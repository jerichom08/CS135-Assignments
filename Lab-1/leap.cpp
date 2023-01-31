/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab1C

Takes user input of a year number and prints either "Leap year" or "Common year".
*/

#include <iostream>
using namespace std;

int main() {
    int year;
    string type;
    cout << "Enter year: ";
    cin >> year;
    if(year % 4 != 0) {
        type = "Common year";
    }
    else if(year % 100 != 0) {
        type = "Leap year";
    }
    else if(year % 400 != 0) {
        type = "Common year";
    }
    else {
        type = "Leap year";
    }
    cout << type;
}