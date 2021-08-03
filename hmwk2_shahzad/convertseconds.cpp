#include <iostream>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 - Madhusudhan
// Homework 2 - Problem 2

int main() {
    cout << "Enter a number of seconds: " << endl;
    int seconds;
    cin >> seconds;
    int minutes;
    int hours;
    minutes = seconds / 60;
    seconds = seconds % 60;
    hours = minutes / 60;
    minutes = minutes % 60;
    cout << hours << " hour(s) " << minutes << " minute(s) " << seconds << " second(s) ";
    return 0;
}