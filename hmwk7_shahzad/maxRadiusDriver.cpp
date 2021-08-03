#include <iostream>
#include <iomanip>
#include "Planet.h"
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Homework 7 - Problem 2

/*
function returns index of planet with largest radius
*/

int maxRadius(Planet planetArray[], int sizeArray) //returns index of planet with largest radius in an array
{
    double largestRadius = 0.00;
    int largestIndex = 0;
    if (sizeArray == 0) //returns -1 if the size of the array is 0
    {
        return -1;
    }
    else
    {
        for (int i = 0; i < sizeArray; i++) //goes through all index's of the array and grab the largest radius
        {
            if (planetArray[i].getRadius() > largestRadius)
            {
                largestRadius = planetArray[i].getRadius();
                largestIndex = i;
            }
        }
        return largestIndex; //returns index of largest radius
    }
}

int main() //tests the maxRadius function
{
    Planet planetArray[2];
    planetArray[0] = Planet("On a Cob Planet", 1234);
    planetArray[1] = Planet("Bird World", 4321);
    maxRadius(planetArray, 2);
}