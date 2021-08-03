#include <iostream>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Project 1 - Problem 2

/*
This function takes a character and returns whether or not the character is a vowel.
Character parameter is input.
Bool function returns either 0 or 1 depending on character input.
*/

bool isVowel(char input)
{
    bool trueFalse;
    if (input == 'a' || input == 'e' || input == 'i' || input == 'o' || input == 'u' || input == 'A' || input == 'E' || input == 'I' || input == 'O' || input == 'U')
    {
        trueFalse = true;
        return true;
    }
    else
    {
        trueFalse = false;
        return false;
    }
}

int main ()
{
    char input;
    cin >> input;
    isVowel(input);
    cout << isVowel(input);
}