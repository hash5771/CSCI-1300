#include <iostream>
#include "victor.h"
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

Victor::Victor()
{
    victor = false;
    playerArraySize = 24;
    playerArray[24];
}
Victor::Victor(bool victor, Player playerArray[], int playerArraySize)
{
    setVictor(victor);
    setPlayerArray(playerArray, playerArraySize);
}
void Victor::setVictor(bool victorInput)
{
    victor = victorInput;
}
bool Victor::getVictor()
{
    return victor;
}
void Victor::setPlayerArray(Player playerInputArray[], int playerArraySizeInput)
{
    playerInputArray[playerArraySizeInput];
}
Player Victor::getPlayerArray()
{
    return playerArray[24];
}