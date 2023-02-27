/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 4B

Takes user input of width and height and prints a checkboard with those dimensions.
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
            if(i % 2 == 0) {
                if(j % 2 == 0) {
                    cout << '*';
                }
                else {
                    cout << ' ';
                }
            }
            else {
                if(j % 2 == 0) {
                    cout << ' ';
                }
                else {
                    cout << '*';
                }
            }
        }
        cout << endl;
    }

    return 0;
}