#ifndef CIRCULATION_H
#define CIRCULATION_H

#include <string>
#include <ctime>

using namespace std;

class Circulation {
private:
    string circulationID;
    string memberID;
    string bookID;
    time_t issueDate;
    time_t dueDate;
    time_t returnDate;
    string status; // "Issued", "Returned", "Overdue"
    string condition; // "Good", "Fair", "Damaged"

public:
    Circulation();
    Circulation(string cid, string mid, string bid);
    
    // Getters
    string getCirculationID() const { return circulationID; }
    string getMemberID() const { return memberID; }
    string getBookID() const { return bookID; }
    time_t getIssueDate() const { return issueDate; }
    time_t getDueDate() const { return dueDate; }
    time_t getReturnDate() const { return returnDate; }
    string getStatus() const { return status; }
    string getCondition() const { return condition; }
    
    // Operations
    void issueBook();
    void returnBook(string cond);
    bool isOverdue() const;
    int getOverdueDays() const;
    
    // Display
    void display() const;
    string toCSV() const;
};

#endif