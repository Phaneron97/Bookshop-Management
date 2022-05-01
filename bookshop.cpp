#include <iostream> // read/write from console
#include <fstream> // File handling
#include <filesystem>

#include "bookshop.h"
#include "book.h"

using filesystem::directory_iterator;
using namespace std;

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
    new_file.open("books/" + bookName, ios::in); // open file to perform read operation
    if (new_file.is_open()) {
        string tp;
        while(getline(new_file, tp)) {
            cout << tp << "\n";
        }
        new_file.close();
    }
    else {
        cout << "File doesn't exist" << endl;
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