/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Homework E7.1

Defines a structure Point and a function distance() that calculates the distance between two points.
*/

#include <iostream>
#include <cmath>
using namespace std;

class Point {
    public:
        double x, y;
};

double distance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

int main() {
    Point a = {5, 5};
    Point b = {10, 10};
    cout << distance(a, b) << endl;
    return 0;
}