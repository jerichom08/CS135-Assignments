/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Homework E8.1


*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream file("hello.txt");
    file << "Hello, World!";
    file.close();

    string text;
    ifstream readFile("hello.txt");
    getline(readFile, text);
    cout << text;
    readFile.close();

    return 0;
}