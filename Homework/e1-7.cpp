/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Homework E1.7

Prints out three items on three separate lines
*/

#include <iostream>
using namespace std;

int main() {
    string name1, name2, name3;
    cout << "Enter name 1: ";
    cin >> name1;
    cout << "Enter name 2: ";
    cin >> name2;
    cout << "Enter name 3: ";
    cin >> name3;
    cout << name1 << "\n"
         << name2 << "\n"
         << name3 << "\n";
    return 0;
}