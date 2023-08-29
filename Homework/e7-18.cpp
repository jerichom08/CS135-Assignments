/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Homework E7.18

Defines a structure Triangle that has three Point members.
Includes a function that computes the perimeter of a Triangle.
*/

#include <iostream>
#include <cmath>
using namespace std;

class Point {
    public:
        double x, y;
};

class Triangle {
    public:
        Point a, b, c;
};

double distance(Point a, Point b) {
    return sqrt(pow(b.x - a.x, 2) + pow(b.y - a.y, 2));
}

double perimeter(Triangle t) {
    return distance(t.a, t.b) + distance(t.b, t.c) + distance(t.c, t.a);
}

int main() {
    Triangle t = {(0, 0), (0, 5), (5, 5)};
    cout << perimeter(t);
    return 0;
}