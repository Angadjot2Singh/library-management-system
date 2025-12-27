#include "Book.h"
#include <iostream>
#include <algorithm>
#include <cctype>

using namespace std;

Book::Book() : bookID(""), title(""), author(""), isbn(""), category(""), yearPublished(0), 
               totalCopies(0), availableCopies(0), publisher(""), isActive(true) {}

Book::Book(string id, string t, string a, string i, string cat, int year, int copies, string pub)
    : bookID(id), title(t), author(a), isbn(i), category(cat), yearPublished(year),
      totalCopies(copies), availableCopies(copies), publisher(pub), isActive(true) {}

bool Book::issueBook() {
    if (availableCopies > 0) {
        availableCopies--;
        return true;
    }
    return false;
}

bool Book::returnBook() {
    if (availableCopies < totalCopies) {
        availableCopies++;
        return true;
    }
    return false;
}

void Book::display() const {
    cout << "\n========== BOOK DETAILS ==========" << endl;
    cout << "Book ID: " << bookID << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Category: " << category << endl;
    cout << "Year Published: " << yearPublished << endl;
    cout << "Publisher: " << publisher << endl;
    cout << "Total Copies: " << totalCopies << endl;
    cout << "Available Copies: " << availableCopies << endl;
    cout << "Status: " << (isActive ? "Active" : "Inactive") << endl;
    cout << "==================================" << endl;
}

string Book::toCSV() const {
    return bookID + "," + title + "," + author + "," + isbn + "," + category + "," 
           + to_string(yearPublished) + "," + publisher + "," + to_string(totalCopies) 
           + "," + to_string(availableCopies) + "," + (isActive ? "1" : "0");
}

bool Book::matchesTitle(string searchTerm) const {
    string searchLower = searchTerm;
    string titleLower = title;
    transform(searchLower.begin(), searchLower.end(), searchLower.begin(), ::tolower);
    transform(titleLower.begin(), titleLower.end(), titleLower.begin(), ::tolower);
    return titleLower.find(searchLower) != string::npos;
}

bool Book::matchesAuthor(string searchTerm) const {
    string searchLower = searchTerm;
    string authorLower = author;
    transform(searchLower.begin(), searchLower.end(), searchLower.begin(), ::tolower);
    transform(authorLower.begin(), authorLower.end(), authorLower.begin(), ::tolower);
    return authorLower.find(searchLower) != string::npos;
}

bool Book::matchesISBN(string searchTerm) const {
    return isbn == searchTerm;
}