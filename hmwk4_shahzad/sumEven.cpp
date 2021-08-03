#include <iostream>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 - Madhusudhan
// Homework 4 - Problem 1

int main()
{
    int posNumber;
    cout << "Enter a positive number:" << endl;
    cin >> posNumber;
    int sumEven = 0;
    for (int i = 2; i <= posNumber; i = i + 2)
    {
        sumEven = sumEven + i;
    }
    cout << "Sum: " << sumEven << endl;
}