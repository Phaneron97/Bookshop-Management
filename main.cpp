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
        void search_book(string bookName);
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
}

void bookshop::search_book(string bookName) {
    bookName = bookName + ".txt";
    fstream new_file;
    new_file.open(bookName, ios::in); // open file to perform read operation
    if (new_file.is_open()) {
        string tp;
        while(getline(new_file, tp)) {
            cout << tp << "\n";
        }
        new_file.close();
    }
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
        fwrite(fileText.c_str(), 1, fileText.size(), o_file); // Write in file
        fclose(o_file); // Properly close file
    }
}

void bookshop::display_choices() {
    string bookshop_choices[5] = {
        "Display all books",
        "Add a new book",
        "Search a book",
        "Update an existing book",
        "Delete an existing book",
    };

    for (unsigned int i = 0; i < 5; i++) {
        cout << i << ": " << bookshop_choices[i] << endl;
    }
}

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
        // cout << "cin clear" << endl;
        // cin.clear();
        // cout << "cin ignore" << endl;
        // cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        // cout << "input choice" << endl;
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
    } while(choice != 5);
    cout << "Goodbye!" << endl;
    // return 0;

    // int choice;

    // do {
    //     cout << "choice: ";
    //     cin >> choice;
    // } while (choice != 5);
}