/*
Author: Jericho Maniago
Course: CSCI-136
Instructor: Sadab Hafiz
Assignment: Quiz 12


*/

#include <iostream>
using namespace std;

class Customer {
private:
    string name;
    string unique_id;
public:
    Customer();
    Customer(string name, string unique_id);
    string get_name();
    string get_unique_id();
    void set_name(string name);
    void set_unique_id(string unique_id);
};

Customer::Customer() {
    name = "";
    unique_id = "";
}

Customer::Customer(string name, string unique_id) {
    this->name = name;
    this->unique_id = unique_id;
}

string Customer::get_name() {
    return name;
}

string Customer::get_unique_id() {
    return unique_id;
}

void Customer::set_name(string name) {
    this->name = name;
}

void Customer::set_unique_id(string unique_id) {
    this->unique_id = unique_id;
}

int main() {
    Customer c;
    c.set_name("Joe");
    c.set_unique_id("1");

    cout << c.get_name() << " " << c.get_unique_id() << endl;

    return 0;
}