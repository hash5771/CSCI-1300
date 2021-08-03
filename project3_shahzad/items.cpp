#include <iostream>
#include "items.h"
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Project 3

/*
this class controls the total amount of items available to players in the arena
the player can manipulate these by choosing to go out and find food, water, meds, or weapons
all of these actions are hard coded
*/

Items::Items()
{
    int weaponsAmount = 0;
    int foodAmount = 0;
    int waterAmount = 0;
    int medicineAmount = 10;
}
Items::Items(int weaponsAmount, int foodAmount, int waterAmount, int medicineAmount)
{
    setWeaponsAmount(weaponsAmount);
    setFoodAmount(foodAmount);
    setWaterAmount(waterAmount);
    setMedicineAmount(medicineAmount);
}
void Items::setWeaponsAmount(int weaponsAmountInput)
{
    weaponsAmount = weaponsAmountInput;
}
int Items::getWeaponsAmount()
{
    return weaponsAmount;
}
void Items::setFoodAmount(int foodAmountInput)
{
    foodAmount = foodAmountInput;
}
int Items::getFoodAmount()
{
    return foodAmount;
}
void Items::setWaterAmount(int waterAmountInput)
{
    waterAmount = waterAmountInput;
}
int Items::getWaterAmount()
{
    return waterAmount;
}
void Items::setMedicineAmount(int medicineAmountInput)
{
    medicineAmount = medicineAmountInput;
}
int Items::getMedicineAmount()
{
    return medicineAmount;
}