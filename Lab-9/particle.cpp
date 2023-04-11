/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 9F

Creates a new class Particle that stores position and volocity of a particle, and includes multiple functions to alter the components of a particle.
*/

#include <iostream>
#include <cmath>
using namespace std;

class Particle {
    public:
        double x, y, z, vx, vy, vz;
};

class Coord3D {
    public:
        double x, y, z;
};

// dynamically allocate memory for a particle and initialize it
Particle* createParticle(double x, double y, double z, double vx, double vy, double vz) {
    Particle *p;
    p = new Particle;
    *p = {x, y, z, vx, vy, vz};
    return p;
}

Coord3D* createCoord3D(double x, double y, double z) {
    Coord3D *p;
    p = new Coord3D;
    *p = {x, y, z};
    return p;
}

// set its velocity to (vx, vy, vz)
void setVelocity(Particle *p, double vx, double vy, double vz) {
    p->vx = vx;
    p->vy = vy;
    p->vz = vz;
}
// get its current position
Coord3D getPosition(Particle *p) {
    return *createCoord3D(p->x, p->y, p->z);
}

// update particle's position after elapsed time dt
void move(Particle *p, double dt) {
    p->x = p->x + p->vx * dt;
    p->y = p->y + p->vy * dt;
    p->z = p->z + p->vz * dt;
}

// delete all memory allocated for the particle passed by pointer
void deleteParticle(Particle *p) {
    delete p;
}

int main() {
    // make new particle
    Particle *p = createParticle(1.0, 1.5, 2.0, 0.1, 0.2, 0.3);
    double time = 0.0;
    double dt = 0.1;
    while(time < 3.0) {
        // update its velocity
        setVelocity(p, 10.0 * time, 0.3, 0.1);

        // move the particle
        move(p, dt);
        time += dt;

        // reporting its coordinates
        cout << "Time: " << time << " \t";
        cout << "Position: "
             << getPosition(p).x << ", "
             << getPosition(p).y << ", "
             << getPosition(p).z << endl;
    }
    // remove the particle, deallocating its memory
    deleteParticle(p);
}