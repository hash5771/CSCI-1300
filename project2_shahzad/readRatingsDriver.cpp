#include <iostream>
#include <fstream>
#include <string>
#include "User.h"
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Project 2 - Problem 7/11

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

int readRatings(string filename, User users[], int numUsersStored, int usersArrSize, int maxCol)
{
    users[usersArrSize];
    if (numUsersStored >= usersArrSize)
    {
        return -2;
    }
    ifstream file;
    file.open(filename);
    if (!file.is_open())
    {
        return -1;
    }

    string lines = "";
    while (getline(file, lines))
    {
        if (numUsersStored >= usersArrSize)
        {
            break;
        }
        else if (lines == "")
        {
            numUsersStored = numUsersStored;
        }
        else
        {
            string storage[100];
            int count = split(lines, ',', storage, 100);
            int j = 1;
            users[numUsersStored].setUsername(storage[0]);
            for (int i = 0; i < count-1; i++)
            {
                users[numUsersStored].setRatingAt(i, stoi(storage[j]));
                j++;
            }
            numUsersStored++;
        }
    }
    file.close();
    return numUsersStored;
}