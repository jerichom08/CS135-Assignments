/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Homework E2.10

Takes user input of gallons, fuel efficiency, and gas price, then prints out the cost and how far th car can go.
*/

#include <iostream>
using namespace std;

int main() {
    double g, mpg, ppg;
    cout << "Enter number of gallons of gas in the tank: ";
    cin >> g;
    cout << "Enter fuel efficiency in miles per gallon: ";
    cin >> mpg;
    cout << "Enter price of gas per gallon: ";
    cin >> ppg;

    double miles = g * mpg;
    double cost = (100 / mpg) * ppg;

    cout << "Cost per 100 miles is " << cost << endl;
    cout << "Miles that the car can travel is " << miles << endl;
}