#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 - Madhusudhan
// Homework 3 - Problem 4

int main() {
    cout << "Enter boxers' weights" << endl;
    int one;
    int two;
    int three;
    cin >> one;
    cin >> two;
    cin >> three;
    if (one > two && one > three && two > three)
    {
        cout << "Descending order";
    }
    else if (three > one && three > two && two > one)
    {
        cout << "Ascending order";
    }
    else
    {
        cout << "Neither";
    }
}