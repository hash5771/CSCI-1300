#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Homework 8 - Problem 4

/*
- this program takes user input (a positive integer) 
and converts it into binary, returning it as a string
- this program uses recursion to accomplish this task
*/

string decimalToBinaryRecursive(int number)
{
    string binary;
    if (number == 0 || number == 1) //base case
    {
        if (number == 0)
        {
            binary = "0";
            return binary;
        }
        else
        {
            binary = "1";
            return binary;
        }
    }
    else
    {
        if (number % 2 == 0)
        {
            binary = "0";
            return binary = decimalToBinaryRecursive(number / 2) + binary;
        }
        else if (number % 2 == 1)
        {
            binary = "1";
            return binary = decimalToBinaryRecursive(number / 2) + binary;
        }
    }
    return binary;
}

int main()
{
    cout << decimalToBinaryRecursive(10) << endl; // output should be 1010
}