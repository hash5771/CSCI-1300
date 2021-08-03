#include <iostream>
#include <vector>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Homework 8 - Problem 2

/*
this program takes user input (positive integers) and stores it inside of a vector.
- if one vector is longer than the other, alternate as long as possible starting with the longer vector then append remaining elements of long vector
- if both vectors are empty, return an empty vector
- if both vectors are the same size, start with the first inputted vector
*/

vector<int> shuffle(vector<int> vectorOne, vector<int> vectorTwo)
{
    vector<int> shuffle;
    if (vectorOne.size() == vectorTwo.size())
    {
        if (vectorOne.size() == 0)
        {
            shuffle = shuffle;
        }
        else
        {
            for (int i = 0; i < vectorOne.size(); i++)
            {
                shuffle.push_back(vectorOne[i]);
                shuffle.push_back(vectorTwo[i]);
            }
        }
    }
    else if (vectorOne.size() != vectorTwo.size())
    {
        if (vectorOne.size() > vectorTwo.size())
        {
            int j = 0;
            int counter = 0;
            if (vectorTwo.size() == 0)
            {
                while (counter < vectorOne.size())
                {
                    shuffle.push_back(vectorOne[counter]);
                    counter++;
                }
            }
            else
            {
                while (j < vectorTwo.size())
                {
                    shuffle.push_back(vectorOne[j]);
                    shuffle.push_back(vectorTwo[j]);
                    j++;
                    counter = j;
                }
                while (counter < vectorOne.size())
                {
                    shuffle.push_back(vectorOne[counter]);
                    counter++;
                }
            }
        }
        else if (vectorOne.size() < vectorTwo.size())
        {
            int k = 0;
            int counter = 0;
            if (vectorOne.size() == 0)
            {
                while (counter < vectorOne.size())
                {
                    shuffle.push_back(vectorTwo[counter]);
                    counter++;
                }
            }
            else
            {
                while (k < vectorOne.size())
                {
                    shuffle.push_back(vectorTwo[k]);
                    shuffle.push_back(vectorOne[k]);
                    k++;
                    counter = k;
                }
                while (counter < vectorTwo.size())
                {
                    shuffle.push_back(vectorTwo[counter]);
                    counter++;
                }
            }
        }
    }
    return shuffle;
}
int main()
{
    vector<int> v1{1, 3, 5, 9};
    vector<int> v2{2, 4, 6, 8, 10};
    vector<int> v3 = shuffle(v1, v2);
    for (int i = 0; i < v3.size(); i++)
    {
        cout << v3[i] << " ";
    }
}