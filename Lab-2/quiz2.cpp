//Uses a for loop to initialize an array from 1 to 10 and prints out each number on a separate line.

#include <iostream>
using namespace std;

int main() {
    int nums[10];
    for (int i = 1; i <= 10; i++) {
        nums[i] = i;
        cout << nums[i] << endl;
    }
    return 0;
}