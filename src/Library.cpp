#include "../include/Library.h"
#include <fstream> // <-- upar add karo

void Library::addBook()
{
    Book newBook;
    newBook.inputBook();

    books.push_back(newBook);

    // Step 3 - Save book to file
    ofstream file("data/books.txt", ios::app);

    file << newBook.getId() << "|"
         << newBook.getTitle() << "|"
         << newBook.getAuthor() << "|"
         << newBook.isIssued() << endl;

    file.close();

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