/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Project 1D

Includes functions to make a hangman game.
*/

#include <iostream>
#include <fstream>
#include <climits>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

const int g_MAX_WORDS = 1000;
int g_word_count = 0;

string g_words[g_MAX_WORDS];
string g_definitions[g_MAX_WORDS];
string g_pos[g_MAX_WORDS];

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


int getIndex(string word) {
    for (int i = 0; i < g_MAX_WORDS; i++) {
        if(word == g_words[i]) {
            return i;
        }
    }
    return -1;
}

string getDefinition(string word) {
    int index = getIndex(word);
    if(index == -1) {
        return "NOT_FOUND";
    }
    return g_definitions[index];
}

string getPOS(string word) {
    int index = getIndex(word);
    if(index == -1) {
        return "NOT_FOUND";
    }
    return g_pos[index];
}

int countPrefix(string prefix) {
    int count = 0;
    for (int i = 0; i < g_word_count; i++) {
        if (g_words[i].substr(0, prefix.length()) == prefix) {
            count++;
        }
    }
    return count;
}

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

bool editWord(string word, string definition, string pos) {
    int i = getIndex(word);
    if(i == -1) {
        return false;
    }
    g_definitions[i] = definition;
    g_pos[i] = pos;
    return true;
}

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

string getRandomWord() {
    srand((unsigned) time(NULL));
    int index = rand() % g_word_count;
    return g_words[index];
}

/*
    @param            :   The string with a word from the dictionary 
    @return           :   string of "_" based on the number of
                          characters in the given `word` 
    @post             :   Return string of "_" based on the length
                          of the given `word`.
                          For example, if the word is "game", then
                          the function would return "____". In other
                          words, a string of four "_"s.
*/
string maskWord(string word) {
    string mask;
    int len = word.size();
    for (int i = 0; i < len; i++) {
        mask += "_";
    }
    return mask;
}

/*
    @param            :   The integer for the difficulty of the game
                          (0 for easy, 1 for normal, and 2 for hard) 
    @return           :   The number of tries given the `difficulty`
                          (9 for easy, 7 for normal, and 5 for hard)
    @post             :   Return the number of tries based on given
                          difficulty (0-easy: 9 tries, 1-normal: 7
                          tries, 2-Hard: 5 tries) 
*/
int getTries(int difficulty) {
    if(difficulty == 0) {
        return 9;
    }
    if(difficulty == 1) {
        return 7;
    }
    return 5;
}

/*
    @param tries      :   The integer for remaining tries 
    @param difficulty :   The integer for the difficulty of the game 
                          (0 for easy, 1 for normal, and 2 for hard) 
    @post             :   prints the number of lives left and number
                          of lives used using "O" and "X". DO NOT
                          PRINT AN ENDLINE

    For example : calling `printAttemps(2, 1)` would print "OOXXXXX". 
                  Based on given `difficulty`, we know the total tries
                  is 7 (from `getTries(1)`). Also, the player has 2
                  `tries` remaining based on the given parameter.
                  Therefore, the function prints two "0"s to indicate
                  the remaining tries and 5 "X"s to indicate the tries
                  that have been used (7-2=5)          
*/
void printAttempts(int tries, int difficulty) {
    string s;
    int total = getTries(difficulty);
    int used = total - tries;
    for (int i = 0; i < tries; i++) {
        s += "O";
    }
    for (int i = 0; i < used; i++) {
        s += "X";
    }
    cout << s;
}

/*
    @param word       :   The string word from the dictionary
    @param letter     :   The char letter that that will be revealed
    @param(&) current :   The string representing a masked word
    @return           :   `true` if the `letter` exists in `word`,
                          otherwise return `false`  
    @post             :   If the given `letter` exists in `word`
                          reveal the `letter` in `current` masked word
                          and return `true`. Otherwise, return `false`

    For example : Let's say we have the following main function:
                  int main(){
                      string w = "g___";
                      cout << revealLetter("good", 'o', "g___") << endl;
                      cout <<  w << endl;
                  }
                  The first `cout` will print 1 because the letter 'o'
                  exists in "good". Thus, the function returned `true`.
                  The second `cout` will print "goo_". The variable `w`
                  has been modified by the function to reveal all the
                  `o`s in "good" resulting in "goo_"           
*/
bool revealLetter(string word, char letter, string &current) {
    for (int i = 0; i < word.length(); i++) {
        if(word.at(i) == letter) {
            for (int j = i; j < word.length(); j++) {
                if(word.at(j) == letter) {
                    current[j] = letter;
                }
            }
            return true;
        }
    }
    return false;
}

// game-loop for Hangman
void gameLoop() {
    int difficulty, tries;
    string word, current;
    char letter;
    while (true) {
        cout << "Welcome to Hangman!" << endl;
        cout <<  "0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
        cin >> difficulty;
        while (difficulty < 0 || difficulty > 3) {
            cout <<  "Enough horseplay >_< !\n0. easy\n1. normal\n2. hard\n3. exit\nChoose a difficulty: ";
            cin >> difficulty;
        }
        if (difficulty == 3) {
            cout << "If you're hangry, go grab a bite! See what I did there?" << endl;
            break;
        }
        word = getRandomWord();
        current = maskWord(word);
        tries = getTries(difficulty);
        while (tries != 0) {
            cout << "Life: ";
            printAttempts(tries, difficulty);
            cout << endl << "Word: "<< current << endl;
            cout << "Enter a letter: ";
            cin >> letter;
            
            if (!revealLetter(word, letter, current)) {
                tries--;
            }
            if (current == word) {
                break;
            }
            if (tries == 2) {
                cout << "The part of speech of the word is "<< getPOS(word) << endl;
            }
            if (tries == 1) {
                cout << "Definition of the word: " << getDefinition(word) << endl;
            }
        }
        if (tries == 0) {
            cout << "The word is \"" << word << "\". Better luck next time! You're getting the ..ahem.. hang of it." << endl;
        }
        else {
            cout << "Congrats!!!" << endl;
        }
    }
}

/*
int main() {
    string filename = "dictionary.txt";
    readWords(filename);

    string w = "g___";
    cout << revealLetter("good", 'o', w) << endl;
    cout <<  w << endl;
}
*/