#include <iostream>
#include <string>
#include "Book.h"
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Project 2 - Problem 5/11

int printAuthorGenre(string genre, char authorFirstLetter, Book books[], int numBooksStored)
{
    int count = 0;
    int j = 0;
    string matchTitle[numBooksStored];
    string matchAuthor[numBooksStored];
    for (int i = 0; i < numBooksStored; i++)
    {
        if (books[i].getGenre() == genre) //checks to see if genre matches
        {
            string author = books[i].getAuthor();
            author.at(0);
            if (author.at(0) == authorFirstLetter) //checks to see how many authors match
            {
                matchTitle[j] = books[i].getTitle();
                matchAuthor[j] = books[i].getAuthor();
                j++;
                count++;
            }
        }
    }
    if (count == 0)
    {
        cout << "No titles found for this genre-author pair." << endl;
    }
    else if (count > 0)
    {
        cout << "Here is a list of books that match this genre-author pair:" << endl;
        for (int k = 0; k < count; k++)
        {
            cout << matchTitle[k] << " by " << matchAuthor[k] << endl;
        }
    }
    return count;
}

int main() //tests printAuthorGenre function
{

}