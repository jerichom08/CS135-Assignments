/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 11C

Adds a private variable that includes friendship (following) relation between users.
*/

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

class Profile {
private:
    string username;
    string displayname;
public:
    Profile(string usrn, string dspn);
    Profile();
    string getUsername();
    string getFullName();
    void setDisplayName(string dspn);
};

Profile::Profile(string usrn, string dspn) {
    username = usrn;
    displayname = dspn;
}

Profile::Profile() {
    username = "";
    displayname = "";
}

string Profile::getUsername() {
    return username;
}

string Profile::getFullName() {
    return displayname + " (@" + username + ")";
}

void Profile::setDisplayName(string dspn) {
    displayname = dspn;
}

class Network {
private:
    static const int MAX_USERS = 20;
    int numUsers;
    Profile profiles[MAX_USERS];
    bool following[MAX_USERS][MAX_USERS];
    int findID (string usrn);
public:
    Network();
    bool addUser(string usrn, string dspn);
    bool follow(string usrn1, string usrn2);
    void printDot();
};

int Network::findID(string usrn) {
    for (int i = 0; i < MAX_USERS; i++) {
        if(profiles[i].getUsername() == usrn) {
            return i;
        }
    }
    return -1;
}

Network::Network() {
    numUsers = 0;
    for (int i = 0; i < MAX_USERS; i++) {
        for (int j = 0; j < MAX_USERS; j++) {
            following[i][j] = false;
        }
    }
}

bool Network::addUser(string usrn, string dspn) {
    for (int i = 0;i < usrn.length(); i++) {
        if(!isalnum(usrn.at(i))) {
            return false;
        }
    }
    if (findID(usrn) != -1) {
        return false;
    }
    if(numUsers == MAX_USERS) {
        return false;
    }
    profiles[numUsers] = {usrn, dspn};
    numUsers++;
    return true;
}

bool Network::follow(string usrn1, string usrn2) {
    int id1 = findID(usrn1);
    int id2 = findID(usrn2);
    if(id1 == -1 || id2 == -1) {
        return false;
    }
    following[id1][id2] = true;
    return true;
}

void Network::printDot() {
    cout << "digraph {" << endl;
    for (int i = 0; i < numUsers; i++) {
        cout << "  \"@" + profiles[i].getUsername() + "\"" << endl;
    }
    cout << endl;
    for (int i = 0; i < numUsers; i++) {
        for (int j = 0; j < numUsers; j++) {
            if(following[i][j]) {
                cout << "  \"@" + profiles[i].getUsername() + "\" -> \"@" + profiles[j].getUsername() + "\"" << endl;
            }
        }
    }
    cout << "}" << endl;
}

int main() {
    Network nw;
    // add three users
    nw.addUser("mario", "Mario");
    nw.addUser("luigi", "Luigi");
    nw.addUser("yoshi", "Yoshi");

    // make them follow each other
    nw.follow("mario", "luigi");
    nw.follow("mario", "yoshi");
    nw.follow("luigi", "mario");
    nw.follow("luigi", "yoshi");
    nw.follow("yoshi", "mario");
    nw.follow("yoshi", "luigi");

    // add a user who does not follow others
    nw.addUser("wario", "Wario");
    
    // add clone users who follow @mario
    for(int i = 2; i < 6; i++) {
        string usrn = "mario" + to_string(i);
        string dspn = "Mario " + to_string(i);
        nw.addUser(usrn, dspn);
        nw.follow(usrn, "mario");
    }
    // additionally, make @mario2 follow @luigi
    nw.follow("mario2", "luigi");

    nw.printDot();
}