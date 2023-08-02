#include <iostream>
#include<bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

class Book {
public:
    Book(const string& title, const string& author, const string& isbn)
        : title(title), author(author), isbn(isbn), isAvailable(true) {}

    const string& getTitle() const{
        return title;
    }
    const string& getAuthor() const{
        return author;
    }
    const string& getISBN() const{
        return isbn;
    }
    bool getAvailability() const{
        return isAvailable;
    }

    void setAvailability(bool availability) {
        isAvailable = availability;
    }

private:
    string title;
    string author;
    string isbn;
    bool isAvailable;
};

class Library {
public:
    void addBook(const Book& book) { books.push_back(book); }
    void displayBooks() const {
        cout << "Available books in the library:" << endl;
        for (const Book& book : books) {
            if (book.getAvailability()) {
                cout << book.getTitle() << " by " << book.getAuthor() << " (ISBN: " << book.getISBN() << ")" << endl;
            }
        }
    }

    Book* findBookByISBN(const string& isbn) {
        for (Book& book : books) {
            if (book.getISBN() == isbn) {
                return &book;
            }
        }
        return nullptr;
    }

private:
    vector<Book> books;
};

void clearConsole() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

int main() {
    Library collegeLibrary;

    collegeLibrary.addBook(Book("Book 1", "Author A", "ISBN1234"));
    collegeLibrary.addBook(Book("Book 2", "Author B", "ISBN5678"));
    collegeLibrary.addBook(Book("Book 3", "Author C", "ISBN9012"));

    int choice;
    string isbnToBorrow;

    do {
        clearConsole();
        cout<<"\n\n**********Welcome to Our Library**********"<<endl;
        cout << "===========College Library Menu============" << endl;
        cout<<"*************Select the following choice*******"<<endl;
        cout << "1. Display available books" << endl;
        cout << "2. Borrow a book" << endl;
        cout << "3. Return a book" << endl;
        cout << "4. Exit" << endl;
        cin >> choice;
        cin.ignore();

        switch (choice) {
        case 1:
            clearConsole();
            collegeLibrary.displayBooks();
            cout << "Press Enter to go back to the menu...";
            cin.ignore();
            break;

        case 2:
            clearConsole();
            cout << "Enter the ISBN of the book you want to borrow: ";
            getline(cin, isbnToBorrow);
            {
                Book* borrowedBook = collegeLibrary.findBookByISBN(isbnToBorrow);
                if (borrowedBook) {
                    if (borrowedBook->getAvailability()) {
                        borrowedBook->setAvailability(false);
                        cout << "You have successfully borrowed \"" << borrowedBook->getTitle() << "\"" << endl;
                    } else {
                        cout << "The book \"" << borrowedBook->getTitle() << "\" is already borrowed." << endl;
                    }
                } else {
                    cout << "Book with ISBN " << isbnToBorrow << " not found in the library." << endl;
                }
            }
            cout << "Press Enter to go back to the menu...";
            cin.ignore();
            break;

        case 3:
            clearConsole();
            cout << "Enter the ISBN of the book you want to return: ";
            getline(cin, isbnToBorrow);
            {
                Book* returnedBook = collegeLibrary.findBookByISBN(isbnToBorrow);
                if (returnedBook) {
                    if (!returnedBook->getAvailability()) {
                        returnedBook->setAvailability(true);
                        cout << "You have successfully returned \"" << returnedBook->getTitle() << "\"" << endl;
                    } else {
                        cout << "The book \"" << returnedBook->getTitle() << "\" was not borrowed." << endl;
                    }
                } else {
                    cout << "Book with ISBN " << isbnToBorrow << " not found in the library." << endl;
                }
            }
            cout << "Press Enter to go back to the menu...";
            cin.ignore();
            break;

        case 4:
            cout << "Exiting the program. Thank you!" << endl;
            break;

        default:
            clearConsole();
            cout << "Invalid choice. Please try again." << endl;
            cout << "Press Enter to continue...";
            cin.ignore();
            break;
        }

    } while (choice != 4);

    return 0;
}


