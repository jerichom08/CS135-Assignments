//Implementation of Trainer class.

#include "trainer.hpp"

Trainer::Trainer() {
    currentProfemon = nullptr;
}

Trainer::Trainer(vector<Profemon> profemons) {
    int i = 0;
    for (int j = 0; j < 3; j++) {
        if(currentTeam[j].getName() == "Undefined") {
            currentTeam[j] = profemons[i];
            i++;
        }
    }
    for (int k = i; k < profemons.size(); k++) {
        profedex.push_back(profemons[k]);
    }
    currentProfemon = &currentTeam[0];
}

bool Trainer::contains(string name) {
    for (int i = 0; i < 3; i++) {
        if(currentTeam[i].getName() == name) {
            return true;
        }
    }
    for (int i = 0; i < profedex.size(); i++) {
        if(profedex[i].getName() == name) {
            return true;
        }
    }
    return false;
}

bool Trainer::addProfemon(Profemon profemon) {
    if(contains(profemon.getName())) {
        return false;
    }
    for (int i = 0; i < 3; i++) {
        if(currentTeam[i].getName() == "Undefined") {
            currentTeam[i] = profemon;
            return true;
        }
    }
    profedex.push_back(profemon);
    return true;
}

bool Trainer::removeProfemon(string name) {
    if(!contains(name)) {
        return false;
    }
    for (int i = 0; i < 3; i++) {
        if(currentTeam[i].getName() == name) {
            Profemon p;
            currentTeam[i] = p;
            return true;
        }
    }
    for (int i = 0; i < profedex.size(); i++) {
        if(profedex[i].getName() == name) {
            profedex.erase(profedex.begin() + i);
            return true;
        }
    }
    return true;
}

void Trainer::setTeamMember(int slot, string name) {
    Profemon p;
    int index;
    for (int i = 0; i < profedex.size(); i++) {
        if(profedex[i].getName() == name) {
            p = profedex[i];
            index = i;
            break;
        }
    }
    if(currentTeam[slot].getName() == "Undefined") {
        currentTeam[slot] = p;
        profedex.erase(profedex.begin() + index);
    }
    else {
        profedex[index] = currentTeam[slot];
        currentTeam[slot] = p;
    }
}

bool Trainer::chooseProfemon(int slot) {
    if(currentTeam[slot].getName() != "Undefined") {
        currentProfemon = &currentTeam[slot];   
        return true;
    }
    return false;
}

Profemon Trainer::getCurrent() {
    return *currentProfemon;
}

void Trainer::printProfedex() {
    for (int i = 0; i < profedex.size(); i++) {
        profedex[i].printProfemon(false);
        cout << endl;
    }
}

void Trainer::printTeam() {
    for (int i = 0; i < 3; i++) {
        if(currentTeam[i].getName() != "Undefined") {
            currentTeam[i].printProfemon(true);
            cout << endl;
        }
        cout << "";
    }
}