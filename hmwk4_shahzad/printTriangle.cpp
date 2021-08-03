#include <iostream>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 - Madhusudhan
// Homework 4 - Problem 5

int main () {
    int height;
    cout << "Enter the height:" << endl;
    cin >> height;
    char a = 'a';
    for (int i = height; i > 0; i--)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << a++;
            if (a > 'z')
            {
                a = 'a';
            }
        }
        cout << endl;
    }
    return 0;
}