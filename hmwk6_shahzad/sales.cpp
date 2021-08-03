#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Homework 6 - Problem 2

/*

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

int readSales(string file, string employeeNames[], int employeeNumMonthly[][12], int arraySize)
{
    ifstream inputFile;
    inputFile.open(file);

    if (!inputFile.is_open()) // file did not open
    {
        return -1;
    }
    else // file opened
    {
        string lines = "";
        string sortNames[1] = {};
        string sortNumbers[12] = {};
        int count = 0;
        int employeeNum = 0;
        int totalCount = 0;
        while (getline(inputFile, lines)) //function grabs each individual line in the file
        {
            if (arraySize < employeeNum)
            {
                break;
            }
            else if (totalCount % 2 == 0) //grabs all of the employee names
            {
                split(lines, ',', sortNames, 1);
                employeeNames[count] = sortNames[0];
                cout << employeeNames[count];
                employeeNames[count] = "";
                count++;
                totalCount++;
            }
            else //grabs all of the monthly sales and stores them into the 2D array
            {
                split(lines, ',', sortNumbers, 12);
                double totalSales = 0;
                for (int i = 0; i < 12; i++)
                {
                    double totalSort = stod(sortNumbers[i]);
                    totalSales += totalSort;
                    employeeNumMonthly[employeeNum][i] = totalSort;
                }
                double average = totalSales / 12;
                cout << fixed << setprecision(1) << ": " << average << endl;
                employeeNum++;
                totalCount++;
            }
        }
        cout << count << endl;
        inputFile.close();
        return count;
    }
}

int main()
{
    string file = "sales.txt";
    const int SIZE = 12;
    string employeeNames[SIZE] = {""};
    int employeeNumMonthly[SIZE][12] = {0};
    readSales(file, employeeNames, employeeNumMonthly, SIZE);
}