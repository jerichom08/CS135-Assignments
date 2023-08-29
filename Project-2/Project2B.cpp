/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Project 2A

Reads in songs from a text file and puts each element in dynamically allocated arrays.
*/

#include <iostream>
#include <fstream>
#include <climits>
#include <cstdlib>
using namespace std;

int g_curr_size = 2;
int g_number_of_songs = 0;

string *g_song_names = new string[g_curr_size];
string *g_artist_names = new string[g_curr_size];
int *g_song_durations = new int[g_curr_size];
string *g_genres = new string[g_curr_size];

void allocateNew() {
    g_curr_size *= 2;
    string *new_song_names = new string[g_curr_size];
    string *new_artist_names = new string[g_curr_size];
    int *new_song_durations = new int[g_curr_size];
    string *new_genres = new string[g_curr_size];

    for (int i = 0; i < g_number_of_songs; i++) {
        new_song_names[i] = g_song_names[i];
        new_artist_names[i] = g_artist_names[i];
        new_song_durations[i] = g_song_durations[i];
        new_genres[i] = g_genres[i];
    }

    delete[] g_song_names;
    delete[] g_artist_names;
    delete[] g_song_durations;
    delete[] g_genres;

    g_song_names = new_song_names;
    g_artist_names = new_artist_names;
    g_song_durations = new_song_durations;
    g_genres = new_genres;
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

        if(i == g_curr_size) {
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

        g_song_names[i] = song;
        g_artist_names[i] = artist;
        g_song_durations[i] = duration;
        g_genres[i] = genre;
        g_number_of_songs++;
        i++;
    }

    fin.close();
}

string *getGenreSongs(string genre, int &genreCount) {
    string *gen = new string[g_number_of_songs];
    genreCount = 0;
    for (int i = 0; i < g_number_of_songs; i++) {
        if(g_genres[i] == genre) {
            gen[genreCount] = g_song_names[i];
            genreCount++;
        }
    }
    return gen;
}

string *getSongsFromDuration(int duration, int &durationsCount, int filter) {
    string *dur = new string[g_number_of_songs];
    durationsCount = 0;
    for (int i = 0; i < g_number_of_songs; i++) {
        if (filter == 0 && g_song_durations[i] > duration) {
            dur[durationsCount] = g_song_names[i];
            durationsCount++;
        }
        else if (filter == 1 && g_song_durations[i] < duration) {
            dur[durationsCount] = g_song_names[i];
            durationsCount++;
        }
        else if (filter == 2 && g_song_durations[i] == duration) {
            dur[durationsCount] = g_song_names[i];
            durationsCount++;
        }
    }
    return dur;
}

string *getUniqueArtists(int &uniqueCount) {
    string *unique = new string[g_number_of_songs];
    uniqueCount = 0;
    for (int i = 0; i < g_number_of_songs; i++) {
        int j;
        for (j = 0; j < i; j++) {
            if(g_artist_names[i] == g_artist_names[j]) {
                break;
            }
        }
        if(i == j) {
            unique[uniqueCount] = g_artist_names[i];
            uniqueCount++;
        }
    }
    return unique;
}

string getFavoriteArtist() {
    if(g_number_of_songs == 0) {
        return "NONE";
    }
    int min = 0;
    string fav;
    for (int i = 0; i < g_number_of_songs; i++) {
        int count = 0;
        for (int j = 0; j < g_number_of_songs; j++) {
            if(g_artist_names[i] == g_artist_names[j]) {
                count++;
            }
        }
        if(count > min) {
            min = count;
            fav = g_artist_names[i];
        }
    }
    return fav;
}