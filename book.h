#pragma once 

#include <iostream>

#include "bookshop.h"

using namespace std;

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