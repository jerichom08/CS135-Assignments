/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 3B

Finds the minimum and maximum storage in East basin in 2018.
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
    string date;
    double eastSt;
    double max = INT_MIN;
    double min = INT_MAX;

    while(fin >> date >> eastSt) {
        fin.ignore(INT_MAX, '\n');

        if(eastSt > max) {
            max = eastSt;
        }
        if(eastSt < min) {
            min = eastSt;
        }
    }

    fin.close();

    cout << "minimum storage in East basin: " << min << " billion gallons\n";
    cout << "maximum storage in East basin: " << max << " billion gallons\n";

    return 0;
}