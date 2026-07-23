#include <iostream>
#include "../include/Library.h"

using namespace std;

int main()
{
    Library library;

    library.loadBooks();
    int choice;

    while (true)
    {
        // Menu print

        cout << "1. Add Book\n";
        cout << "2. View Books\n";
        cout << "3. Search Book\n";
        cout << "4. Update Book\n";
        cout << "5. Delete Book\n";
        cout << "6. Issue Book\n";
        cout << "7. Return Book\n";
        cout << "8. Exit\n";

        cout << "\nEnter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            library.addBook();
            break;

        case 2:
            library.viewBooks();
            break;
        case 3:
            library.searchBook();
            break;
        case 4:
            library.updateBook();
            break;
        case 5:
            library.deleteBook();
            break;
        case 6:
            library.issueBook();
            break;

        case 8:
            cout << "Thank you!\n";
            return 0;

        default:
            cout << "Invalid Choice\n";
        }
    }
}