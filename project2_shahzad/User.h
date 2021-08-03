#include <iostream>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Project 2 - Problem 6/7/8/9/10/11

class User
{
    public:
    User();
    User(string username, int ratings[], int numRatings);
    string getUsername();
    void setUsername(string usernameInput);
    int getRatingAt(int index);
    bool setRatingAt(int index, int value);
    int getNumRatings();
    void setNumRatings(int numRatingsInput);
    int getSize();

    private:
    string username;
    static const int size = 50;
    int ratings[size];
    int numRatings;
};