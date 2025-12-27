#ifndef LIBRARY_H
#define LIBRARY_H

#include "User.h"
#include "Book.h"
#include "Circulation.h"
#include "Fine.h"
#include <vector>
#include <map>
#include <fstream>

using namespace std;

class LibraryManagementSystem {
private:
    vector<User> members;
    vector<Book> books;
    vector<Circulation> circulations;
    vector<Fine> fines;
    
    User* currentUser;
    
    // File paths
    string membersFile;
    string booksFile;
    string circulationFile;
    string finesFile;
    
    // Helper functions
    string generateID(string prefix);
    bool userExists(string userID) const;
    Book* findBook(string bookID);
    User* findMember(string userID);
    Circulation* findCirculation(string circulationID);
    Fine* findFine(string fineID);

public:
    LibraryManagementSystem();
    
    // Initialization
    void loadAllData();
    void saveAllData();
    
    // Authentication
    bool login(string userID, string password);
    bool registerMember(string name, string email, string phone, string address, string password);
    void logout();
    User* getCurrentUser() { return currentUser; }
    
    // Member Management
    void viewProfile();
    void updateProfile(string email, string phone, string address);
    
    // Book Management
    void addBook(string title, string author, string isbn, string category, int year, int copies, string publisher);
    void updateBook(string bookID, string title, string author, string category);
    void deleteBook(string bookID);
    
    // Book Search
    vector<Book*> searchByTitle(string title);
    vector<Book*> searchByAuthor(string author);
    vector<Book*> searchByISBN(string isbn);
    vector<Book*> searchByCategory(string category);
    void displayAllBooks();
    
    // Circulation Operations
    bool issueBook(string memberID, string bookID);
    bool returnBook(string circulationID, string condition);
    void viewBorrowedBooks(string memberID);
    void viewCirculationHistory(string memberID);
    
    // Fine Management
    void calculateOverdueFines();
    bool payFine(string fineID, float amount);
    void waiverFine(string fineID, float amount);
    void viewFines(string memberID);
    void generateFineReport();
    
    // Reports
    void generateCirculationReport();
    void generatePopularBooksReport();
    void generateMemberActivityReport();
    void generateFineCollectionReport();
    
    // Admin Functions
    void viewAllMembers();
    void viewSystemStatistics();
};

#endif