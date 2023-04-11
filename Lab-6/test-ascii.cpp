/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 6A

Takes user input of text and prints out the ASCII codes of each letter.
*/

#include <iostream>
using namespace std;

int main() {
    string text;
    cout << "Input: ";
    getline(cin, text);
    cout << endl;

    for (int i = 0; i < text.length(); i++) {
        char c = text[i];
        cout << text[i] << ' ' << (int)c << endl;
    }

    return 0;
}