/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 4F

Takes user input of width and height and prints an upside-down trapezoid.
*/

#include <iostream>
using namespace std;

int main() {
    int w, h;
    cout << "Input width: ";
    cin >> w;
    cout << "Input height: ";
    cin >> h;

    int spaces = 0;
    int stars = w;

    if(h * 2 > w + 1) {
        cout << "Impossible shape!";
    }
    else {
        cout << "Shape: " << endl;
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < spaces; j++) {
                cout << ' ';
            }
            for (int j = 0; j < stars; j++) {
                cout << '*';
            }
            cout << endl;
            stars -= 2;
            spaces += 1;
        }
    }

    return 0;
}