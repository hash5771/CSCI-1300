#include <iostream>
#include <fstream>
#include <string>
#include "Book.h"
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Homework 7 - Problem 6

/*
creates a menu using the book class from problem 3 and functions from problems 4/5
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

int readBooks(string filename, Book books[], int numBooksStored, int booksArrSize)
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
                cout << "Database is full. Some books may have not been added." << endl;
                break;
            }
            if (lines != "")
            {
                split(lines, ',', booksArray, booksArrSize);
                authorArray[i] = booksArray[0];
                titleArray[i] = booksArray[1];
                genreArray[i] = booksArray[2];
                books[i] = Book(booksArray[0], booksArray[1], booksArray[2]);
                i++;
                totalBooks++;
            }
        }
        file.close();
        return totalBooks + numBooksStored;
    }
}

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

int main() //question for office hours: how do we loop the if (menuChoice == 1/2/3) statements?
{
    int menuChoice = 0;
    cout << "======Main Menu=====" << endl;
    cout << "1. Read books" << endl;
    cout << "2. Print all books" << endl;
    cout << "3. Quit" << endl;
    cin >> menuChoice;
    do
    {
        if (menuChoice == 1)
        {
            Book books[50];
            string filename;
            cout << "Enter a book file name:" << endl;
            cin >> filename;
            int numBooksStored = 0;
            int booksArrSize = 50;
            readBooks(filename, books, numBooksStored, booksArrSize);
            int newNumBooksStored = readBooks(filename, books, numBooksStored, booksArrSize);
            if (newNumBooksStored == -2)
            {
                cout << "Database is already full. No books were added." << endl;
            }
            else if (newNumBooksStored == -1)
            {
                cout << "No books saved to the database." << endl;
            }
            else
            {
                cout << "Total books in the database: " << newNumBooksStored << endl;
            }
            cout << "======Main Menu=====" << endl;
            cout << "1. Read books" << endl;
            cout << "2. Print all books" << endl;
            cout << "3. Quit" << endl;
            cin >> menuChoice;
            if (menuChoice == 1)
            {
                string filenametwo;
                cout << "Enter a book file name:" << endl;
                cin >> filenametwo;
                readBooks(filenametwo, books, newNumBooksStored, booksArrSize);
                int newNumBooksStoredtwo = readBooks(filenametwo, books, newNumBooksStored, booksArrSize);
                if (newNumBooksStoredtwo == -2)
                {
                    cout << "Database is already full. No books were added." << endl;
                }
                else if (newNumBooksStoredtwo == -1)
                {
                    cout << "No books saved to the database." << endl;
                }
                else
                {
                    cout << "Total books in the database: " << newNumBooksStoredtwo << endl;
                }
                cout << "======Main Menu=====" << endl;
                cout << "1. Read books" << endl;
                cout << "2. Print all books" << endl;
                cout << "3. Quit" << endl;
                cin >> menuChoice;
                if (menuChoice == 2)
                {
                    printAllBooks(books, newNumBooksStoredtwo);
                    cout << "======Main Menu=====" << endl;
                    cout << "1. Read books" << endl;
                    cout << "2. Print all books" << endl;
                    cout << "3. Quit" << endl;
                    cin >> menuChoice;
                }
            }
            else if (menuChoice == 2)
            {
                printAllBooks(books, newNumBooksStored);
                cout << "======Main Menu=====" << endl;
                cout << "1. Read books" << endl;
                cout << "2. Print all books" << endl;
                cout << "3. Quit" << endl;
                cin >> menuChoice;
            }
        }
        else if (menuChoice == 3)
        {
            break;
        }
        else
        {
            cout << "Invalid input." << endl;
            cout << "======Main Menu=====" << endl;
            cout << "1. Read books" << endl;
            cout << "2. Print all books" << endl;
            cout << "3. Quit" << endl;
            cin >> menuChoice;
        }

    } while (menuChoice != 3);
    cout << "Good bye!" << endl;
    return 0;
}