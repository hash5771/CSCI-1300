#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Project 1 - Problem 3

/*
This function takes a string from the user and outputs the number of vowels in the string.
String parameter is input.
Int function returns number of vowels in string.
*/

int numVowels(string input)
{
    int vowelCounter = 0;
    for (int i = 0; i <= input.length(); i++)
    {
        if (input[i] == 'a' || input[i] == 'e' || input[i] == 'i' || input[i] == 'o' || input[i] == 'u' || input[i] == 'A' || input[i] == 'E' || input[i] == 'I' || input[i] == 'O' || input[i] == 'U')
        {
            vowelCounter = vowelCounter + 1;
        }
        else
        {
            vowelCounter = vowelCounter;
        }
    }
    return vowelCounter;
}
int main()
{
    string input;
    getline(cin, input);
    numVowels(input);
    cout << numVowels (input);
}