/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab1B

Takes user input of three integers and prints out the smallest of the three.
*/

#include <iostream>
using namespace std;

int main() {
    int num1, num2, num3, smaller, smallest;
    cout << "Enter the first number: ";
    cin >> num1;
    cout << "Enter the second number: ";
    cin >> num2;
    cout << "Enter the third number: ";
    cin >> num3;
    if(num1 < num2) {
        smaller = num1;
    }
    else {
        smaller = num2;
    }
    if(smaller < num3) {
        smallest = smaller;
    }
    else {
        smallest = num3;
    }
    cout << "The smaller of the three is " << smallest;
}