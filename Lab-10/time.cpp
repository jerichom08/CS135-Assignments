/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 10

A) Includes the class Time and two functions that return minutes since midnight and minutes between two times.
B) Includes a function to add minutes to a time.
C) Includes the classes Movie and TimeSlot and funcitons to print them;
*/

#include <iostream>
using namespace std;

class Time {
    public:
    int h;
    int m;
};

void printTime(Time time) {
    cout << time.h << ":" << time.m;
}

int minutesSinceMidnight(Time time) {
    int total = time.m + (time.h * 60);
    return total;
}

int minutesUntil(Time earlier, Time later) {
    int diff = minutesSinceMidnight(later) - minutesSinceMidnight(earlier);
    return diff;
}

Time addMinutes(Time time0, int min) {
    time0.m += min;
    while(time0.m >= 60) {
        time0.h += 1;
        time0.m -= 60;
    }
    return time0;
}

enum Genre {ACTION, COMEDY, DRAMA, ROMANCE, THRILLER};

class Movie {
    public:
    string title;
    Genre genre;
    int duration;
};

void printMovie(Movie mv){
    string g;
    switch (mv.genre) {
        case ACTION   : g = "ACTION"; break;
        case COMEDY   : g = "COMEDY"; break;
        case DRAMA    : g = "DRAMA";  break;
        case ROMANCE  : g = "ROMANCE"; break;
        case THRILLER : g = "THRILLER"; break;
    }
    cout << mv.title << " " << g << " (" << mv.duration << " min)";
}

class TimeSlot {
    public:
    Movie movie;
    Time startTime;
};

void printTimeSlot(TimeSlot ts) {
    Time endTime = addMinutes(ts.startTime, ts.movie.duration);
    printMovie(ts.movie);
    cout << " [starts at ";
    printTime(ts.startTime);
    cout << ", ends by ";
    printTime(endTime);
    cout << ']' << endl;
}

TimeSlot scheduleAfter(TimeSlot ts, Movie nextMovie) {
    Time startTime = addMinutes(ts.startTime, ts.movie.duration);
    return {nextMovie, startTime};
}

bool timeOverlap(TimeSlot ts1, TimeSlot ts2) {
    int interval1 = minutesUntil(ts1.startTime, ts2.startTime);
    int interval2 = minutesUntil(ts2.startTime, ts1.startTime);
    if(interval2 > interval1) {
        if(interval2 < ts2.movie.duration) {
            return true;
        }
        return false;
    }
    if(interval1 < ts1.movie.duration) {
        return true;
    }
    return false;
}

int main() {
    Time time = {9, 15};
    Movie movie = {"Back to the Future", COMEDY, 116};
    TimeSlot ts = {movie, time};
    printTimeSlot(ts);

    Movie nextMovie = {"Black Panther", ACTION, 134};
    TimeSlot newTs = {scheduleAfter(ts, nextMovie)};
    printTimeSlot(newTs);
}