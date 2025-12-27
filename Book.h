#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <vector>

using namespace std;

class Book {
private:
    string bookID;
    string title;
    string author;
    string isbn;
    string category;
    int yearPublished;
    int totalCopies;
    int availableCopies;
    string publisher;
    bool isActive;

public:
    Book();
    Book(string id, string t, string a, string i, string cat, int year, int copies, string pub);
    
    // Getters
    string getBookID() const { return bookID; }
    string getTitle() const { return title; }
    string getAuthor() const { return author; }
    string getISBN() const { return isbn; }
    string getCategory() const { return category; }
    int getYear() const { return yearPublished; }
    int getTotalCopies() const { return totalCopies; }
    int getAvailableCopies() const { return availableCopies; }
    string getPublisher() const { return publisher; }
    bool getStatus() const { return isActive; }
    
    // Setters
    void setTitle(string t) { title = t; }
    void setAuthor(string a) { author = a; }
    void setCategory(string cat) { category = cat; }
    
    // Availability Operations
    bool issueBook();
    bool returnBook();
    bool isAvailable() const { return availableCopies > 0; }
    
    // Display
    void display() const;
    string toCSV() const;
    
    // Search helpers
    bool matchesTitle(string searchTerm) const;
    bool matchesAuthor(string searchTerm) const;
    bool matchesISBN(string searchTerm) const;
};

#endif