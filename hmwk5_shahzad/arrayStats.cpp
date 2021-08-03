#include <iostream>
#include <iomanip>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Homework 5 - Problem 2

/*

*/

void stats(double array[], double count)
{
    double total = 0;
    double max = array[0];
    double min = array[0];
    for (int j = 0; j < count; j++)
    {
        if (max < array[j])
        {
            max = array[j];
        }
        else if (min > array[j])
        {
            min = array[j];
        }
        total = array[j] + total;
    }
    cout << fixed << setprecision(2);
    cout << "Min: " << min << endl;
    cout << "Max: " << max << endl;
    cout << "Avg: " << total / count << endl;
    return;
}

int main()
{
    const int NUMBERS = 100;
    double array[NUMBERS];
    double count = 0;

    for (int i = 0; i < NUMBERS; i++)
    {
        if (cin >> array[i])
        {
            count++;
        }
        else
        {
            break;
        }
    }
    stats(array, count);
    cin.clear();
}