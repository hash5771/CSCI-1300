#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 - Madhusudhan
// Homework 2 - Problem 2

int main() {
    cout << "Enter a radius: " << endl;
    double radius;
    cin >> radius;
    double volume;
    double surfacearea;
    volume = (4 * M_PI * pow(radius, 3)) / 3;
    surfacearea = 4 * M_PI * pow(radius, 2);
    cout << fixed << setprecision(3);
    cout << "Volume: " << volume << endl; 
    cout << "Surface area: " << surfacearea;
    return 0;
}
