//Interface for Profemon class.

#ifndef PROFEMON_HPP
#define PROFEMON_HPP
#include "skill.hpp"
enum Specialty {ML, SOFTWARE, HARDWARE};

class Profemon {
private:
    string name;
    int level;
    int expRequired;
    int expCurrent;
    double maxHP;
    Specialty specialty;
    Skill skills[3];
public:
    Profemon();
    Profemon(string name, double max_health, Specialty specialty);
    string getName();
    Specialty getSpecialty();
    int getLevel();
    double getMaxHealth();
    void setName(string name);
    void levelUp(int exp);
    bool learnSkill(int slot, Skill skill);
    void printProfemon(bool print_skills);
};

#endif