#include <iostream> // read/write from console
#include <fstream> // File handling
#include <filesystem>

#include "log.h"

using namespace std;
using filesystem::directory_iterator;

class bookshop {
    // book book;
    public: 
        void add_book(string title, string authorFirstname, string authorSurname, int copies);
        void delete_book();        
        void update_book();
        void display_all_books();
        void details_book();
        void display_choices();
};

class book : public bookshop{
    public:
        string title;
        string authorFirstname;
        string authorSurname;
        string fullname;
        int copies;
    
    public:
        string get_fullname() {
            fullname = authorSurname + ", " + authorFirstname;
            return fullname;
        }
};

void bookshop::display_all_books() {
    int i = 1;
    cout << endl << "---------------------------------------" << endl;
    for (const auto & file : directory_iterator("books/")) { // iterate through all files in given directory
        cout << endl;
        cout << file.path() << endl; // Print full filename
        fstream newfile;
        newfile.open(file.path(), ios::in); // open filepath 
        if (newfile.is_open()) {
            string tp;
            cout << "Book: " << i << endl;
            while(getline(newfile, tp)) {
                cout << tp << "\n";
            }
            newfile.close();
        }
        cout << endl << "---------------------------------------" << endl;
        i++;
    }


    // return 0;
}

void bookshop::add_book(string title, string authorFirstname, string authorSurname, int copies) {    
    book book;
    book.authorSurname = authorSurname;
    book.authorFirstname = authorFirstname;
    book.title = title;
    book.copies = copies;

    string fileName = "books//" + book.get_fullname() + " - " + book.title + ".txt";
    string fileText = book.get_fullname() + "\n" + book.title + "\n" + to_string(book.copies);
  
    FILE *o_file = fopen(fileName.c_str(), "w+");
    if (o_file) {
        fwrite(fileText.c_str(), 1, fileText.size(), o_file);
    }
}

void bookshop::display_choices() {
    string bookshop_choices[] = {
        "Display all books",
        "Add a new book",
        "Update an existing book",
        "Delete an existing book",
        "Search for a book"
    };

    for (unsigned int i = 0; i < sizeof(bookshop_choices); i++) {
        cout << i << ": " << bookshop_choices[i] << endl;
    }
}

int main() {
    bookshop bookshop;
    string title;
    string firstname;
    string surname;
    int copies;

    int choice;
    cout << "Welcome to the bookshop!" << endl;        
    while (choice != 5) {
        cout << "What do you want to do?" << endl;        
        bookshop.display_choices();
        cin >> choice;

        switch (choice) {
            case 0: 
                bookshop.display_all_books();
                break;
            case 1: 
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
                cout << "case 2" << endl;
                break;
            case 3: 
                cout << "case 3" << endl;
                break;
            case 4: 
                cout << "case 4" << endl;
                break;
            case 5: 
                cout << "case 5" << endl;
                break;
            default:
                cout << "not a known option" << endl;
                break;
        }
    }
    cout << "Goodbye!" << endl;
}