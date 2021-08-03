#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Project 1 - Problem 7

/*
This function combines questions 4-6 and creates a menu to allow the user to choose their acitivity.
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
    cout << "Select a numerical option:" << endl;
    cout << "=== menu ===" << endl;
    cout << "1. Find similarity score" << endl;
    cout << "2. Find the best similarity score" << endl;
    cout << "3. Analyze the genome sequences" << endl;
    cout << "4. Quit" << endl;
    int option;
    cin >> option;
    while (option != 4)
    {
        if (option == 1)
        {
            string sequenceOne;
            string sequenceTwo;
            cout << "Enter sequence 1:" << endl;
            cin >> sequenceOne;
            cout << "Enter sequence 2:" << endl;
            cin >> sequenceTwo;
            cout << "Similarity score: " << calcSimScore(sequenceOne, sequenceTwo) << endl;
            cout << "Select a numerical option:" << endl;
            cout << "=== menu ===" << endl;
            cout << "1. Find similarity score" << endl;
            cout << "2. Find the best similarity score" << endl;
            cout << "3. Analyze the genome sequences" << endl;
            cout << "4. Quit" << endl;
            cin >> option;
        }
        else if (option == 2)
        {
            string genome;
            string sequence;
            cout << "Enter genome:" << endl;
            cin >> genome;
            cout << "Enter sequence:" << endl;
            cin >> sequence;
            cout << "Best similarity score: " << findBestSimScore (genome, sequence) << endl;
            cout << "Select a numerical option:" << endl;
            cout << "=== menu ===" << endl;
            cout << "1. Find similarity score" << endl;
            cout << "2. Find the best similarity score" << endl;
            cout << "3. Analyze the genome sequences" << endl;
            cout << "4. Quit" << endl;
            cin >> option;
        }
        else if (option == 3)
        {
            string genomeOne;
            string genomeTwo;
            string genomeThree;
            string sequence;
            cout << "Enter genome 1:" << endl;
            cin >> genomeOne;
            cout << "Enter genome 2:" << endl;
            cin >> genomeTwo;
            cout << "Enter genome 3:" << endl;
            cin >> genomeThree;
            cout << "Enter sequence:" << endl;
            cin >> sequence;
            findMatchedGenome(genomeOne, genomeTwo, genomeThree, sequence);
            cout << "Select a numerical option:" << endl;
            cout << "=== menu ===" << endl;
            cout << "1. Find similarity score" << endl;
            cout << "2. Find the best similarity score" << endl;
            cout << "3. Analyze the genome sequences" << endl;
            cout << "4. Quit" << endl;
            cin >> option;
        }
        else
        {
            cout << "Invalid option." << endl;
            cout << "Select a numerical option:" << endl;
            cout << "=== menu ===" << endl;
            cout << "1. Find similarity score" << endl;
            cout << "2. Find the best similarity score" << endl;
            cout << "3. Analyze the genome sequences" << endl;
            cout << "4. Quit" << endl;
            cin >> option;
        }
    }
    cout << "Good bye!" << endl;
}