/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Quiz 5

Prints a rectangle.
*/

#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 6; i++) {
        for (int j = 0; j < 5; j++) {
            cout << '+';
        }
        cout << endl;
    }

    return 0;
}