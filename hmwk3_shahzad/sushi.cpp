#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 - Madhusudhan
// Homework 3 - Problem 3

int main() {
    cout << "Enter the number of sushi:" << endl;
    int sushi;
    cin >> sushi;
    double price;

    if (0 < sushi && sushi < 10)
    {
        price = sushi * 1.99;
        cout << fixed << setprecision(2) << "Total price: $" << price;
    }
    else if (10 <= sushi && sushi <= 19)
    {
        price = sushi * 1.99 * 0.90;
        cout << fixed << setprecision(2) << "Total price: $" << price;
    }
    else if (20 <= sushi && sushi <= 49)
    {
        price = sushi * 1.99 * 0.85;
        cout << fixed << setprecision(2) << "Total price: $" << price;
    }
    else if (50 <= sushi && sushi <= 99)
    {
        price = (sushi * 1.99 * 0.80);
        cout  << fixed << setprecision(2) << "Total price: $" << price;
    }
    else if (sushi >= 100)
    {
        price = (sushi * 1.99 * 0.75);
        cout << fixed << setprecision(2) << "Total price: $" << price;
    }
    else
    {
        cout << "Invalid input";
    }
}