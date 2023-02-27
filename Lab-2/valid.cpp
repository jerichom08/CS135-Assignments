/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 2A

Asks for user input of an integer in the range 0 < n < 100. 
If the number is not in range, the program keeps asking the user to re-enter until a number is in range. 
After a valid input is taken, prints the number squared.
*/

#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Please enter an integer: ";
    cin >> num;
    while(num <= 0 || num >= 100) {
        cout << "Please re-enter: ";
        cin >> num;
    }
    num *= num;
    cout << "Number squared is " << num;
    return 0;
}