#include <iostream>
#include "User.h"
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Project 2 - Problem 6/7/8/9/10/11

User::User()
{
    username = "";
    numRatings = 0;
    for (int i = 0; i < size; i++)
    {
        ratings[i] = 0;
    }
}
User::User(string username, int ratings[], int numRatings)
{
    setUsername(username);
    setRatingAt(ratings[size], size);
    setNumRatings(numRatings);
}
string User::getUsername()
{
    return username;
}
void User::setUsername(string usernameInput)
{
    username = usernameInput;
}
int User::getRatingAt(int index)
{
    if (index >= size || index < 0)
    {
        return -1;
    }
    else
    {
        return ratings[index];
    }
}
bool User::setRatingAt(int index, int value)
{
    if (index >= 0 && index < size && value >= 0 && value <= 5)
    {
        ratings[index] = value;
        return true;
    }
    else
    {
        return false;
    }
}
int User::getNumRatings()
{
    return numRatings;
}
void User::setNumRatings(int numRatingsInput)
{
    numRatings = numRatingsInput;
}
int User::getSize()
{
    return size;
}