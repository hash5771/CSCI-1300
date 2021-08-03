#include <iostream>
#include <stdlib.h>
#include <ctime>
#include "arena.h"
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Project 3

/*
this class will control the arena in numerous ways including:
- setting the arena environment at random every time the program compiles
- returning the arena environment
- setting the number of "days" that have passed in the arena
- returning the number of "days" that have passed in the arena
*/

Arena::Arena() // constructor initializes data members and sets random variables
{
    arena[5];
    srand(time(NULL));
    currentArena = arena[rand() % 5];
    days = 0;
    srand(time(NULL));
    year = rand() % 100 + 1;
}
Arena::Arena(int days) // parametized constructor sets necessary data members
{
    setDays(days);
}
string Arena::getArena() // returns the arena environment
{
    return currentArena;
}
void Arena::setDays(int daysInput) // records the number of days (will impact playerStats)
{
    days = daysInput;
}
int Arena::getDays() // returns the current number of days
{
    return days;
}
int Arena::getYear() // returns the year
{
    return year;
}