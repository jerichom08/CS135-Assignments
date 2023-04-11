/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 6D

Includes functions to decrypt text that are encrypted by the Caesar or Vigenere cipher.
*/

#include <iostream>
#include <cctype>
using namespace std;

char shiftCharRight(char c, int rshift) {
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

char shiftCharLeft(char c, int lshift) {
    int a = (int)c;
    if(!isalpha(c)) {
        return c;
    }
    for (int i = lshift; i > 0; i--) {
        a--;
        if(!isalpha(a)) {
            a += 26;
        }
    }
    return (char)(a);
}

string encryptCaesar(string plaintext, int rshift) {
    string cipher;
    for (int i = 0; i < plaintext.length(); i++) {
        cipher += shiftCharRight(plaintext[i], rshift);
    }
    return cipher;
}

string decryptCaesar(string ciphertext, int rshift) {
    string decrypt;
    for (int i = 0; i < ciphertext.length(); i++) {
        decrypt += shiftCharLeft(ciphertext[i], rshift);
    }
    return decrypt;
}

string encryptVigenere(string plaintext, string keyword) {
    string cipher;
    int i = 0;
    for (int j = 0; j < plaintext.length(); j++) {
        int shift = (char)keyword[i] - 97;
        cipher += shiftCharRight(plaintext[j], shift);
        if(isalpha(plaintext[j])) {
            i++;
        }
        if(i == keyword.length()) {
            i = 0;
        }
    }
        return cipher;
}

string decryptVigenere(string ciphertext, string keyword) {
    string decrypt;
    int i = 0;
    for (int j = 0; j < ciphertext.length(); j++) {
        int shift = (char)keyword[i] - 97;
        decrypt += shiftCharLeft(ciphertext[j], shift);
        if(isalpha(ciphertext[j])) {
            i++;
        }
        if(i == keyword.length()) {
            i = 0;
        }
    }
    return decrypt;
}

int main() {
    string text, key, caesarText, vigenereText;
    int shift;
    cout << "Enter plaintext: ";
    getline(cin, text);

    cout << endl
         << "= Caesar =" << endl
         << "Enter shift: ";
    cin >> shift;
    caesarText = encryptCaesar(text, shift);
    cout << "Ciphertext: " << caesarText << endl
         << "Decrypted: " << decryptCaesar(caesarText, shift) << endl;

    cout << endl
         << "= Vigenere =" << endl
         << "Enter keyword: ";
    cin >> key;
    vigenereText = encryptVigenere(text, key);
    cout << "Ciphertext: " << vigenereText << endl
         << "Decrypted: " << decryptVigenere(vigenereText, key) << endl;

    return 0;
}