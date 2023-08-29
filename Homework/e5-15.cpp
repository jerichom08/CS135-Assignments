/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Homework E5.15

Sorts 3 numbers in ascending order.
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

void sort3(int& a, int& b, int& c) {
    sort2(b, c);
    sort2(a, b);
    sort2(b, c);
}

int main() {
    int v = 3;
    int w = 4;
    int x = 1;
    sort3(v, w, x);
    return 0;
}