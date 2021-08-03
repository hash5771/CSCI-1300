#include <iostream>
#include <iomanip>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 - Madhusudhan
// Homework 2 - Problem 2

int main() {
    cout << "Enter a temperature in Fahrenheit: " << endl;
    double temperaturef;
    cin >> temperaturef;
    double equation = (temperaturef - 32) * 5 / 9;
    cout << "The temperature " << temperaturef << " degrees Fahrenheit is " << fixed << setprecision(2) << equation << " degrees Celsius.";
    return 0;
}