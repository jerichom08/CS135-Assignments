/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 6B

Implements the Caesar cipher encryption by using the functions shiftChar() and encryptCaesar().
*/

#include <iostream>
using namespace std;

// A helper function to shift one character by rshift
char shiftChar(char c, int rshift) {
    int a = (int)c;
    if(a < 65 || (a > 90 && a < 97) || a > 122) {
        return c;
    }
    for (int i = 0; i < rshift; i++) {
        a++;
        if((a > 90 && a < 97) || a > 122) {
            a -= 26;
        }
    }
    return (char)(a);
}

// Caesar cipher encryption
string encryptCaesar(string plaintext, int rshift) {
    string cipher;
    for (int i = 0; i < plaintext.length(); i++) {
        cipher += shiftChar(plaintext[i], rshift);
    }
    return cipher;
}

int main() {
    string text;
    int shift;

    cout << "Enter plaintext: ";
    getline(cin, text);
    cout << "Enter shift: ";
    cin >> shift;
    cout << "Ciphertext: " << encryptCaesar(text, shift);

    return 0;
}