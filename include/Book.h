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
    string getTitle() const;
    string getAuthor() const;

    void setId(int id);
    void setTitle(string title);
    void setAuthor(string author);
    void setIssued(bool issued);

    Book();

    void inputBook();
    void displayBook() const;

    int getId() const;
    bool isIssued() const;

    void issueBook();
    void returnBook();
};

#endif // BOOK_H