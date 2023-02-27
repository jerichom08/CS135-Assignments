/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Homework E5.14

Includes a void function that swaps the values of two variables if the first is greater than the second.
*/

#include <iostream>
using namespace std;

void sort2(int& a,int& b) {
    int c;
    if(a > b) {
        c = a;
        a = b;
        b = c;
    }
}

int main() {
    int u = 2;
    int v = 3;
    int w = 4;
    int x = 1;
    sort2(u, v);
    sort2(w, x);
    return 0;
}