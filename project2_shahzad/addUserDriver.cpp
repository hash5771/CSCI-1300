#include <iostream>
#include <string>
#include <cctype>
#include "User.h"
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Project 2 - Problem 9/11

int addUser(string username, User users[], int numRatings, int numUsersStored, int usersArrSize)
{
    if (numUsersStored >= usersArrSize) // compares the amount of elements in the array to the size of the array
    {
        return -2;
    }
    for (int i = 0; i < numUsersStored; i++) // goes through all of the elements in the array to check if the username exists
    {
        if (users[i].getUsername() == username || username == "")
        {
            return -1;
        }
    }
    for (int j = 0; j < usersArrSize; j++) // sets the rating at each element in the array to 0
    {
        users[j].setRatingAt(0, 0);
    }
    users[numUsersStored].setUsername(username); // sets the username in the array
    numUsersStored++;
    return numUsersStored;
}