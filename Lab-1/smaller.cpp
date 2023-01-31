/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab1A

Takes user input of two integers and prints out the smaller of the two.
*/

#include <iostream>
using namespace std;

int main() {
    int num1, num2, smaller;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    if(num1 > num2) {
        smaller = num2;
    }
    else {
        smaller = num1;
    }
    cout << "The smaller of the two is " << smaller;
    return 0;
}