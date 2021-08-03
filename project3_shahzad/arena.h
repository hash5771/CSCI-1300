#include <iostream>
#include <stdlib.h>
#include <ctime>
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

class Arena
{
public:
    Arena();
    Arena(int days);
    string getArena();
    void setDays(int days);
    int getDays();
    int getYear();

private:
    string arena[5] = {"Jungle", "Desert", "Ocean", "Mountain", "Tundra"};
    string currentArena;
    int days;
    int year;
};