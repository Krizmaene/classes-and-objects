#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Book {
private: 
    string title;
    string author; 
    int year;

public: 
    Book() {} 

    Book (string t, string a, int y) : title(t), author(a), year(y) {}

    string getTitle() {
        return title;
    }

    void displayDetailed() {
            cout << "Title: " << title << endl;
            cout << "Author: " << author << endl;
            cout << "Year: " << year << endl;
    }

    void displayDetails() {
        cout << left << setw(20) << title
         << setw(20) << author
         << setw(10) << year << endl;
    }
};

class Library {
private:
    static const int MAX_BOOKS = 100;
    Book books[MAX_BOOKS]; 
    int bookCount; 

public: 
    Library() : bookCount(0) {} 

    void addBook(string title, string author, int year) {
        if (bookCount < MAX_BOOKS) {
            books[bookCount] = Book(title, author, year);
            bookCount++;
            cout << "Book added successfully!" << endl;
        } else {
            cout << "Library is full!" << endl;
        }
    }

    void displayBooks() {
        if (bookCount == 0) {
            cout << "No books in the library!" << endl;
            return; 
        }
        cout << "Book List: " << endl;
        cout << "Title\t\t\tAuthor\t\tYear" << endl;
        for (int i = 0; i < bookCount; i++){
            books[i].displayDetails();
        }
    }

    void searchBook(string title) {
        for (int i = 0; i < bookCount; i++) {
            if (books[i].getTitle() == title) {
                cout << "Book found!" << endl;
                books[i].displayDetailed();
                return;
            }
        }
        cout << "Book not found!" << endl;
    }
};

int main() {
    Library library;
    string title, author;
    int year;
    int choice; 

    while (true) { 
        cout << "Menu" << endl;
        cout << "1 - Add Book" << endl;
        cout << "2 - Display Books" << endl;
        cout << "3 - Search Book" << endl;
        cout << "4 - Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
    

        switch (choice) {
            case 1:
                cout << "Enter title: ";
                cin.ignore();
                getline(cin, title);
                cout << "Enter Author: ";
                getline(cin, author);
                cout << "Enter year: ";
                cin >> year;
                library.addBook(title, author, year); 
                break;
            case 2:
                library.displayBooks();
                break;
            case 3: 
                cout << "Enter a book to search: ";
                cin.ignore();
                getline(cin, title);
                library.searchBook(title);
                break;
            case 4:
                return 0;
            default: 
                cout << "Invalid choice! Please try again." << endl;
        }
        cout << endl;
    }
    return 0;
}