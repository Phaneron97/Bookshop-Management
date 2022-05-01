#include <iostream> // read/write from console
#include <fstream> // File handling
#include <filesystem>

#include "log.h"
#include "book.h"
#include "bookshop.h"

using namespace std;
using filesystem::directory_iterator;

int main() {
    bookshop bookshop;
    string bookName;
    string title;
    string firstname;
    string surname;
    int copies;
    
    cout << "Welcome to the bookshop!" << endl;
    int choice;   
    do {
        bookshop.display_choices();
        cout << "What do you want to do?" << endl;    
        cin >> choice;

        switch (choice) {
            case 0: 
                bookshop.display_all_books();
                break;
            case 1: 
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                cout << "Title: ";
                getline(cin, title);
                cout << "author firstname: ";
                cin >> firstname;
                cout << "author surname: ";
                cin >> surname;
                cout << "copies: ";
                cin >> copies;    
                bookshop.add_book(title, firstname, surname, copies);
                break;
            case 2:
                cin.clear();
                cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

                cout << "Type the name of the book: ";
                getline(cin, bookName);
                bookshop.search_book(bookName);
                break;
            default:
                cout << "not a known option" << endl;
                break;
        }
        cout << "==============================================" << endl;
    } while(choice != 5);
    cout << "Goodbye!" << endl;
}