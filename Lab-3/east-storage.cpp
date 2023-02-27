/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 3A

Takes user input of a date and prints the East basin storage on that day.
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
    double eastSt;

    string date, day;
    cout << "Enter date: ";
    cin >> day;

    while(fin >> date >> eastSt) {
        fin.ignore(INT_MAX, '\n');

        if(date == day) {
            cout << "East basin storage: " << eastSt << " billion gallons" << endl;
        }
    }
    fin.close();
    return 0;
}