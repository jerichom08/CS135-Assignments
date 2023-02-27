/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Lab 5 A-G

A) Includes a function bool isDivisibleBy(int n, int d) whichs checks if n is divisble by d.
B) Includes a function that checks if a number is a prime number.
C) Includes a function that returns the next prime number greater than a user inputted number.
D) Includes a function that returns the number of prime numbers in a given interval.
E) Includes a function that determines whether a prime number is a twin prime.
F) Includes a function that returns the next twin prime greater than a user inputted number;
G) Includes a function that returns the largest twin prime within a given range.
*/

#include <iostream>
#include <climits>
using namespace std;

bool isDivisibleBy(int n, int d) {
    if(d == 0) {
        return false;
    }
    if(n % d == 0) {
        return true;
    }
    return false;
}

bool isPrime(int n) {

    if(n < 2) {
        return false;
    }
    for (int i = 2; i < n; i++) {
        if(isDivisibleBy(n, i)) {
            return false;
        }
    }
    return true;
}

int nextPrime(int n) {
    for (int i = n + 1; i < INT_MAX; i++) {
        if(isPrime(i)) {
            return i;
        }
    }
    return 0;
}

int countPrimes(int a, int b) {
    int num = 0;
    for (int i = a; i <= b; i++) {
        if(isPrime(i)) {
            num++;
        }
    }
    return num;
}

bool isTwinPrime(int n) {
    if(isPrime(n) && (isPrime(n - 2) || isPrime(n + 2))) {
        return true;
    }
    return false;
}

int nextTwinPrime(int n) {
    for (int i = n + 1; i < INT_MAX; i++) {
        if(isTwinPrime(i)) {
            return i;
        }
    }
    return 0;
}

int largestTwinPrime(int a, int b) {
    for (int i = b; i >= a; i--) {
        if(isTwinPrime(i)) {
            return i;
        }
    }
    return -1;
}

int main() {
    int a1, a2, b, c, d1, d2, e, f, g1, g2;
    
    /* cout << "Enter first number: ";
    cin >> a1;
    cout << "Enter second number: ";
    cin >> a2;
    if (isDivisibleBy(a1, a2)) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }

    cout << "Enter Number: ";
    cin >> b;
    if(isPrime(b)) {
        cout << "Is prime" << endl;
    }
    else {
        cout << "Is not prime" << endl;
    }

    cout << "Enter number: ";
    cin >> c;
    cout << nextPrime(c) << endl; 

    cout << "Enter start number: ";
    cin >> d1;
    cout << "Enter end number: ";
    cin >> d2;
    cout << countPrimes(d1, d2) << endl; 

    cout << "Enter number: ";
    cin >> e;
    if(isTwinPrime(e)) {
        cout << "Is twin prime" << endl;
    }
    else {
        cout << "Is not twin prime" << endl;
    }

    cout << "Enter number: ";
    cin >> f;
    cout << nextTwinPrime(f); */

    cout << "Enter start number: ";
    cin >> g1;
    cout << "Enter end number: ";
    cin >> g2;
    cout << largestTwinPrime(g1, g2);

    return 0;
}