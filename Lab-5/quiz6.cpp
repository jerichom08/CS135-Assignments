/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Quiz 6

Has a function max3() that returns the maximum of 3 integers.
*/

#include <iostream>
using namespace std;

int max3(int a, int b, int c) {
    if(a > b && a > c) {
        return a;
    }
    if(b > a && b > c) {
        return b;
    }
    return c;
}

int main() {
    int a = 3;
    int b = 1;
    int c = 2;
    cout << max3(a, b, c);
    return 0;
}