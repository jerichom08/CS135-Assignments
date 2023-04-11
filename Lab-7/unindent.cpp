/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 7A

Reads input from cin and prints each line with leading spaces removed.
*/

#include <iostream>
#include <cctype>
#include <string>
#include <climits>
using namespace std;

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

    while(getline(cin, line)) {
        cout << removeLeadingSpaces(line) << endl;
    }

    return 0;
}