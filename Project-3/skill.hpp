//Interface for Skill class.

#ifndef SKILL_HPP
#define SKILL_HPP
#include <string>
#include <iostream>
using namespace std;

class Skill {
private:
    string name;
    string description;
    int uses;
    int specialty;
public:
    Skill();
    Skill(string name, string description, int specialty, int uses);
    string getName();
    string getDescription();
    int getTotalUses();
    int getSpecialty();
    void setName(string name);
    void setDescription(string description);
    void setTotalUses(int uses);
    bool setSpecialty(int specialty);
};

#endif