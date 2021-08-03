#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Homework 8 - Problem 3

/*
- this program takes user input (a positive integer) 
and converts it into binary, returning it as a string
- this program uses loops to accomplish this task
*/

string decimalToBinaryIterative(int number)
{
    string binary;
    int places = 0;
    do
    {
        places++;
    } while (number >= pow(2, places));

    do
    {
        if (number >= pow(2, places - 1))
        {
            binary += "1";
            number = number - pow(2, places - 1);
            places--;
        }
        else if (number < pow(2, places - 1))
        {
            binary += "0";
            places--;
        }
    } while (places > 0);
    return binary;
}

int main()
{
    cout << decimalToBinaryIterative(10) << endl;
}