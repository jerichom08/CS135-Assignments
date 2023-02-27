/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 4G

Takes user input of width and height and prints a checkerboard with 3 by 3 squares.
*/

#include <iostream>
using namespace std;

int main() {
    int w, h;
    cout << "Input width: ";
    cin >> w;
    cout << "Input height: ";
    cin >> h;

    cout << "Shape: " << endl;
    bool space = false;
    for (int i = 0; i < h; i++) {
        if((i/3) % 2 == 0) {
            for (int j = 0; j < w; j++) {
                if((j / 3) % 2 == 1) {
                    space = true;
                }
                else if((j / 3) % 2 == 0) {
                    space = false;
                }
                if(space) {
                    cout << ' ';
                }
                else {
                    cout << '*';
                }
            }
        }
        else {
            for (int j = 0; j < w; j++) {
                if((j / 3) % 2 == 1) {
                    space = false;
                }
                else if((j / 3) % 2 == 0) {
                    space = true;
                }
                if(space) {
                    cout << ' ';
                }
                else {
                    cout << '*';
                }
            }
        }
        cout << endl;
    }
}