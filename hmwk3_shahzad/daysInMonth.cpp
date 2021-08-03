#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 - Madhusudhan
// Homework 3 - Problem 5

int main() {
    int year;
    cout << "Enter a year:" << endl;
    cin >> year;
    int month;
    cout << "Enter a month:" << endl;
    cin >> month;
    switch (month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            cout << "31 days";
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            cout << "30 days";
            break;
        case 2:
            if (year < 1582 && year % 4 == 0)
            {
                cout << "29 days";
            }
            else if (year > 1582 && year % 100 == 0)
            {
                if (year % 400 == 0)
                {
                    cout << "29 days";
                }
                else
                {
                    cout << "28 days";
                }
            }
            else if (year > 1582 && year % 4 == 0)
            {
                cout << "29 days";
            }
            else
            {
                cout << "28 days";
            }
            break;
        default:
            cout << "Invalid month";
            break;
    }
}