#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
#include <cstdio>
#include "Book.h"
#include "User.h"
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Project 2 - Problem 8/11

string lowercase(string name)
{
    string lowerCaseString = name;
    for (int a = 0; a < name.length(); a++)
    {
        if (name[a] >= 'A' && name[a] <= 'Z')
        {
            lowerCaseString[a] = name[a] + 32;
        }
    }
    return lowerCaseString;
}

int getRating(string username, string bookTitle, User users[], Book books[], int numUsers, int numBooks)
{
    for (int i = 0; i < numUsers; i++)
    {
        if (lowercase(users[i].getUsername()) == lowercase(username))
        {
            for (int j = 0; j < numBooks; j++)
            {
                if (lowercase(books[j].getTitle()) == lowercase(bookTitle))
                {
                    return users[i].getRatingAt(j);
                }
            }
        }
    }
    return -3;
}