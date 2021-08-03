#include <iostream>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 - Madhusudhan
// Homework 4 - Problem 3

int main()
{
    int userInput;
    do
    {
        cout << "Select a numerical option:" << endl;
        cout << "=== menu ===" << endl;
        cout << "1. Fox" << endl;
        cout << "2. Bunny" << endl;
        cout << "3. Sloth" << endl;
        cout << "4. Quit" << endl;
        cin >> userInput;
        double hireScore;
        double agility;
        double strength;
        double speed;
        if (userInput == 1)
        {
            cout << "Enter agility:" << endl;
            cin >> agility;
            agility = agility * 1.8;
            cout << "Enter strength:" << endl;
            cin >> strength;
            strength = strength * 2.16;
            hireScore = agility + strength;
            cout << "Hire Score: " << hireScore << endl;
        }
        else if (userInput == 2)
        {
            cout << "Enter agility:" << endl;
            cin >> agility;
            agility = agility * 1.8;
            cout << "Enter speed:" << endl;
            cin >> speed;
            speed = speed * 3.24;
            hireScore = agility + speed;
            cout << "Hire Score: " << hireScore << endl;
        }
        else if (userInput == 3)
        {
            cout << "Enter strength:" << endl;
            cin >> strength;
            strength = strength * 2.16;
            cout << "Enter speed:" << endl;
            cin >> speed;
            speed = speed * 3.24;
            hireScore = strength + speed;
            cout << "Hire Score: " << hireScore << endl;
        }
        else if (userInput == 4)
        {
            cout << "Good bye!" << endl;
        }
        else
        {
            cout << "Invalid option" << endl;
        }
    } while (userInput != 4);
}
