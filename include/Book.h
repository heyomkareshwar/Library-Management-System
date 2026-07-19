#ifndef BOOK_H
#define BOOK_H

#include <string>
#include <iostream>

using namespace std;

class Book
{
private:
    int id;
    string title;
    string author;
    bool issued;

public:
    Book();

    void inputBook();
    void displayBook() const;

    int getId() const;
    bool isIssued() const;

    void issueBook();
    void returnBook();
};
#endif // BOOK_H