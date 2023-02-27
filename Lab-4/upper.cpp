/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 4E

Takes user input of length and prints an upper right hand triangle.
*/

#include <iostream> 
using namespace std;

int main() {
    int len;
    cout << "Input side length: ";
    cin >> len;

    cout << "Shape: " << endl;
    for (int i = 0; i < len; i++) {
        for (int j = 0; j < i; j++) {
            cout << ' ';
        }
        for (int j = len; j > i; j--) {
            cout << '*';
        }
        cout << endl;
    }
}