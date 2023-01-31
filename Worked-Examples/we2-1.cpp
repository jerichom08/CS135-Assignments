/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: WE 2.1

Prints out three items on three separate lines
*/

#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x_distance, y_distance, road_speed, terrain_speed, road_length;
    //declare variables for user input

    cout << "Enter x-distance(km) between robot and item: ";
    cin >> x_distance;
    cout << "Enter y-distance(km) between robot and item: ";
    cin >> y_distance;
    cout << "Enter speed(km/h) of robot on the road: ";
    cin >> road_speed;
    cout << "Enter speed(km/h) of robot on terrain: ";
    cin >> terrain_speed;
    cout << "Enter distance(km) traveled by the robot on the road: ";
    cin >> road_length;
    //asks for values for user input variables

    double road_time = road_length / road_speed;
    //road time calculated by dividing the length by speed.

    double terrain_length = sqrt(pow(x_distance, 2) + pow(y_distance - road_length, 2));
    //terrain length found by using Pythagorean theorem

    double terrain_time = terrain_length / terrain_speed;
    //terrain time calculated by dividing the length by speed

    double total_time = road_time + terrain_time;
    //total time calculated by adding both time segments

    cout << "Total time taken for robot to travel to item: " << total_time << " hours";
    return 0;
}