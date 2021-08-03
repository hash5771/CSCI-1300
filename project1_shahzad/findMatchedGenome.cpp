#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Project 1 - Problem 6

/*
This function takes four strings from the user, converts each of the three genome strings into substrings, and finds the one with the best sim score in relation to the entered sequence.
String parameters are genomeOne, genomeTwo, genomeThree, and sequence.
void function does not return a value.
*/

void findMatchedGenome(string genomeOne, string genomeTwo, string genomeThree, string sequence)
{
    double lengthOne = genomeOne.length();
    double lengthTwo = genomeTwo.length();
    double lengthThree = genomeThree.length();
    double lengthSequence = sequence.length();
    double bestScoreOne = 0;
    double bestScoreTwo = 0;
    double bestScoreThree = 0;
    if (genomeOne == "" || genomeTwo == "" || genomeThree == "" || sequence == "")
    {
        cout << "Genomes or sequence is empty." << endl;
    }
    else if (lengthOne == lengthTwo && lengthTwo == lengthThree && lengthOne == lengthThree && lengthOne >= lengthSequence)
    {
        for (int i = 0; i < (lengthOne - lengthSequence) + 1; i++)
        {
            double hammingDistanceOne = 0;
            string subStringOne = genomeOne.substr(i, lengthSequence);
            for (int a = 0; a < lengthSequence; a++)
            {
                if (subStringOne[a] != sequence[a])
                {
                    hammingDistanceOne = hammingDistanceOne + 1;
                }
            }
            double scoreOne = (lengthSequence - hammingDistanceOne) / lengthSequence;
            if (scoreOne > bestScoreOne)
            {
                bestScoreOne = scoreOne;
            }
        }
        for (int i = 0; i < (lengthOne - lengthSequence) + 1; i++)
        {
            double hammingDistanceTwo = 0;
            string subStringTwo = genomeTwo.substr(i, lengthSequence);
            for (int b = 0; b < lengthSequence; b++)
            {
                if (subStringTwo[b] != sequence[b])
                {
                    hammingDistanceTwo = hammingDistanceTwo + 1;
                }
            }
            double scoreTwo = (lengthSequence - hammingDistanceTwo) / lengthSequence;
            if (scoreTwo > bestScoreTwo)
            {
                bestScoreTwo = scoreTwo;
            }
        }

        for (int i = 0; i < (lengthOne - lengthSequence) + 1; i++)
        {
            double hammingDistanceThree = 0;
            string subStringThree = genomeThree.substr(i, lengthSequence);
            for (int c = 0; c < lengthSequence; c++)
            {
                if (subStringThree[c] != sequence[c])
                {
                    hammingDistanceThree = hammingDistanceThree + 1;
                }
            }
            double scoreThree = (lengthSequence - hammingDistanceThree) / lengthSequence;
            if (scoreThree > bestScoreThree)
            {
                bestScoreThree = scoreThree;
            }
        }
        if (bestScoreOne > bestScoreTwo && bestScoreOne > bestScoreThree)
        {
            cout << "Genome 1 is the best match." << endl;
        }
        else if (bestScoreTwo > bestScoreOne && bestScoreTwo > bestScoreThree)
        {
            cout << "Genome 2 is the best match." << endl;
        }
        else if (bestScoreThree > bestScoreOne && bestScoreThree > bestScoreTwo)
        {
            cout << "Genome 3 is the best match." << endl;
        }
        else if (bestScoreOne == bestScoreTwo && bestScoreOne > bestScoreThree)
        {
            cout << "Genome 1 is the best match." << endl;
            cout << "Genome 2 is the best match." << endl;
        }
        else if (bestScoreOne == bestScoreThree && bestScoreOne > bestScoreTwo)
        {
            cout << "Genome 1 is the best match." << endl;
            cout << "Genome 3 is the best match." << endl;
        }
        else if (bestScoreTwo == bestScoreThree && bestScoreTwo > bestScoreOne)
        {
            cout << "Genome 2 is the best match." << endl;
            cout << "Genome 3 is the best match." << endl;
        }
        else if (bestScoreOne == bestScoreTwo && bestScoreOne == bestScoreThree && bestScoreTwo == bestScoreThree)
        {
            cout << "Genome 1 is the best match." << endl;
            cout << "Genome 2 is the best match." << endl;
            cout << "Genome 3 is the best match." << endl;
        }
    }
    else if (lengthOne != lengthTwo || lengthOne != lengthThree || lengthTwo != lengthThree)
    {
        cout << "Lengths of genomes are different." << endl;
    }
}

int main()
{
    string genomeOne;
    string genomeTwo;
    string genomeThree;
    string sequence;
    cin >> genomeOne;
    cin >> genomeTwo;
    cin >> genomeThree;
    cin >> sequence;
    findMatchedGenome(genomeOne, genomeTwo, genomeThree, sequence);
}