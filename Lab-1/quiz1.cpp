/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Quiz 1

Asks user input of a number and prints out "I love C++" that amount of times.
*/

#include <iostream>
using namespace std;

int main() {
    int num;
    cout << "Enter a number: ";
    cin >> num;
    for (int i = 0; i < num; i++) {
        cout << "I love C++\n";
    }
    return 0;
}