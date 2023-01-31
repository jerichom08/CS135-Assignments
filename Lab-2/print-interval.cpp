/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 2B

Takes user input of two integers and prints out all integers in the range.
*/

#include <iostream>
using namespace std;

int main() {
    int lower, upper;
    cout << "Please enter L: ";
    cin >> lower;
    cout << "Please enter U: ";
    cin >> upper;
    for (int i = lower; i < upper; i++) {
        cout << i << " ";
    }
}