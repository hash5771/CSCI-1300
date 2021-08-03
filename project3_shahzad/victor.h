#include <iostream>
#include "player.cpp"
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Project 3

/*
the victor class was originally meant to check for whether or not a player in the playerArray was a victor
if the boolean victor value returned as true (the player was the only tribute left), file output of a congrats message would have occured
could not get this class to work effectively as the redefinition of the player class problem continually occured
class is not included in the final product
*/

class Victor
{
    public:
    Victor();
    Victor(bool victor, Player playerArray[], int playerArraySize);
    void setVictor(bool victorInput);
    bool getVictor();
    void setPlayerArray(Player playerArrayInput[], int playerArraySizeInput);
    Player getPlayerArray();

    private:
    bool victor;
    Player playerArray[24];
    int playerArraySize;
};