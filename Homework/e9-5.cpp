/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Homework E9.5

Include class Rectangle with constructor functions and member functions for perimeter, area, and resizing.
*/

#include <iostream>
using namespace std;

class Rectangle {
public:
    Rectangle(double input_w, double input_h);
    double get_perimeter();
    double get_area();
    void resize(double factor);
private:
    double width;
    double height;
};

Rectangle::Rectangle(double input_w, double input_h) {
    width = input_w;
    height = input_h;
}

double Rectangle::get_perimeter() {
    return (width * 2) + (height * 2);
}

double Rectangle::get_area() {
    return width * height;
}

void Rectangle::resize(double factor) {
    width *= factor;
    height *= factor;
}

int main() {
    Rectangle r1(5, 5);
    cout << r1.get_perimeter() << " " << r1.get_area() << endl;
    r1.resize(2);
    cout << r1.get_perimeter() << " " << r1.get_area() << endl;
    return 0;
}