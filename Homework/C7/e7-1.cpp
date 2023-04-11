/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Homework E7.1

Declares a function sort2() that that two pointers as input and sorts the values that they point to.
*/

#include <iostream>
using namespace std;

void sort2(double *p, double *q) {
    double temp;
    if(*p >= *q) {
        temp = *p;
        *p = *q;
        *q = temp;
    }
}

int main() {
    double x = 5, y = 8;
    sort2(&x, &y);
}