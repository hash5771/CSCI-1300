#include <iostream>
#include "Book.h"
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Project 2 - Problem 4/11

int countGenre (string genre, Book books[], int numBooksStored)
{
    int count = 0;
    for (int i = 0; i < numBooksStored; i++)
    {
        if (books[i].getGenre() == genre)
        {
            count++;
        }
    }
    return count;
}

int main() //tests countGenre function
{
    int numBooksStored = 0;
    int booksArrSize = 50;
    Book books[booksArrSize];
    countGenre("fileName.txt", books, 0);
}