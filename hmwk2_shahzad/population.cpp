#include <iostream>
#include <iomanip>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 - Madhusudhan
// Homework 2 - Problem 2

int main() {
    cout << "Enter the current population: " << endl;
    int second = 1;
    int minute = second * 60;
    int hour = minute * 60;
    int day = hour * 24;
    int year = day * 365;
    int births = year / 8;
    int deaths = year / 12;
    int immigration = year / 27;
    int pop;
    cin >> pop;
    double one = pop + births;
    double two = one - deaths;
    double three = two + immigration;
    cout << fixed << setprecision(0);
    cout << "The population in one year: " << three;
    return 0;
}