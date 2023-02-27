/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Quiz 4

Opens and reads a file then prints each line.
*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ifstream fin("data.txt");

    string color, code;

    while(fin >> color >> code) {
        cout << color << " " << code << endl;
    }

    fin.close();
}