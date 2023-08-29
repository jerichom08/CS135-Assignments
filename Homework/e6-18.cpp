/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Homework E6.18

Includes a function that appends one verctor after another.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> append(vector<int> a, vector<int> b) {
    for (int i = 0;i < b.size(); i++) {
        a.push_back(b[i]);
    }
    return a;
}

int main() {
    vector<int> a = {1, 4, 9, 16};
    vector<int> b = {9, 7, 4, 9, 11};
    vector<int> c = append(a, b);
    for (int i = 0; i < c.size(); i++) {
        cout << c[i] << ' ';
    }
    return 0;
}