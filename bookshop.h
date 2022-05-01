#pragma once 

#include <iostream>
using namespace std;

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
