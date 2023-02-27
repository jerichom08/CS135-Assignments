/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 2C

Creates an array that allows the user to edit its contents.
*/

#include <iostream>
using namespace std;

int main() {
    int myData[10];
    int i = 0;
    int v = 0;
    for(int i = 0; i < 10; i++) {
        myData[i] = 1;
    }
    do {
        for (int i = 0; i < 10; i++) {
            cout << myData[i] << " ";
        }
        cout << endl;
        cout << "Input index: ";
        cin >> i;
        cout << "Input value: ";
        cin >> v;
        if(i >= 0 && i < 10) {
            myData[i] = v;
        }
    } while (i >= 0 && i < 10);
    cout << "Index out of range. Exit.";
    return 0;
}