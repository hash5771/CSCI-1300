#include <iostream>
#include <iomanip>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 - Madhusudhan
// Homework 3 - Problem 1

int main() {
    cout << "Enter practicum 1 score:" << endl;
    int practicumone;
    cin >> practicumone;
    cout << "Enter practicum 2 score:" << endl;
    int practicumtwo;
    cin >> practicumtwo;
    cout << "Enter practicum 3 score:" << endl;
    int practicumthree;
    cin >> practicumthree;
    double practicumtotal = practicumone + practicumtwo + practicumthree;
    double total = practicumtotal / 3;
    cout << "Practicum average: " << fixed << setprecision(2) << total << endl;
    if (total >= 67)
    {
        cout << "You have a passing practicum average.";
    }
    else
    {
        cout << "You can retake practicums during the final.";
    }
}