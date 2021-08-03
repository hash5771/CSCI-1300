#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Homework 6 - Problem 1

/*
This function uses a split function to divide each line in a text file into two strings
It then puts the product names into one array and the prices into a number array
*/

int split(string phrase, char del, string words[], int size)
{
    if (phrase.length() == 0)
    {
        return 0;
    }

    string piece = "";
    int arrpos = 0;

    for (int pos = 0; pos < phrase.length(); pos++)
    {
        if (phrase[pos] != del)
        {
            piece = piece + phrase[pos];
        }
        else
        {
            if (pos != 0 && pos != (phrase.length() - 1))
            {
                words[arrpos] = piece;
                piece = "";
                arrpos++;

                int check = pos + 1;
                if (phrase[check] == del)
                {
                    pos++;
                }
            }
            else
            {
                if (pos == (phrase.length() - 1))
                {
                    pos++;
                }
            }
        }
    }
    words[arrpos] = piece;

    int count = arrpos + 1;
    if (count > size)
    {
        return -1;
    }
    return count;
}

int main()
{
    // file name is entered by the user
    cout << "Enter the file name: " << endl;
    string filename;
    cin >> filename;

    // declaration of ifstream reading code from the user's selected file
    ifstream inputFile;

    // file is opened
    inputFile.open(filename);

    if (!inputFile.is_open()) //file does not open
    {
        cout << "Could not open file.";
        return -1;
    }
    else //file opens
    {
        string sort[2] = {};          // will grab all separate strings
        string electronics[100] = {}; // will store the electronics as strings
        string numbers[100] = {};     // will store the numbers as strings
        string lines = "";              // stores the separate lines
        int count = 0;
        double max = 0.0;
        double min = 100000.0;
        int maxposition = 0;
        int minposition = 0;
        while (getline(inputFile, lines)) // will loop each line one by one
        {
            if(lines.length() != 0)
            {
                split(lines, ',', sort, 2);
                // sort[0] is carrying the electronic name, sort[1] is carrying the price as a string
                electronics[count] = sort[0];
                numbers[count] = sort[1];
                double numNums = stod(numbers[count]); //converts the prices from strings into doubles

                if (numNums > max)
                {
                    max = numNums;
                    maxposition = count;
                }
                if (numNums < min)
                {
                    min = numNums;
                    minposition = count;
                }
                cout << electronics[count] << endl;
                count++; // increments count by one after storing electronic name into electronics array & number into numbers array
            }
        }
        cout << "The number of lines: " << count << endl; //return number of lines
        cout << "The most expensive product: " << electronics[maxposition] << endl; //return most expensive product
        cout << "The least expensive product: " << electronics[minposition] << endl; //return least expensive product
    }
    inputFile.close();
}