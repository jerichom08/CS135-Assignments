/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Project 1B

Includes the functions getIndex(), getDefinition(), getPOS(), and countPrefix().
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

void readWords(string filename) {
    ifstream fin(filename);
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

/*
    @param            :   The string with a query word
    @return           :   Integer index of the word in
                          `g_words` global-array. Returns
                          -1 if the word is not found
    @post             :   Find the index of given `word`
                          in the `g_words` array. Return -1
                          if word is not in the array
*/
int getIndex(string word) {
    for (int i = 0; i < g_word_count; i++) {
        if(word == g_words[i]) {
            return i;
        }
    }
    return -1;
}

/*
    @param            :   The string with a query word
    @return           :   Return the string definition of
                          the word from  `g_definitions`
                          global-array. Return "NOT_FOUND" if
                          word doesn't exist in the dictionary
    @post             :   Find the definition of the given `word`
                          Return "NOT_FOUND" otherwise
*/
string getDefinition(string word) {
    int index = getIndex(word);
    if(index == -1) {
        return "NOT_FOUND";
    }
    return g_definitions[index];
}

/*
    @param            :   The string with a query word
    @return           :   Return the string part-of-speech(pos) 
                          from the `g_pos` global-array. Return
                          "NOT_FOUND" if the word doesn't exist
                          in the dictionary.
    @post             :   Find the pos of the given `word`
                          Return "NOT_FOUND" otherwise
*/
string getPOS(string word) {
    int index = getIndex(word);
    if(index == -1) {
        return "NOT_FOUND";
    }
    return g_pos[index];
}

/*
    @param            :   The string prefix of a word (the prefix
                          can be of any length)
    @return           :   Integer number of words found that starts
                          with the given `prefix`
    @post             :   Count the words that start with the given
                          `prefix`
*/
int countPrefix(string prefix) {
    int count = 0;
    for (int i = 0; i < g_word_count; i++) {
        if (g_words[i].substr(0, prefix.length()) == prefix) {
            count++;
        }
    }
    return count;
}

int main() {
    string filename = "words.txt";
    readWords(filename);

    string word;
    cout << "Enter word: ";
    cin >> word;
    cout << countPrefix(word);

    return 0;
}