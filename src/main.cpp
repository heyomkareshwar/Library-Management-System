#include <iostream>
#include "../include/Book.h"

using namespace std;

int main()
{
    Book b1;

    b1.inputBook();

    cout << "\nBook Details\n";
    b1.displayBook();

    return 0;
}