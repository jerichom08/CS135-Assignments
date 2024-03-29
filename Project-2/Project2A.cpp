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

/*
    @post             :   Replace the old global
                          dynamically allocated arrays
                          with new dynamically allocated
                          arrays of twice the size 
                          ('g_curr_size' * 2). Update
                          'g_curr_size' accordingly.
                          Make sure you copy the contents
                          of the older arrays. Do this
                          for the following global-arrays:
                          'g_song_names', 'g_artist_names', 
                          'g_song_durations', 'g_genres'
*/
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
/*
    @param            :   The string with the 'filename'
    @post             :   Reads the song, artists,
                          song durations and genres into 
                          the global-arrays and set the 
                          value of 'g_number_of_songs'
                          to the number of songs read.
                          Call 'allocateNew()' to allocate 
                          an array of larger size if the 
                          dynamic arrays reach full 
                          capacity.
*/
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

int main(){
    readSongs("songs.txt");
    cout << g_curr_size << endl
         << g_number_of_songs << endl;
    for (int i = 0; i < g_curr_size; i++) {
        cout << g_song_names[i] << endl;
    }
}