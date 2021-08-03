#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 - Madhusudhan
// Homework 3 - Problem 2

int main() {
    double hours;
    double rate;
    cout << "Enter the number of hours worked" << endl;
    cin >> hours;
    cout << "Enter an hourly pay rate" << endl;
    cin >> rate;
    double paycheck;
    if (hours < 0 || rate < 0)
    {
        cout << "Invalid input";
    }
    else if (hours > 40)
    {
        double overtime;
        overtime = (hours - 40);
        paycheck = ((40 * rate) + (1.5 * rate * overtime));
        cout << fixed << setprecision(2) << "Paycheck: " << paycheck;
    }
    else
    {
        paycheck = (hours * rate);
        cout << fixed << setprecision(2) << "Paycheck: " << paycheck;
    }
}