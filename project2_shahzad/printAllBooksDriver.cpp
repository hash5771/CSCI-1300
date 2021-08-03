#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Project 2 - Problem 3/11

/*
function prints the titles of books in an array of book objects
*/

void printAllBooks(Book books[], int numBooks)
{
    if (numBooks <= 0)
    {
        cout << "No books are stored" << endl;
    }
    else
    {
        cout << "Here is a list of books" << endl;
        for (int i = 0; i < numBooks; i++)
        {
            cout << books[i].getTitle() << " by " << books[i].getAuthor() << endl;
        }
    }
}

int main() //tests the printAllBooks function
{

}