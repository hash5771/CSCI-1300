#include <iostream>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 - Madhusudhan
// Homework 4 - Problem 2

int main()
{
    int userInput;
    cout << "Enter a positive number: " << endl;
    cin >> userInput;
    int sum = userInput;
    for (int i = 0; sum != 1; i++)
    {
        cout << sum << endl;
        if (sum % 2)
        {
            sum = (sum * 3) + 1;
        }
        else
        {
            sum = sum / 2;
        }
    }
    cout << sum << endl;
}