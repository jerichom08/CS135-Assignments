/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Project 2C

Uses a class Song instead of dynamic arrays to store songs.
*/

#include <iostream>
#include <fstream>
#include <climits>
#include <cstdlib>
using namespace std;

class Song {
    public:
    string name;
    string artist;
    int duration;
    string genre;
};

int g_capacity = 2;
int g_size = 0;
Song *g_songs = new Song[g_capacity];

void allocateNew() {
    g_capacity *= 2;
    Song *new_songs = new Song[g_capacity];

    for (int i = 0; i < g_size; i++) {
        new_songs[i] = g_songs[i];
    }

    delete[] g_songs;
    g_songs = new_songs;
}

void readSongs(string filename) {
    ifstream fin(filename);
    if(fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }

    string line;
    int i = 0;
    while(getline(fin, line))   {

        if(i == g_capacity) {
            allocateNew();
        }

        string song = line.substr(0, line.find(':'));
        line.erase(0, line.find(':') + 1);
        string artist = line.substr(0, line.find('-'));
        line.erase(0, line.find('-') + 1);
        string genre = line.substr(0, line.find('-'));
        line.erase(0, line.find('-') + 1);
        int duration = stoi(line.substr(0, line.find(' ')));
        line.erase(0, line.find(' ') + 1);

        g_songs[i].name = song;
        g_songs[i].artist = artist;
        g_songs[i].duration = duration;
        g_songs[i].genre = genre;
        g_size++;
        i++;
    }

    fin.close();
}

Song *getGenreSongs(string genre, int &genreCount) {
    Song *gen = new Song[g_size];
    genreCount = 0;
    for (int i = 0; i < g_size; i++) {
        if(g_songs[i].genre == genre) {
            gen[genreCount] = g_songs[i];
            genreCount++;
        }
    }
    return gen;
}

Song *getSongsFromDuration(int duration, int &durationsCount, int filter) {
    Song *dur = new Song[g_size];
    durationsCount = 0;
    for (int i = 0; i < g_size; i++) {
        if (filter == 0 && g_songs[i].duration > duration) {
            dur[durationsCount] = g_songs[i];
            durationsCount++;
        }
        else if (filter == 1 && g_songs[i].duration < duration) {
            dur[durationsCount] = g_songs[i];
            durationsCount++;
        }
        else if (filter == 2 && g_songs[i].duration == duration) {
            dur[durationsCount] = g_songs[i];
            durationsCount++;
        }
    }
    return dur;
}

string *getUniqueArtists(int &uniqueCount) {
    string *unique = new string[g_size];
    uniqueCount = 0;
    for (int i = 0; i < g_size; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if(g_songs[i].artist == g_songs[j].artist) {
                break;
            }
        }
        if(i == j) {
            unique[uniqueCount] = g_songs[i].artist;
            uniqueCount++;
        }
    }
    return unique;
}

string getFavoriteArtist() {
    if(g_size == 0) {
        return "NONE";
    }
    int min = 0;
    string fav;
    for (int i = 0; i < g_size; i++) {
        int count = 0;
        for (int j = 0; j < g_size; j++) {
            if(g_songs[i].artist == g_songs[j].artist) {
                count++;
            }
        }
        if(count > min) {
            min = count;
            fav = g_songs[i].artist;
        }
    }
    return fav;
}