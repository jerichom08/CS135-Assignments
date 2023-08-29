/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Homework E4.8

Takes input of a word and prints each character on a separate line.
*/
#include <iostream>
using namespace std;

int main() {

    string word;
    cout << "Enter word: ";
    cin >> word;

    for (int i = 0; i < word.length(); i++) {
        cout << word.substr(i, 1) << endl;
    }
}