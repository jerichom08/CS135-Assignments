/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Homework E3.1

Takes user input of an integer and determines whether it is negative, zero, or positive.
*/

#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter an integer: ";
    cin >> num;
    if(num == 0) {
        cout << "The integer is zero." << endl;
    }
    else if(num < 0) {
        cout << "The integer is negative." << endl;
    }
    else {
        cout << "The integer is positive.";
    }
    return 0;
}