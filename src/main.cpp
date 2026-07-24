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
        cout << "3. Search Book by ID\n";
        cout << "4. Search Book by Title\n";
        cout << "5. Update Book\n";
        cout << "6. Delete Book\n";
        cout << "7. Issue Book\n";
        cout << "8. Return Book\n";
        cout << "9. Dashboard\n";
        cout << "10. Exit\n";
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
            library.searchBookByTitle();
            break;

        case 5:
            library.updateBook();
            break;

        case 6:
            library.deleteBook();
            break;

        case 7:
            library.issueBook();
            break;

        case 8:
            library.returnBook();
            break;

        case 9:
            library.showDashboard();
            break;

        case 10:
            cout << "Thank you!\n";
            return 0;

        default:
            cout << "Invalid Choice\n";
        }
    }
}