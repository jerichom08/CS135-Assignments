/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 9

A) Defines a function length() that takes the coordinates of a point and computes the distance from the origin.
B) Defines a function fartherFromOrigin() that takes two points and returns the point that is farther from the origin.
C) Defines a function move() that gets the position and velocity of an object and computes its new position after the given time.
E) Includes functions that create, delete, and coordinate objects dynamically.
*/

#include <iostream>
#include <cmath>
using namespace std;

class Coord3D {
    public:
        double x;
        double y;
        double z;
};

double length(Coord3D *p) {
    return sqrt(pow(p->x, 2) + pow(p->y, 2) + pow(p->z, 2));
}

Coord3D *fartherFromOrigin(Coord3D *p1, Coord3D *p2) {
    double len1 = length(p1);
    double len2 = length(p2);
    if(len1 > len2) {
        return p1;
    }
    return p2;
}

void move(Coord3D *ppos, Coord3D *pvel, double dt) {
    ppos->x = ppos->x + pvel->x * dt;
    ppos->y = ppos->y + pvel->y * dt;
    ppos->z = ppos->z + pvel->z * dt;
}

Coord3D* createCoord3D(double x, double y, double z) {
    Coord3D *p;
    p = new Coord3D;
    *p = {x, y, z};
    return p;
}

void deleteCoord3D(Coord3D *p) {
    delete p;
}

int main() {
    double x, y, z;
    cout << "Enter position: ";
    cin >> x >> y >> z;
    Coord3D *ppos = createCoord3D(x,y,z);
    
    cout << "Enter velocity: ";
    cin >> x >> y >> z;
    Coord3D *pvel = createCoord3D(x,y,z);

    move(ppos, pvel, 10.0);

    cout << "Coordinates after 10 seconds: " 
         << (*ppos).x << " " << (*ppos).y << " " << (*ppos).z << endl;

    deleteCoord3D(ppos); // release memory
    deleteCoord3D(pvel);
}