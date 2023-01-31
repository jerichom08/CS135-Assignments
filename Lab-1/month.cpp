/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab1D

Takes user input of the year and month and prints the number of days in that month.
*/

#include <iostream>
using namespace std;

int main() {

    int year, month, feb;
    int bump = 31;
    int gap = 30;
    //Declare and initialize variables.

    cout << "Enter year: ";
    cin >> year;
    cout << "Enter month: ";
    cin >> month;
    //Take input of year and month.

    if(year % 4 != 0) {
        feb = 28;
    }
    else if(year % 100 != 0) {
        feb = 29;
    }
    else if(year % 400 != 0) {
        feb = 28;
    }
    else {
        feb = 29;
    }
    //Determines whether the year is a leap year and adjusts the number of days in February.
    
    if(month == 2) {
        cout << feb << " days";
    }
    else if((month < 8 && month % 2 == 1) || (month >= 8 && month % 2 == 0)) {
        cout << bump << " days";
    }
    else {
        cout << gap << " days";
    }
    //Prints out number of days based on month.
    
    return 0;
}