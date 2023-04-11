/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 6C

Implements the Vigenere cipher using the encryptVigenere() function.
*/

#include <iostream>
#include <cctype>
using namespace std;

char shiftChar(char c, int rshift) {
    int a = (int)c;
    if(!isalpha(c)) {
        return c;
    }
    for (int i = 0; i < rshift; i++) {
        a++;
        if(!isalpha(a)) {
            a -= 26;
        }
    }
    return (char)(a);
}

string encryptVigenere(string plaintext, string keyword) {
    string cipher;
    int i = 0;
    for (int j = 0; j < plaintext.length(); j++) {
        int shift = (char)keyword[i] - 97;
        cipher += shiftChar(plaintext[j], shift);
        if(isalpha(plaintext[j])) {
            i++;
        }
        if(i == keyword.length()) {
            i = 0;
        }
    }
        return cipher;
}

int main() {
    string text, key;
    cout << "Enter plaintext: ";
    getline(cin, text);
    cout << "Enter keyword: ";
    getline(cin, key);
    cout << "Ciphertext: " << encryptVigenere(text, key);

    return 0;
}