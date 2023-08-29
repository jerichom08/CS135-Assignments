/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 12C

Includes a function that takes two vectors and combines them into the first vector.
*/

#include <iostream>
#include <vector>
using namespace std;

void gogeta(vector<int> &goku, vector<int> &vegeta) {
    for (int i = 0; i < vegeta.size(); i++) {
        goku.push_back(vegeta[i]);
    }
    vegeta.clear();
}

int main() {
    vector<int> v1{1,2,3};
    vector<int> v2{4,5};

    gogeta(v1, v2);

    return 0;
}