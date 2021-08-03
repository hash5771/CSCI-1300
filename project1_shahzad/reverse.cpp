#include <iostream>
#include <string>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Project 1 - Problem 1

/*
This function takes a string and outputs the reverse of that string.
String parameter is string phrase.
void function does not return value.
*/

void reverse (string phrase)
{
    for (int i = phrase.length() - 1; i >= 0; i--)
    {
        cout << phrase[i];
    }
}

int main ()
{
    string phrase;
    getline(cin, phrase);
    reverse(phrase);
}