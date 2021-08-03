#include <iostream>
#include <cmath>
#include "Planet.h"
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Homework 7 - Problem 1/2

/*
implementation of the planet class
*/

Planet::Planet() //constructor automatically called when program compiles
        {
            planetName = "";
            planetRadius = 0.0;
        }
Planet::Planet(string planetName, double planetRadius) //constructor automatically called when program compiles
        {
            setName(planetName);
            setRadius(planetRadius);
        }
string Planet::getName()
        {
            return planetName;
        }
void Planet::setName(string nameInput)
        {
            planetName = nameInput;
        }
double Planet::getRadius()
        {
            return planetRadius;
        }
void Planet::setRadius (double radiusInput)
        {
            planetRadius = radiusInput;
        }
double Planet::getVolume()
        {
            double volume = 0.0;
            double four = 4.00;
            double three = 3.00;
            volume = (four/three) * (M_PI) * pow(planetRadius, 3);
            return volume;
        }