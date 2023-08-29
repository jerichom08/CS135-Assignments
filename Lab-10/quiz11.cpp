/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Quiz 11

Defines a class Money and includes a function that withdraws money from a balance.
*/

#include <iostream>
using namespace std;

class Money {
    public:
        int dollars, cents;
};

Money withdraw_money(Money balance, Money withdrawal) {
    Money new_balance;
    new_balance.dollars = balance.dollars - withdrawal.dollars;
    new_balance.cents = balance.cents - withdrawal.cents;
    if(new_balance.cents < 0) {
        new_balance.cents += 100;
        new_balance.dollars -= 1;
    }
    if(new_balance.dollars < 0) {
        new_balance.cents = 0;
        new_balance.dollars = 0;
    }
    return new_balance;
}

int main() {
    Money starting = {100, 00};
    Money withdrawal = {2, 75};
    Money ending = withdraw_money(starting, withdrawal);
    cout << '$' << ending.dollars << '.' << ending.cents << endl;
    return 0;
}