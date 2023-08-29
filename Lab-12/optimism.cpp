/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 12B

Returns a vector with only positive integers.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> goodVibes(const vector<int> v) {
    vector<int> n;
    for (int i = 0; i < v.size(); i++) {
        if(v[i] > 0) {
            n.push_back(v[i]);
        }
    }
    return n;
}

int main() {
    vector<int> v{1, 2, -1, 3, 4, -1, 6};
    goodVibes(v);
    for (int i = 0; i < v.size(); i++) {
        cout << v[i] << " ";
    }
    return 0;
}