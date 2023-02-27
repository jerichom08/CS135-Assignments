/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 4A

Takes user input of width and height and prints a solid box with those dimensions.
*/

#include <iostream>
using namespace std;

int main() {
    int width, height;
    cout << "Input width: ";
    cin >> width;
    cout << "Input height: ";
    cin >> height;

    cout << "Shape: " << endl;
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            cout << '*';
        }
        cout << endl;
    }

    return 0;
}