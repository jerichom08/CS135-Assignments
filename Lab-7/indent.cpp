/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 7B

Reads input from cin and prints each line with correct indentation.
*/

#include <iostream>
#include <cctype>
#include <string>
using namespace std;

int countChar(string line, char c) {
    int n = 0;
    for (int i = 0; i < line.length(); i++) {
        if(line.at(i) == c) {
            n++;
        }
    }
    return n;
}

string removeLeadingSpaces(string line) {
    string s;
    for (int i = 0; i < line.length(); i++) {
        if(!isspace(line.at(i))) {
            s = line.substr(i);
            break;
        }
    }
    return s;
}

int main() {
    string line;
    int tab = 0;

    while(getline(cin, line)) {
        line = removeLeadingSpaces(line);
        for (int i = 0; i < tab - (line[0] == '}'); i++) {
            cout << "\t";
        }
        tab += countChar(line, '{');
        tab -= countChar(line, '}');
        cout << line << endl;
    }

    return 0;
}