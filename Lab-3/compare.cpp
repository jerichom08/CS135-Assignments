/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 3C

Takes user input of a start and end date and prints which basin had a higher elevation on each day.
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

    string day1, day2;
    cout << "Enter starting date: ";
    cin >> day1;
    cout << "Enter ending date: ";
    cin >> day2;

    string date;
    double eastEl;
    double westEl;
    double eastSt;
    double westSt;

    while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {
        fin.ignore(INT_MAX, '\n');

        if(date >= day1 && date <= day2) {
            if(westEl > eastEl) {
                cout << date << " West" << endl;
            }
            else if(eastEl > westEl) {
                cout << date << " East" << endl;
            }
            else {
                cout << date << "Equal" << endl;
            }
        }
    }

    fin.close();
    return 0;
}