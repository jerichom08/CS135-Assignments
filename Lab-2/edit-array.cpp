/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 2C

Prints out three items on three separate lines
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
    while(i >=0 && i < 10) {
        for(int i = 0; i < 10;i++) {
            cout << myData[i] << " ";
        }
        cout << "Input index: ";
        cin >> i;
        cout << "Input value: ";
        cin >> v;
        myData[i] = v;
    }
    cout << "Index out of range. Exit.";
    return 0;
}