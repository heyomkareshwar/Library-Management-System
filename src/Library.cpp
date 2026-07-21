#include "../include/Library.h"
#include <fstream>
#include <sstream>

using namespace std;

void Library::addBook()
{
    Book newBook;
    newBook.inputBook();

    books.push_back(newBook);

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

void Library::loadBooks()
{
    ifstream file("data/books.txt");

    if (!file)
    {
        return;
    }

    string line;

    while (getline(file, line))
    {
        stringstream ss(line);

        string id, title, author, issued;

        getline(ss, id, '|');
        getline(ss, title, '|');
        getline(ss, author, '|');
        getline(ss, issued, '|');

        Book book;

        book.setId(stoi(id));
        book.setTitle(title);
        book.setAuthor(author);
        book.setIssued(stoi(issued));

        books.push_back(book);
    }

    file.close();
}