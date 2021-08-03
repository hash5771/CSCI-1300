#include <iostream>
#include <cmath>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 - Madhusudhan
// Homework 2 - Problem 2

int main() {
    cout << "How fast are you running (in mph): " << endl;
    int input;
    cin >> input;
    if (input >= 7)
    {
        cout << "Enjoy some hip-hop music!" << endl;
        return 0;
    }
    if (input < 5)
    {
        cout << "Enjoy some smooth jazz!" << endl;
        return 0;
    }
    if (5 <= input || input < 7)
    {
        cout << "Enjoy some pop music!" << endl;
    }
}