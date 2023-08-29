/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 13B

Computes the sum of a given range.
*/

#include <iostream>
#include <cctype>
using namespace std;

void printRange(int left, int right) {
    if(left <= right) { 
        cout << left << ' ';
        printRange(left + 1, right);
    }
}

int sumRange(int left, int right) {
    int sum = 0;
    if(left <= right) {
        sum = left + sumRange(left + 1, right);
    }
    return sum;
}

int sumArrayInRange(int *arr, int left, int right) {
    int sum = 0;
    if(left <= right) {
        sum = arr[left] + sumArrayInRange(arr, left + 1, right);
    }
    return sum;
}

int sumArray(int *arr, int size) {
    int sum = sumArrayInRange(arr, 0, size - 1);
    return sum;
}

bool isAlphanumeric(string s) {
    if(s.empty()) {
        return true;
    }
    int size = s.length();
    char c = s[0];
    if(!isalnum(c)) {
        return false;
    }
    if(isAlphanumeric(s.substr(1, size - 1))) {
        return true;
    }
    return false;
}

bool nestedParens(string s) {
    if(s.empty()) {
        return true;
    }
    
}

int main() {
    cout << nestedParens("((()))") << endl;      // true (1)
    cout << nestedParens("()") << endl;          // true (1)
    cout << nestedParens("") << endl;            // true (1)

    cout << nestedParens("(((") << endl;         // false (0)
    cout << nestedParens("(()") << endl;         // false (0)
    cout << nestedParens(")(") << endl;          // false (0)
    cout << nestedParens("a(b)c") << endl;       // false (0)
}