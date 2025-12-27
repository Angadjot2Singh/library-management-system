#include "Library.h"
#include <iostream>
#include <fstream>
#include <algorithm>

using namespace std;

LibraryManagementSystem::LibraryManagementSystem() {
    membersFile = "data/members.csv";
    booksFile = "data/books.csv";
    circulationFile = "data/circulation.csv";
    finesFile = "data/fines.csv";
    currentUser = nullptr;
    loadAllData();
}

void LibraryManagementSystem::loadAllData() {
    // Load members
    ifstream mfile(membersFile);
    if (mfile.is_open()) {
        string line;
        while (getline(mfile, line)) {
            // Parse and load members
        }
        mfile.close();
    }
    
    // Load books
    ifstream bfile(booksFile);
    if (bfile.is_open()) {
        string line;
        while (getline(bfile, line)) {
            // Parse and load books
        }
        bfile.close();
    }
}

void LibraryManagementSystem::saveAllData() {
    // Save members to CSV
    ofstream mfile(membersFile);
    for (const auto& member : members) {
        mfile << member.toCSV() << endl;
    }
    mfile.close();
    
    // Save books to CSV
    ofstream bfile(booksFile);
    for (const auto& book : books) {
        bfile << book.toCSV() << endl;
    }
    bfile.close();
}

bool LibraryManagementSystem::login(string userID, string password) {
    for (auto& member : members) {
        if (member.getUserID() == userID && member.verifyPassword(password)) {
            currentUser = &member;
            return true;
        }
    }
    return false;
}

bool LibraryManagementSystem::registerMember(string name, string email, string phone, 
                                            string address, string password) {
    string memberID = generateID("M");
    User newMember(memberID, name, email, phone, address, password, "Member");
    members.push_back(newMember);
    saveAllData();
    return true;
}

void LibraryManagementSystem::logout() {
    currentUser = nullptr;
}

void LibraryManagementSystem::viewProfile() {
    if (currentUser) {
        currentUser->display();
    }
}

void LibraryManagementSystem::updateProfile(string email, string phone, string address) {
    if (currentUser) {
        currentUser->setEmail(email);
        currentUser->setPhone(phone);
        currentUser->setAddress(address);
        saveAllData();
    }
}

void LibraryManagementSystem::addBook(string title, string author, string isbn, 
                                      string category, int year, int copies, string publisher) {
    string bookID = generateID("B");
    Book newBook(bookID, title, author, isbn, category, year, copies, publisher);
    books.push_back(newBook);
    saveAllData();
}

Book* LibraryManagementSystem::findBook(string bookID) {
    for (auto& book : books) {
        if (book.getBookID() == bookID) {
            return &book;
        }
    }
    return nullptr;
}

vector<Book*> LibraryManagementSystem::searchByTitle(string title) {
    vector<Book*> results;
    for (auto& book : books) {
        if (book.matchesTitle(title)) {
            results.push_back(&book);
        }
    }
    return results;
}

vector<Book*> LibraryManagementSystem::searchByAuthor(string author) {
    vector<Book*> results;
    for (auto& book : books) {
        if (book.matchesAuthor(author)) {
            results.push_back(&book);
        }
    }
    return results;
}

vector<Book*> LibraryManagementSystem::searchByISBN(string isbn) {
    vector<Book*> results;
    for (auto& book : books) {
        if (book.matchesISBN(isbn)) {
            results.push_back(&book);
        }
    }
    return results;
}

void LibraryManagementSystem::displayAllBooks() {
    cout << "\n========== LIBRARY INVENTORY ==========" << endl;
    cout << "Total Books: " << books.size() << endl;
    for (const auto& book : books) {
        book.display();
    }
}

bool LibraryManagementSystem::issueBook(string memberID, string bookID) {
    Book* book = findBook(bookID);
    User* member = findMember(memberID);
    
    if (!book || !member || !book->issueBook()) {
        return false;
    }
    
    string circulationID = generateID("C");
    Circulation circ(circulationID, memberID, bookID);
    circulations.push_back(circ);
    saveAllData();
    return true;
}

bool LibraryManagementSystem::returnBook(string circulationID, string condition) {
    Circulation* circ = findCirculation(circulationID);
    Book* book = findBook(circ->getBookID());
    
    if (!circ || !book || !book->returnBook()) {
        return false;
    }
    
    circ->returnBook(condition);
    
    if (circ->isOverdue()) {
        string fineID = generateID("F");
        Fine newFine(fineID, circ->getMemberID(), circulationID, circ->getOverdueDays());
        fines.push_back(newFine);
    }
    
    saveAllData();
    return true;
}

string LibraryManagementSystem::generateID(string prefix) {
    static int counter = 1000;
    return prefix + to_string(++counter);
}

User* LibraryManagementSystem::findMember(string userID) {
    for (auto& member : members) {
        if (member.getUserID() == userID) {
            return &member;
        }
    }
    return nullptr;
}

Circulation* LibraryManagementSystem::findCirculation(string circulationID) {
    for (auto& circ : circulations) {
        if (circ.getCirculationID() == circulationID) {
            return &circ;
        }
    }
    return nullptr;
}

Fine* LibraryManagementSystem::findFine(string fineID) {
    for (auto& fine : fines) {
        if (fine.getFineID() == fineID) {
            return &fine;
        }
    }
    return nullptr;
}