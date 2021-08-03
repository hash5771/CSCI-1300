#include <iostream>
#include <vector>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Homework 8 - Problem 1

/*
this program takes user input (positive integers) and stores it inside of a vector.
- if the input it divisible by three, the last element of the vector is removed.
- if the input it divisible by five, the first element of the vector is removed.
- once the user input is -1, the loop ends and the program computes the elements in the vector and the max/min values.
*/

int main()
{
    vector<int> numbers;
    int input;
    int indexCounter = 0;
    do
    {
        cout << "Please enter a number:" << endl;
        cin >> input;
        if (input <= 0)
        {
            if (input == -1)
            {
                if (numbers.empty())
                {
                    cout << "The vector is empty." << endl;
                    break;
                }
                else
                {
                    break;
                }
            }
            else
            {
                cout << "The number should be a positive integer or -1." << endl;
            }
        }
        else if (input > 0)
        {
            if (numbers.empty())
            {
                numbers.push_back(input);
                indexCounter++;
            }
            else if (input % 3 == 0 && input % 5 == 0) //if input is divisible by both three and five
            {
                if (indexCounter > 2)
                {
                    numbers.pop_back();             //removes last element of vector
                    numbers.erase(numbers.begin()); //removes first element of vector
                    indexCounter = indexCounter - 2;
                }
                else if (indexCounter == 1)
                {
                    numbers.pop_back();
                    indexCounter--;
                }
            }
            else if (input % 3 == 0 && input % 5 != 0)
            {
                numbers.pop_back();
                indexCounter--;
            }
            else if (input % 5 == 0 && input % 3 != 0)
            {
                numbers.erase(numbers.begin());
                indexCounter--;
            }
            else
            {
                numbers.push_back(input);
                indexCounter++;
            }
        }
    } while (input != -1);

    if (numbers.empty())
    {
        return 0;
    }
    else
    {
        cout << "The elements in the vector are:";
        int max = 0;
        int min = 10000;
        for (int i = 0; i < indexCounter; i++)
        {
            if (i == indexCounter - 1)
            {
                cout << " " << numbers[i] << endl;
            }
            else
            {
                cout << " " << numbers[i];
            }
            if (numbers[i] > max)
            {
                max = numbers[i];
            }
            if (numbers[i] < min)
            {
                min = numbers[i];
            }
        }
        cout << "Min = " << min << endl;
        cout << "Max = " << max << endl;
    }
}