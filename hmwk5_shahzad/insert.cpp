#include <iostream>
#include <iomanip>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Homework 5 - Problem 3

void insert(int array[], int numElems, int size, int value)
{
    cout << array[size] << endl;
}

int main()
{
    const int CAPACITY = 10;
    int numElems = 8;
    int size = 10;
    int array[size] = {1, 1, 3, 4, 5, 5, 5, 6};
    int value = 2;
    int insertindex = 0;
    for (int i = 0; i < numElems; i++)
    {
        cout << array[i] << endl;
    }
    insert(array, 8, size, 2);
}