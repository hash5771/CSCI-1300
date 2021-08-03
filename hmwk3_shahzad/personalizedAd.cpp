#include <iostream>
#include <iomanip>
#include <cmath>
#include <string>
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 - Madhusudhan
// Homework 3 - Problem 6

int main() {
    int ad;
    cout << "How personalized should the ad be? (1-3)" << endl;
    cin >> ad;
    if (ad == 1)
    {
        cout << "Do you own a dog?" << endl;
        string answer;
        cin >> answer;
        string yes = "yes";
        string Yes = "Yes";
        if(answer == yes || answer == Yes)
        {
            cout << "Meat's the need of dogs like yours!";
        }
        else
        {
            cout << "Dirty mouth? Clean it up with new Orbit Raspberry Mint.";
        }
    }
    else if (ad == 2)
    {
        int friends;
        cout << "How many Facebook friends do you have?" << endl;
        cin >> friends;
        if (friends >= 500)
        {
            cout << "Don't like cleaning up after your dog? Call Doody Free to sign up for backyard cleanup or dog walking service.";
        }
        else
        {
            cout << "Who doesn't need another cat? Adopt a shelter pet right meow.";
        }
    }
    else if (ad == 3)
    {
        int zip;
        cout << "What is your zip code?" << endl;
        cin >> zip;
        int age;
        cout << "What is your age?" << endl;
        cin >> age;
        if (80301 <= zip && zip <= 80310)
        {
            if (age >= 25)
            {
                cout << "You are surrounded by professional athletes. Up your exercise game in the privacy of your home with a Peloton bike.";
            }
            else
            {
                cout << "Looking for dinner that won't break the bank? Tacos. Come grab a $3 at Centro Latin Kitchen.";
            }
        }
        else
        {
                cout << "Feeling Uninspired? The Boulder Flatirons are calling. Come hike to inspiring views, delicious food, and enjoy the hospitality of Boulder, CO.";
        }
    }
    else
    {
        cout << "Invalid option." << endl;
    }
}