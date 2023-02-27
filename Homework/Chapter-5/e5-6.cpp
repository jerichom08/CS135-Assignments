/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Homework E5.6

Takes input of a word and prints each character on a separate line.
*/

#include <iostream>
#include <string>
using namespace std;

string middle(string str) {
    string c;
    int len = str.length();
    if(str.length() % 2 != 0) {
        c = str.substr(len / 2, 1);
    }
    else {
        c = str.substr((len / 2) - 1, 2);
    }
    return c;
}

int main() {
    string s;
    cout << "Enter string: ";
    cin >> s;
    cout << middle(s);
    return 0;
}