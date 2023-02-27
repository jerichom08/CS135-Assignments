/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 4D

Takes user input of length and prints a lower left hand triangle.
*/

#include <iostream>
using namespace std;

int main() {
    int len;
    cout << "Input side length: ";
    cin >> len;

    cout << "Shape: " << endl;
    for (int i = 1; i <= len; i++) {
        for (int j = 0; j < i; j++) {
            cout << '*';
        }
        cout << endl;
    }

    return 0;
}