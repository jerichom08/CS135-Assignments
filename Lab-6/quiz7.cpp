/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Quiz 7

Includes a function that removes the letter 'e' from a string.
*/

#include <iostream>
using namespace std;

void remove_e(string &sentence) {
    string n;
    for (int i = 0; i < sentence.length(); i++) {
        if(sentence.at(i) != 'e') {
            n += sentence.at(i);
        }
    }
    sentence = n;
}

int main() {
    string s = "elephant";
    remove_e(s);
    cout << s << endl;
}