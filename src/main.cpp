#include <iostream>
using namespace std;
int main()
{

    int choice;

    cout << "================================" << endl;
    cout << "Library Management System" << endl;
    cout << "================================" << endl;

    cout << "1. Add Book" << endl;
    cout << "2. View Books" << endl;
    cout << "3. Search Books" << endl;
    cout << "4. Update Book" << endl;
    cout << "5. Delete Book" << endl;
    cout << "6. Issue Book" << endl;
    cout << "7. Return Book" << endl;
    cout << "8. Exit\n"
         << endl;

    cout << "Enter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\nYou selected 'Add Book'." << endl;
        // Add Book functionality
        break;
    case 2:
        cout << "\nYou selected 'View Books'." << endl;
        // View Books functionality
        break;
    case 3:
        cout << "\nYou selected 'Search Books'." << endl;
        // Search Books functionality
        break;
    case 4:
        cout << "\nYou selected 'Update Book'." << endl;
        // Update Book functionality
        break;
    case 5:
        cout << "\nYou selected 'Delete Book'." << endl;
        // Delete Book functionality
        break;
    case 6:
        cout << "\nYou selected 'Issue Book'." << endl;
        // Issue Book functionality
        break;
    case 7:
        cout << "\nYou selected 'Return Book'." << endl;
        // Return Book functionality
        break;
    case 8:
        cout << "Thank you for using the Library Management System!" << endl;
        break;
    default:
        cout << "Invalid choice. Please try again." << endl;
    }
    return 0;
}