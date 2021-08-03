#include <iostream>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Homework 7 - Problem 1/2

/*
declaration of the planet class
*/

class Planet
{
    public:
        Planet(); //constructor automatically called when program compiles
        Planet(string planetName, double planetRadius); //constructor automatically called when program compiles
        string getName();
        void setName(string nameInput);
        double getRadius();
        void setRadius (double radiusInput);
        double getVolume();

    private:
        string planetName;
        double planetRadius;
};