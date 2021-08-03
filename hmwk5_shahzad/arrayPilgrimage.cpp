#include <iostream>
#include <string>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Homework 5 - Problem 1

/*

*/

void arraytemps(double temps[], int sizetemps)
{
    for (int i = 0; i < 10; i++)
    {
        temps[i] = 0;
        temps[i] = -459.67;
        cout << temps[i] << endl;
    }
    cout << endl;
    return;
}

void arraycolors(string colors[], int sizecolors)
{
    for (int j = 0; j < 5; j++)
    {
        cout << colors[j] << endl;
    }
    cout << endl;
    return;
}

void arraysequence(int sequence[], int sizesequence)
{
    for (int k = 0; k < 100; k++)
    {
        sequence[k] = 0;
        sequence[k] = k + 1;
        cout << sequence[k] << endl;
    }
    cout << endl;
    return;
}

void arrayletters(char letters[], char lowerCaseLetters[], int sizeletters)
{
    for (int l = 0; l < 26; l++)
    {
        letters[l] = 65;
        letters[l] = l + 65;
        lowerCaseLetters[l] = 97;
        lowerCaseLetters[l] = l + 97;
        cout << letters[l] << " " << lowerCaseLetters[l] << endl;
    }
    cout << endl;
    return;
}

int main()
{
    double temps[10] = {};
    arraytemps(temps, 10);

    string colors[] = {"Red", "Blue", "Green", "Cyan", "Magenta"};
    arraycolors(colors, 5);

    int sequence[100] = {};
    arraysequence(sequence, 100);

    char letters[26] = {};
    char lowerCaseLetters[26] = {};
    int sizeletters = 52;
    arrayletters(letters, lowerCaseLetters, 52);
}