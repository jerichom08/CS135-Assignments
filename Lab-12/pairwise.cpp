/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 12D

Includes a function that returns a vector of integers that are the pairwise sum of the elements from the two vectors.
*/

#include <iostream>
#include <vector>
using namespace std;

vector<int> sumPairWise(vector<int> &v1, vector<int> &v2) {
    int size;
    if(v1.size() > v2.size()) {
        size = v2.size();
    }
    else {
        size = v1.size();
    }

    vector<int> v3;
    for (int i = 0; i < size; i++) {
        v3.push_back(v1[i] + v2[i]);
    }

    if(v1.size() > v2.size()) {
        for (int i = size; i < v1.size(); i++) {
            v3.push_back(v1[i]);
        }
    }
    else {
        for (int i = size; i < v2.size(); i++) {
            v3.push_back(v2[i]);
        }
    }
    return v3;
}

int main() {
    vector<int> v1{1,2,3};
    vector<int> v2{4,5};

    sumPairWise(v1, v2);

    return 0;
}