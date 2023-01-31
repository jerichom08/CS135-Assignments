/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 2D

Prints all Fibonacci nunmbers in an array from F(0) to F(59)
*/

#include <iostream>
using namespace std;

int main() {
    int fib[60];
    fib[0] = 0;
    fib[1] = 1;
    for (int i = 2; i < 60; i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
    }
    for (int i = 0; i < 60; i++) {
        cout << fib[i] << endl;
    }
    return 0;
}