/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Homework E3.5

Takes input of three numbers and determines whether they are increasing, decreasing, or neither.
*/

#include <iostream>
using namespace std;

int main() {

    int x, y, z;
    cout << "Enter first number: ";
    cin >> x;
    cout << "Enter second number: ";
    cin >> y;
    cout << "Enter third number: ";
    cin >> z;

    if(y > x && z > y) {
        cout << "increasing";
    }
    else if(y < x && z < y) {
        cout << "decreasing";
    }
    else {
        cout << "neither";
    }
    
}