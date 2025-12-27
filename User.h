#ifndef USER_H
#define USER_H

#include <string>
#include <vector>

using namespace std;

class User {
protected:
    string userID;
    string name;
    string email;
    string phone;
    string address;
    string password;
    string role; // "Member" or "Librarian"
    bool isActive;

public:
    User();
    User(string id, string n, string e, string p, string addr, string pwd, string r);
    
    // Getters
    string getUserID() const { return userID; }
    string getName() const { return name; }
    string getEmail() const { return email; }
    string getPhone() const { return phone; }
    string getAddress() const { return address; }
    string getRole() const { return role; }
    bool getStatus() const { return isActive; }
    
    // Setters
    void setEmail(string e) { email = e; }
    void setPhone(string p) { phone = p; }
    void setAddress(string addr) { address = addr; }
    void setPassword(string pwd) { password = pwd; }
    
    // Authentication
    bool verifyPassword(string pwd) const;
    
    // Display
    virtual void display() const;
    virtual string toCSV() const;
};

#endif