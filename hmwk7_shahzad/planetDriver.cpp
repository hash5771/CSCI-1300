#include <iostream>
#include "Planet.h"
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Homework 7 - Problem 1

/*
test file for planet class
*/

int main () //code was provided in a separate file
{
    string name = "Magrathea";
    double radius = 42, newRadius = 20;
    Planet p6 = Planet(name, radius);
    cout << "Planet Name: " << p6.getName() << endl;
    cout << "Planet Radius: " << p6.getRadius() << endl;
    cout << "Planet Volume: " << p6.getVolume() << endl;
    p6.setName("Jupiter");
    p6.setRadius(newRadius);
    cout << "Planet Name: " << p6.getName() << endl;
    cout << "Planet Radius: " << p6.getRadius() << endl;
    cout << "Planet Volume: " << p6.getVolume() << endl;
}