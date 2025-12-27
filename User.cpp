#include "User.h"
#include <iostream>
#include <algorithm>

using namespace std;

User::User() : userID(""), name(""), email(""), phone(""), address(""), password(""), role("Member"), isActive(true) {}

User::User(string id, string n, string e, string p, string addr, string pwd, string r) 
    : userID(id), name(n), email(e), phone(p), address(addr), password(pwd), role(r), isActive(true) {}

bool User::verifyPassword(string pwd) const {
    return password == pwd;
}

void User::display() const {
    cout << "\n========== USER PROFILE ==========" << endl;
    cout << "User ID: " << userID << endl;
    cout << "Name: " << name << endl;
    cout << "Email: " << email << endl;
    cout << "Phone: " << phone << endl;
    cout << "Address: " << address << endl;
    cout << "Role: " << role << endl;
    cout << "Status: " << (isActive ? "Active" : "Inactive") << endl;
    cout << "=================================" << endl;
}

string User::toCSV() const {
    return userID + "," + name + "," + email + "," + phone + "," + address + "," + password + "," + role + "," + (isActive ? "1" : "0");
}