#include "Circulation.h"
#include <iostream>
#include <ctime>
#include <sstream>
#include <iomanip>

using namespace std;

Circulation::Circulation() : circulationID(""), memberID(""), bookID(""), issueDate(0), 
                             dueDate(0), returnDate(0), status("Issued"), condition("") {}

Circulation::Circulation(string cid, string mid, string bid) 
    : circulationID(cid), memberID(mid), bookID(bid), condition("") {
    issueDate = time(nullptr);
    dueDate = issueDate + (14 * 24 * 60 * 60); // 14 days
    returnDate = 0;
    status = "Issued";
}

void Circulation::issueBook() {
    issueDate = time(nullptr);
    dueDate = issueDate + (14 * 24 * 60 * 60); // 14 days default
    returnDate = 0;
    status = "Issued";
}

void Circulation::returnBook(string cond) {
    returnDate = time(nullptr);
    condition = cond;
    status = isOverdue() ? "Overdue" : "Returned";
}

bool Circulation::isOverdue() const {
    if (status == "Returned") return false;
    time_t now = time(nullptr);
    return now > dueDate;
}

int Circulation::getOverdueDays() const {
    if (!isOverdue()) return 0;
    time_t now = time(nullptr);
    return (int)((now - dueDate) / (24 * 60 * 60));
}

void Circulation::display() const {
    cout << "\n====== CIRCULATION RECORD ======" << endl;
    cout << "Circulation ID: " << circulationID << endl;
    cout << "Member ID: " << memberID << endl;
    cout << "Book ID: " << bookID << endl;
    cout << "Issue Date: " << ctime(&issueDate);
    cout << "Due Date: " << ctime(&dueDate);
    if (returnDate != 0) {
        cout << "Return Date: " << ctime(&returnDate);
        cout << "Condition: " << condition << endl;
    }
    cout << "Status: " << status << endl;
    cout << "=================================" << endl;
}

string Circulation::toCSV() const {
    return circulationID + "," + memberID + "," + bookID + "," 
           + to_string(issueDate) + "," + to_string(dueDate) + "," 
           + to_string(returnDate) + "," + status + "," + condition;
}