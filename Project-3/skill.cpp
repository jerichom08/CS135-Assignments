//Implementation of Skill class.

#include "skill.hpp"

Skill::Skill() {
    name = "Undefined";
    description = "Undefined";
    uses = -1;
    specialty = -1;
}

Skill::Skill(string name, string description, int specialty, int uses) {
    this->name = name;
    this->description = description;
    this->specialty = specialty;
    this->uses = uses;
}

string Skill::getName() {
    return name;
}

string Skill::getDescription() {
    return description;
}

int Skill::getTotalUses() {
    return uses;
}

int Skill::getSpecialty() {
    return specialty;
}

void Skill::setName(string name) {
    this->name = name;
}

void Skill::setDescription(string description) {
    this->description = description;
}

void Skill::setTotalUses(int uses) {
    this->uses = uses;
}

bool Skill::setSpecialty(int specialty) {
    if(specialty < 0 || specialty > 2) {
        return false;
    }
    this->specialty = specialty;
    return true;
}