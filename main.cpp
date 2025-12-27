#include "Library.h"
#include <iostream>
#include <string>

using namespace std;

void displayMainMenu();
void displayMemberMenu();
void displayLibrarianMenu();

int main() {
    LibraryManagementSystem lms;
    int choice;
    bool running = true;
    
    cout << "\n╔════════════════════════════════════════════════════════════════╗" << endl;
    cout << "║         LIBRARY MANAGEMENT SYSTEM - MAIN MENU               ║" << endl;
    cout << "║              Automated Digital Solution                      ║" << endl;
    cout << "╚════════════════════════════════════════════════════════════════╝" << endl;
    
    while (running) {
        displayMainMenu();
        cin >> choice;
        
        switch (choice) {
            case 1: {
                string userID, password;
                cout << "\n--- LOGIN ---" << endl;
                cout << "Enter User ID: ";
                cin >> userID;
                cout << "Enter Password: ";
                cin >> password;
                
                if (lms.login(userID, password)) {
                    cout << "\n✓ Login successful!" << endl;
                    User* user = lms.getCurrentUser();
                    
                    bool sessionRunning = true;
                    while (sessionRunning) {
                        if (user->getRole() == "Member") {
                            displayMemberMenu();
                            int memberChoice;
                            cin >> memberChoice;
                            
                            switch (memberChoice) {
                                case 1:
                                    user->display();
                                    break;
                                case 2: {
                                    string email, phone, address;
                                    cout << "Enter new email: ";
                                    cin >> email;
                                    cout << "Enter new phone: ";
                                    cin >> phone;
                                    cout << "Enter new address: ";
                                    cin.ignore();
                                    getline(cin, address);
                                    lms.updateProfile(email, phone, address);
                                    cout << "✓ Profile updated!" << endl;
                                    break;
                                }
                                case 3:
                                    cout << "\n--- BOOK SEARCH ---" << endl;
                                    cout << "1. Search by Title\n2. Search by Author\n3. View All Books\n";
                                    cout << "Choose: ";
                                    int searchChoice;
                                    cin >> searchChoice;
                                    
                                    if (searchChoice == 1) {
                                        string title;
                                        cout << "Enter book title: ";
                                        cin.ignore();
                                        getline(cin, title);
                                        auto results = lms.searchByTitle(title);
                                        cout << "\nFound " << results.size() << " books" << endl;
                                        for (auto book : results) {
                                            book->display();
                                        }
                                    } else if (searchChoice == 2) {
                                        string author;
                                        cout << "Enter author name: ";
                                        cin.ignore();
                                        getline(cin, author);
                                        auto results = lms.searchByAuthor(author);
                                        cout << "\nFound " << results.size() << " books" << endl;
                                        for (auto book : results) {
                                            book->display();
                                        }
                                    } else {
                                        lms.displayAllBooks();
                                    }
                                    break;
                                case 4:
                                    sessionRunning = false;
                                    lms.logout();
                                    cout << "\n✓ Logged out successfully!" << endl;
                                    break;
                                default:
                                    cout << "Invalid choice!" << endl;
                            }
                        } else if (user->getRole() == "Librarian") {
                            displayLibrarianMenu();
                            int librarianChoice;
                            cin >> librarianChoice;
                            
                            switch (librarianChoice) {
                                case 1: {
                                    string title, author, isbn, category, publisher;
                                    int year, copies;
                                    cout << "\n--- ADD BOOK ---" << endl;
                                    cout << "Enter title: ";
                                    cin.ignore();
                                    getline(cin, title);
                                    cout << "Enter author: ";
                                    getline(cin, author);
                                    cout << "Enter ISBN: ";
                                    cin >> isbn;
                                    cout << "Enter category: ";
                                    cin.ignore();
                                    getline(cin, category);
                                    cout << "Enter year published: ";
                                    cin >> year;
                                    cout << "Enter number of copies: ";
                                    cin >> copies;
                                    cout << "Enter publisher: ";
                                    cin.ignore();
                                    getline(cin, publisher);
                                    
                                    lms.addBook(title, author, isbn, category, year, copies, publisher);
                                    cout << "\n✓ Book added successfully!" << endl;
                                    break;
                                }
                                case 2:
                                    lms.displayAllBooks();
                                    break;
                                case 3:
                                    cout << "\n--- SYSTEM STATISTICS ---" << endl;
                                    lms.viewSystemStatistics();
                                    break;
                                case 4:
                                    sessionRunning = false;
                                    lms.logout();
                                    cout << "\n✓ Logged out successfully!" << endl;
                                    break;
                                default:
                                    cout << "Invalid choice!" << endl;
                            }
                        }
                    }
                } else {
                    cout << "\n✗ Login failed! Invalid credentials." << endl;
                }
                break;
            }
            case 2: {
                string name, email, phone, address, password;
                cout << "\n--- REGISTER NEW MEMBER ---" << endl;
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter email: ";
                getline(cin, email);
                cout << "Enter phone: ";
                getline(cin, phone);
                cout << "Enter address: ";
                getline(cin, address);
                cout << "Enter password: ";
                getline(cin, password);
                
                if (lms.registerMember(name, email, phone, address, password)) {
                    cout << "\n✓ Registration successful! You can now login." << endl;
                }
                break;
            }
            case 3:
                cout << "\n╔════════════════════════════════════════════════════════════════╗" << endl;
                cout << "║              Thank you for using Library Management System      ║" << endl;
                cout << "║                    Goodbye! Have a great day!                  ║" << endl;
                cout << "╚════════════════════════════════════════════════════════════════╝\n" << endl;
                running = false;
                break;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }
    
    return 0;
}

void displayMainMenu() {
    cout << "\n╔════════════════════════════════════════════════════════════════╗" << endl;
    cout << "║                      MAIN MENU                                 ║" << endl;
    cout << "╠════════════════════════════════════════════════════════════════╣" << endl;
    cout << "║  1. Login                                                      ║" << endl;
    cout << "║  2. Register as New Member                                     ║" << endl;
    cout << "║  3. Exit                                                       ║" << endl;
    cout << "╚════════════════════════════════════════════════════════════════╝" << endl;
    cout << "Choose option: ";
}

void displayMemberMenu() {
    cout << "\n╔════════════════════════════════════════════════════════════════╗" << endl;
    cout << "║                    MEMBER MENU                                 ║" << endl;
    cout << "╠════════════════════════════════════════════════════════════════╣" << endl;
    cout << "║  1. View My Profile                                            ║" << endl;
    cout << "║  2. Update Profile                                             ║" << endl;
    cout << "║  3. Search Books                                               ║" << endl;
    cout << "║  4. Logout                                                     ║" << endl;
    cout << "╚════════════════════════════════════════════════════════════════╝" << endl;
    cout << "Choose option: ";
}

void displayLibrarianMenu() {
    cout << "\n╔════════════════════════════════════════════════════════════════╗" << endl;
    cout << "║                  LIBRARIAN MENU                                ║" << endl;
    cout << "╠════════════════════════════════════════════════════════════════╣" << endl;
    cout << "║  1. Add New Book                                               ║" << endl;
    cout << "║  2. View All Books                                             ║" << endl;
    cout << "║  3. View System Statistics                                     ║" << endl;
    cout << "║  4. Logout                                                     ║" << endl;
    cout << "╚════════════════════════════════════════════════════════════════╝" << endl;
    cout << "Choose option: ";
}