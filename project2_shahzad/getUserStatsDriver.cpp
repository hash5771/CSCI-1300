#include <iostream>
#include <iomanip>
#include "User.h"
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Project 2 - Problem 10/11

int getUserStats(string username, User users[], int numUsers, int numBooks)
{
    for (int i = 0; i < numUsers; i++)
    {
        if (users[i].getUsername() == username)
        {
            if (users[i].getNumRatings() == 0)
            {
                cout << username << " has not rated any books." << endl;
                return 0;
            }
            double average = 0.00;
            int count = 0;
            for (int j = 0; j < numBooks; j++)
            {
                if (users[i].getRatingAt(j) == 0)
                {
                    average = average;
                }
                else
                {
                    average += users[i].getRatingAt(j);
                    users[i].setNumRatings(j);
                    count++;
                }
            }
            cout << username << " rated " << count << " books" << endl;
            average = average / count;
            cout << username << "'s average rating was " << fixed << setprecision(2) << average << endl;
            return 1;
        }
    }
    cout << username << " does not exist." << endl;
    return -3;
}