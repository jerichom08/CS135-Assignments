#include <iostream>
using namespace std;

int main() {
    int size;
    char symbol;
    cout << "Enter size: ";
    cin >> size;
    cout << "Enter symbol: ";
    cin >> symbol;

    for (int i = 1; i <= size; i++) {
        for (int j = size - i; j > 0; j--) {
            cout << " ";
        }
        for (int j = 1; j <= i; j++) {
            cout << symbol;
        }
        cout << endl;
    }
}