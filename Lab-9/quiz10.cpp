/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Quiz 10

*/

#include <iostream>
using namespace std;

class Date {
    public:
    int month, day, year;
};

string formatDate(Date *d) {
    string m;
    switch(d->month) {
        case 1  :m = "Jan"; break;
        case 2  :m = "Feb"; break;
        case 3  :m = "Mar"; break;
        case 4  :m = "Apr"; break;
        case 5  :m = "May"; break;
        case 6  :m = "Jun"; break;
        case 7  :m = "Jul"; break;
        case 8  :m = "Aug"; break;
        case 9  :m = "Sep"; break;
        case 10 :m = "Oct"; break;
        case 11 :m = "Nov"; break;
        case 12 :m = "Dec"; break;
    }
    string date = m + " " + to_string(d->day) + ", " + to_string(d->year);
    return date;
}

int main() {
    Date midterm1 = Date{10, 17, 2022};
    cout << formatDate(&midterm1) << endl;

    Date christmas = Date{12, 25, 2022};
    cout << formatDate(&christmas) << endl;
}