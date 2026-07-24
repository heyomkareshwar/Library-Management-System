#include "../include/Library.h"
#include <fstream>
#include <sstream>
#include <cstdio>

using namespace std;

void Library::addBook()
{
    Book newBook;

    int id;

    while (true)
    {
        cout << "Enter Book ID: ";
        cin >> id;

        if (!isBookIdExists(id))
            break;

        cout << "\nBook ID already exists! Please enter another ID.\n\n";
    }

    cin.ignore();

    string title, author;

    cout << "Enter Book Title: ";
    getline(cin, title);

    cout << "Enter Author Name: ";
    getline(cin, author);

    newBook.setId(id);
    newBook.setTitle(title);
    newBook.setAuthor(author);
    newBook.setIssued(false);

    books.push_back(newBook);

    saveBooks();

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
bool Library::isBookIdExists(int id)
{
    for (const Book &book : books)
    {
        if (book.getId() == id)
        {
            return true;
        }
    }

    return false;
}
void Library::saveBooks()
{
    ofstream file("data/books.txt");

    for (const Book &book : books)
    {
        file << book.getId() << "|"
             << book.getTitle() << "|"
             << book.getAuthor() << "|"
             << book.isIssued() << endl;
    }

    file.close();
}

void Library::searchBook()
{
    int searchId;

    cout << "\nEnter Book ID to search: ";
    cin >> searchId;

    bool found = false;

    for (const Book &book : books)
    {
        if (book.getId() == searchId)
        {
            cout << "\nBook Found\n\n";
            book.displayBook();

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nBook not found!\n";
    }
}
void Library::searchBookByTitle()
{
    string searchTitle;

    cin.ignore();

    cout << "\nEnter Book Title: ";
    getline(cin, searchTitle);

    bool found = false;

    for (const Book &book : books)
    {
        if (book.getTitle().find(searchTitle) != string::npos)
        {
            if (!found)
            {
                cout << "\nMatching Books:\n\n";
            }

            book.displayBook();
            cout << "------------------------\n";

            found = true;
        }
    }

    if (!found)
    {
        cout << "\nNo book found with this title!\n";
    }
}

void Library::deleteBook()
{
    int deleteId;

    cout << "\nEnter Book ID to delete: ";
    cin >> deleteId;

    bool found = false;

    for (auto it = books.begin(); it != books.end(); it++)
    {
        if (it->getId() == deleteId)
        {
            books.erase(it);
            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nBook not found!\n";
        return;
    }

    saveBooks();
    cout << "\nBook deleted successfully!\n";
}
void Library::updateBook()
{
    int updateId;

    cout << "\nEnter Book ID to update: ";
    cin >> updateId;

    bool found = false;

    for (Book &book : books)
    {
        if (book.getId() == updateId)
        {
            string title, author;

            cin.ignore();

            cout << "Enter New Title: ";
            getline(cin, title);

            cout << "Enter New Author: ";
            getline(cin, author);

            book.setTitle(title);
            book.setAuthor(author);

            found = true;
            break;
        }
    }

    if (!found)
    {
        cout << "\nBook not found!\n";
        return;
    }

    saveBooks();

    cout << "\nBook updated successfully!\n";
}
void Library::issueBook()
{
    int issueId;

    cout << "\nEnter Book ID to issue: ";
    cin >> issueId;

    bool found = false;

    for (Book &book : books)
    {
        if (book.getId() == issueId)
        {
            found = true;

            if (book.isIssued())
            {
                cout << "\nBook is already issued!\n";
                return;
            }

            book.issueBook();
            break;
        }
    }

    if (!found)
    {
        cout << "\nBook not found!\n";
        return;
    }

    saveBooks();

    cout << "\nBook issued successfully!\n";
}
void Library::returnBook()
{
    int returnId;

    cout << "\nEnter Book ID to return: ";
    cin >> returnId;

    bool found = false;

    for (Book &book : books)
    {
        if (book.getId() == returnId)
        {
            found = true;

            if (!book.isIssued())
            {
                cout << "\nBook is already available!\n";
                return;
            }

            book.returnBook();
            break;
        }
    }

    if (!found)
    {
        cout << "\nBook not found!\n";
        return;
    }

    saveBooks();

    cout << "\nBook returned successfully!\n";
}
void Library::showDashboard()
{
    int totalBooks = books.size();
    int issuedBooks = 0;
    int availableBooks = 0;

    for (const Book &book : books)
    {
        if (book.isIssued())
            issuedBooks++;
        else
            availableBooks++;
    }

    cout << "\n=====================================\n";
    cout << "        LIBRARY DASHBOARD\n";
    cout << "=====================================\n";
    cout << "Total Books      : " << totalBooks << endl;
    cout << "Available Books  : " << availableBooks << endl;
    cout << "Issued Books     : " << issuedBooks << endl;
    cout << "=====================================\n";
}