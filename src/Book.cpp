#include "../include/Book.h"

Book::Book()
{
    id = 0;
    title = "";
    author = "";
    issued = false;
}

void Book::inputBook()
{
    cout << "Enter book ID: ";
    cin >> id;
    cin.ignore();

    cout << "Enter book title: ";
    getline(cin, title);

    cout << "Enter book author: ";
    getline(cin, author);

    issued = false;
}

void Book::displayBook() const
{
    cout << "Book ID: " << id << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Status: " << (issued ? "Issued" : "Available") << endl;
}

int Book::getId() const
{
    return id;
}

string Book::getTitle() const
{
    return title;
}

string Book::getAuthor() const
{
    return author;
}

bool Book::isIssued() const
{
    return issued;
}

void Book::setId(int id)
{
    this->id = id;
}

void Book::setTitle(string title)
{
    this->title = title;
}

void Book::setAuthor(string author)
{
    this->author = author;
}

void Book::setIssued(bool issued)
{
    this->issued = issued;
}

void Book::issueBook()
{
    issued = true;
}

void Book::returnBook()
{
    issued = false;
}