/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 12A

Includes a function that creates a vector with n integers from 0 to n - 1.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> makeVector(int n) {
    vector<int> v;
    for (int i = 0; i < n; i++) {
        v.push_back(i);
    }
    return v;
}

int main() {
    makeVector(5);
    return 0;
}