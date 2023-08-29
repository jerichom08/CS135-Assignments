/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Quiz 13

*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> makeVector(int n) {
    vector<int> a;
    if(n <= 0) {
        return a;
    }
    for (int i = n; i >= 0; i--) {
        a.push_back(i);
    }
    return a;
}

int main() {
    vector<int> nums = makeVector(5);
    for(int i : nums) {
        cout << i << " ";
    }
}