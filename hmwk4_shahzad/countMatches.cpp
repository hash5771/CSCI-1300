#include <iostream>
#include <string>
using namespace std;
using std::string;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 - Madhusudhan
// Homework 4 - Problem 4

int main()
{
    string searchString;
    cout << "Enter the search string:" << endl;
    cin >> searchString;

    string subString;
    cout << "Enter the substring to be searched:" << endl;
    cin >> subString;

    int sub = subString.length();
    int search = searchString.length();
    int counter = 0;

    for (int i = 0; i <= search - sub; i++)
    {
        int j;
        for (j = 0; j < sub; j++)
            if (searchString[i + j] != subString[j])
                break;
        if (j == sub)
        {
            counter++;
            j = 0;
        }
    }
    cout << "Number of occurences: " << counter << endl;
    return counter;
}
