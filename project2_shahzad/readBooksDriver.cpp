#include <iostream>
#include <string>
#include <fstream>
#include "Book.h"
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Project 2 - Problem 2/11

/*
function returns number of books in a book array from a file, utilizing the split function
*/
int split(string phrase, char del, string words[], int size)
{
    if (phrase.length() == 0)
    {
        return 0;
    }

    string piece = "";
    int arrpos = 0;

    for (int pos = 0; pos < phrase.length(); pos++)
    {
        if (phrase[pos] != del)
        {
            piece = piece + phrase[pos];
        }
        else
        {
            if (pos != 0 && pos != (phrase.length() - 1))
            {
                words[arrpos] = piece;
                piece = "";
                arrpos++;

                int check = pos + 1;
                if (phrase[check] == del)
                {
                    pos++;
                }
            }
            else
            {
                if (pos == (phrase.length() - 1))
                {
                    pos++;
                }
            }
        }
    }
    words[arrpos] = piece;

    int count = arrpos + 1;
    if (count > size)
    {
        return -1;
    }
    return count;
}

int readBooks(string filename, Book books[], int numBooksStored, int booksArrSize) //returns number of books in a book array
{
    books[booksArrSize];
    if (numBooksStored == booksArrSize) // returns -2 if the array is filled
    {
        return -2;
    }
    ifstream file;
    file.open(filename);
    int totalBooks = 0;

    if (!file.is_open()) // returns -1 if the file did not open successfully
    {
        return -1;
    }
    else // fills the array with information
    {
        string lines = "";
        string booksArray[booksArrSize * 3];
        string authorArray[booksArrSize];
        string titleArray[booksArrSize];
        string genreArray[booksArrSize];
        int totalBooks = 0;
        int i = numBooksStored;
        while (getline(file, lines))
        {
            if (i >= booksArrSize)
            {
                break;
            }
            if (lines != "")
            {
                split(lines, ',', booksArray, booksArrSize);
                titleArray[i] = booksArray[1];
                authorArray[i] = booksArray[0];
                genreArray[i] = booksArray[2];
                books[i] = Book(booksArray[1], booksArray[0], booksArray[2]);
                i++;
                totalBooks++;
            }
        }
        file.close();
        return totalBooks + numBooksStored;
    }
}

int main()
{
    Book books[50];
    readBooks("readBooks.txt", books, 0, 1);
    cout << books[0].getAuthor() << endl
         << books[1].getAuthor() << endl
         << books[2].getAuthor() << endl;
}