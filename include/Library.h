#ifndef LIBRARY_H
#define LIBRARY_H

#include <vector>
#include "Book.h"

using namespace std;

class Library
{
private:
    vector<Book> books;

public:
    void addBook();
    void viewBooks();
};

#endif