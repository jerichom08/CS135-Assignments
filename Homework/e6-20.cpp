/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Homework E6.20

Merges two sorted vectors that produces a new sorted vector.
*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> merge_sorted(vector<int> a, vector<int> b) {
    vector<int> c;
    for (int i = 0; i < a.size(); i++) {
        c.push_back(a[i]);
    }
    for (int i = 0; i < b.size(); i++) {
        c.push_back(b[i]);
    }
    sort(c.begin(), c.end());
    return c;
}

int main() {
    vector<int> a = {1, 4, 9, 16, 16, 18};
    vector<int> b = {4, 7, 9,  9, 11, 13, 17};
    vector<int> c = merge_sorted(a, b);
    for (int i = 0; i < c.size(); i++) {
        cout << c[i] << ' ';
    }
    return 0;
}