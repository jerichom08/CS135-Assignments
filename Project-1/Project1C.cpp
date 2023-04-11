/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Project 1C

Includes the functions addWord(), editWord(), and removeWord().
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
        cout << g_words[i] << " " << g_pos[i] << ' ' << col << ' ' << g_definitions[i] << endl;
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
    for (int i = 0; i < g_MAX_WORDS; i++) {
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

/*
    @param word       :   The string with a new word
    @param definition :   The string with the definition of the
                          new `word`
    @param pos        :   The string with the pos of the new `word`
    @return           :   return `true` if the word is
                          successfully added to the dictionary
                          return `false` if failed (word already
                          exists or dictionary is full)
    @post             :   Add the given `word`, `definition`, `pos`
                          to the end of the respective
                          global-arrays.
                          The word should not be added to the
                          global-arrays if it already exists 
                          or if the array reached maximum 
                          capacity(`g_MAX_WORDS`).
                          Update `g_word_count` if the word is
                          successfully added
*/
bool addWord(string word, string definition, string pos) {
    if(g_word_count >= g_MAX_WORDS) {
        return false;
    }
    for (int i = 0; i < g_word_count; i++) {
        if(g_words[i] == word) {
            return false;
        }
    }
    g_word_count++;
    g_words[g_word_count - 1] = word;
    g_definitions[g_word_count - 1] = definition;
    g_pos[g_word_count - 1] = pos;
    return true;
}

/*
    @param word       :   The string with the word that is to
                          be edited
    @param definition :   The string with the new definition of 
                          the `word`
    @param pos        :   The string with the new pos of the `word`
    @return           :   return `true` if the word is successfully
                          edited, return `false` if the `word`
                          doesn't exist in the dictionary
    @post             :   Replace the given `word`'s  definition
                          and pos with the given `definition` and
                          `pos` (by modifying global-arrays
                          `g_definitions` and `g_pos`).
                          The modification will fail if the word
                          doesn't exist in the dictionary
*/
bool editWord(string word, string definition, string pos) {
    int i = getIndex(word);
    if(i == -1) {
        return false;
    }
    g_definitions[i] = definition;
    g_pos[i] = pos;
    return true;
}

/*
    @param            :   The string with the word that is to
                          be removed
    @return           :   return `true` if the word is successfully
                          removed from the dictionary return `false`
                          if the word doesn't exist in the dictionary
    @post             :   Remove the given `word`, `word`'s
                          definition and `word`'s pos from the
                          respective global-arrays if the word
                          exists.  
                          Update `g_word_count` if the word is
                          successfully removed
*/
bool removeWord(string word) {
    int i = getIndex(word);
    if(i == -1) {
        return false;
    }
    g_word_count--;
    g_words[i] = "";
    g_definitions[i] = "";
    g_pos[i] = "";
    return true;
}

/*
int main() {
    string filename = "words.txt";
    readWords(filename);

    string word;
    cout << "Enter word: ";
    cin >> word;

    if(bool(removeWord(word))) {
        cout << "Word removed" << endl;
    }
    else {
        cout << "Word does not exists" << endl;
    }

    cout << g_word_count << endl;
    for (int i = 0; i < g_word_count; i++) {
        cout << g_words[i] << " " << g_pos[i] << " : " << g_definitions[i] << endl;
    }

    return 0;
}
*/