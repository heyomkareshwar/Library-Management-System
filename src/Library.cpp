#include "../include/Library.h"

void Library::addBook()
{
    Book newBook;
    newBook.inputBook();

    books.push_back(newBook);

    cout << "\nBook Added Successfully!\n";
}

void Library::viewBooks()
{
    if (books.empty())
    {
        cout << "\nNo books available.\n";
        return;
    }

    for (const Book &book : books)
    {
        book.displayBook();
        cout << "------------------------\n";
    }
}