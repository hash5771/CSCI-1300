#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Project 1 - Problem 5

/*
This function takes two strings from the user, converts them into substrings and find the highest similarity score out of the substrings.
String parameters are genome and sequence.
double returns the score as a double (highest sim score).
*/

double findBestSimScore(string genome, string sequence)
{
    double lengthGenome = genome.length();
    double lengthSequence = sequence.length();
    double bestScore = 0;
    if (lengthGenome >= lengthSequence)
    {
        for (int i = 0; i < (lengthGenome - lengthSequence) + 1; i++)
        {
            double hammingDistance = 0;
            string subString = genome.substr(i, lengthSequence);
            for (int j = 0; j < lengthSequence; j++)
            {
                if (subString[j] != sequence[j])
                {
                    hammingDistance = hammingDistance + 1;
                }
                else
                {
                    hammingDistance = hammingDistance;
                }
            }
            double simScore = (lengthSequence - hammingDistance) / lengthSequence;
            if (simScore > bestScore)
            {
                bestScore = simScore;
            }
        }
        return bestScore;
    }
    else
    {
        return bestScore;
    }
}

int main()
{
    string genome;
    string sequence;
    cin >> genome;
    cin >> sequence;
    double bestScoreM;
    bestScoreM = findBestSimScore(genome, sequence);
    cout << bestScoreM << endl;
}