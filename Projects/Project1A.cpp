/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Project 1A

Includes function readWords() that reads a text file and modifies global variables for the dictionary using arrays.
*/

#include <iostream>
#include <fstream>
#include <climits>
#include <cstdlib>
using namespace std;

const int g_MAX_WORDS = 1000;
int g_word_count = 0;

string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];

/*
    @param            :   The string with the `filename`
    @post             :   Reads the words, definitions
                          pos into the global-arrays 
                          and set the value of `g_word_count`
                          to the number of words read
*/

void readWords(string file_name) {
    ifstream fin(file_name);
    if(fin.fail()) {
        cerr << "File cannot be opened for reading." << endl;
        exit(1);
    }

    string word, pos, col, def;
    while(fin >> word >> pos >> col) {
        g_words[g_word_count] = word;
        g_pos[g_word_count] = pos;
        getline(fin, def);
        def = def.substr(1, def.length());
        g_definitions[g_word_count] = def;
        g_word_count++;
    }

    cout << g_word_count << endl;
    for (int i = 0; i < g_word_count; i++) {
        cout << g_words[i] << " " << g_pos[i] << ' ' << col << g_definitions[i] << endl;
    }
    
    fin.close();
}

int main() {
    string filename = "words.txt";
    readWords(filename);
    return 0;
}