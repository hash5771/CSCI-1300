#include <iostream>
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

class Items
{
    public:
    Items();
    Items(int weaponsAmount, int foodAmount, int waterAmount, int medicineAmount);
    void setWeaponsAmount(int weaponsAmountInput);
    int getWeaponsAmount();
    void setFoodAmount(int foodAmountInput);
    int getFoodAmount();
    void setWaterAmount(int waterAmountInput);
    int getWaterAmount();
    void setMedicineAmount(int medicineAmountInput);
    int getMedicineAmount();
    //void setItemsArena(Items itemsObject, Arena arenaObject);

    private: //will be adjusted to change based on chosen arena
    int weaponsAmount; //weapon names and choices
    int foodAmount;
    int waterAmount;
    int medicineAmount;
};