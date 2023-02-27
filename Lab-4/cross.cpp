/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 4B

Takes user input of a size and prints a diagonal cross with that dimension.
*/

#include <iostream>
using namespace std;

int main() {
    int size;
    cout << "Input size: ";
    cin >> size;

    cout << "Shape: " << endl;
    for (int i = 1; i <= size/2; i++) {
        for (int j = 0; j < i; j++) {
            cout << ' ';
        }
        cout << '*';
        for (int j = size - 2 * i; j > 0; j--) {
            cout << ' ';
        }
        cout << '*' << endl;
    }
    if(size % 2 == 1) {
        for (int i = 0; i <= size / 2; i++) {
            cout << ' ';
        }
        cout << '*' << endl;
    }
    for (int i = size / 2; i >= 1; i--) {
        for (int j = 0; j < i; j++) {
            cout << ' ';
        }
        cout << '*';
        for (int j = 0; j < size - 2 * i; j++) {
            cout << ' ';
        }
        cout << '*' << endl;
    }

    return 0;
}