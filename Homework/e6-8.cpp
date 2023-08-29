/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Homework E6.8

Checks whether two arrats have the same elements in the same order.
*/

#include <iostream>
using namespace std;

bool equals(int a[], int a_size, int b[], int b_size) {
    if(a_size != b_size) {
        return false;
    }
    for (int i = 0; i < a_size; i++) {
        if(a[i] != b[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    int a[4] = {1, 2, 3, 4};
    int b[4] = {1, 2, 3, 4};
    int a_len = sizeof(a) / sizeof(int);
    int b_len = sizeof(b) / sizeof(int);
    cout << equals(a, a_len, b, b_len) << endl;
    return 0;
}