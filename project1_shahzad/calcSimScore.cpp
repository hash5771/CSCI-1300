#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Project 1 - Problem 4

/*
This function takes two string from the user and calculates the similarity score of those strings.
String parameters are sequenceOne and sequenceTwo.
double returns the score as a double (decimal value).
*/

double calcSimScore(string sequenceOne, string sequenceTwo)
{
    double lengthOne = sequenceOne.length();
    double lengthTwo = sequenceTwo.length();
    double hammingDistance = 0;
    double simScore = 0;
    if (sequenceOne == "" && sequenceTwo == "")
    {
        return 0;
    }
    if (lengthOne == lengthTwo)
    {
        for (int i = 0; i <= lengthOne; i++)
        {
            if (sequenceOne[i] != sequenceTwo[i])
            {
                hammingDistance = hammingDistance + 1;
            }
        }
        simScore = (lengthOne - hammingDistance) / lengthOne;
    }
    else
    {
        simScore = 0;
    }
    return simScore;
}

int main()
{
    string sequenceOne;
    string sequenceTwo;
    cin >> sequenceOne;
    cin >> sequenceTwo;
    calcSimScore(sequenceOne, sequenceTwo);
    cout << calcSimScore(sequenceOne, sequenceTwo);
}
