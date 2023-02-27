/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 3D

Takes user input of two dates and prints the West basin elevation of alldays in the interval in reverse order.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
using namespace std;

int main() {
    ifstream fin("Current_Reservoir_Levels.tsv");
    if(fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }
    string junk;
    getline(fin, junk);
    double eastSt, eastEl, westSt, westEl;

    string date, day1, day2;
    cout << "Enter earlier date: ";
    cin >> day1;
    cout << "Enter later date: ";
    cin >> day2;

    string dateData[365];
    double westElData[365];
    int start, end;
    int i = 0;

    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
        fin.ignore(INT_MAX, '\n');

        dateData[i] = date;
        westElData[i] = westEl;
        if(date == day1) {
            end = i;
        }
        if(date == day2) {
            start = i;
        }
        i++;
    }

    for (int j = start; j >= end; j--) {
        cout << dateData[j] << " " << westElData[j] << " ft" << endl;
    }

    fin.close();
    return 0;
}