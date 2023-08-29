//Implementation of Profemon class.

#include "skill.hpp"
#include "profemon.hpp"

Profemon::Profemon() {
    name = "Undefined";
}

Profemon::Profemon(string name, double max_health, Specialty specialty) {
    this->name = name;
    maxHP = max_health;
    this->specialty = specialty;
    expRequired = 50;
    expCurrent = 0;
    level = 0;
}

string Profemon::getName() {
    return name;
}

Specialty Profemon::getSpecialty() {
    return specialty;
}

int Profemon::getLevel() {
    return level;
}

double Profemon::getMaxHealth() {
    return maxHP;
}

void Profemon::setName(string name) {
    this->name = name;
}

void Profemon::levelUp(int exp) {
    expCurrent += exp;
    if(specialty == ML) {
        while(expCurrent >= expRequired) {
            level += 1;
            expCurrent -= expRequired;
            expRequired += 10;
        }
    }
    else if(specialty == SOFTWARE) {
        while(expCurrent >= expRequired) {
            level += 1;
            expCurrent -= expRequired;
            expRequired += 15;
        }
    }
    else if(specialty == HARDWARE) {
        while(expCurrent >= expRequired) {
            level += 1;
            expCurrent -= expRequired;
            expRequired += 20;
        }
    }
}

bool Profemon::learnSkill(int slot, Skill skill) {
    if(slot < 0 || slot > 2) {
        return false;
    }
    int profemonSpecialty;
    switch(specialty) {
        case ML       : profemonSpecialty = 0; break;
        case SOFTWARE : profemonSpecialty = 1; break;
        case HARDWARE : profemonSpecialty = 2; break;
    }
    if(skill.getSpecialty() != profemonSpecialty) {
        return false;
    }
    skills[slot] = skill;
    return true;
}

void Profemon::printProfemon(bool print_skills) {
    string s;
    switch (specialty) {
        case ML       : s = "ML"; break;
        case SOFTWARE : s = "SOFTWARE"; break;
        case HARDWARE : s = "HARDWARE"; break;
    }
    cout << name << " [" << s << "] | lvl " << level << " | exp " << expCurrent << "/" << expRequired << " | hp " << maxHP << endl;
    if(print_skills) {
        for (int i = 0; i < 3; i++) {
            if(skills[i].getName() != "Undefined") {
                cout << "    " << skills[i].getName() << " [" << skills[i].getTotalUses() << "] : " << skills[i].getDescription() << endl;
            }
        }
    }

}