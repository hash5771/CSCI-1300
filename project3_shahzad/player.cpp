#include <iostream>
#include "player.h"
using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Project 3

/*
this class will control a player array, one part of which will be the actual players index
all other "players" (AI) and their actions/interaction with the player are hard coded
contain inventory and interact with the items class through int main()
*/

Player::Player() // constructor initializes all data members
{
    playerName = "";
    district = 0;
    health = 100;
    hunger = 100;
    thirst = 100;
    playerKills = 0;
    fallenTribute = false;
    medicineInventory = 0;
    foodInventory = 0;
    waterInventory = 0;
    weaponInventory = 0;
}
Player::Player(string playerName, int district, int health, int hunger, int thirst, int playerKills, bool fallenTribute, int medicineInventory, int foodInventory, int waterInventory, int weaponInventory) // parametized constructor sets all necessary data members
{
    setPlayerName(playerName);
    setHealth(health);
    setHunger(hunger);
    setThirst(thirst);
    setDistrict(district);
    setPlayerKills(playerKills);
    setMedicineInventory(medicineInventory);
    setFoodInventory(foodInventory);
    setWaterInventory(waterInventory);
    setWeaponInventory(weaponInventory);
}

void Player::setPlayerName(string playerNameInput) // allows user to set their name
{
    playerName = playerNameInput;
}
string Player::getPlayerName() // returns the user's inputted name
{
    return playerName;
}

void Player::setDistrict(int districtInput) // allows user to set their district # (1-12)
{
    district = districtInput;
}
int Player::getDistrict() // returns district number
{
    return district;
}

void Player::setHealth(int healthInput) // sets health (0-100)
{
    health = healthInput;
}
int Player::getHealth() // returns health (0-100)
{
    return health;
}

void Player::setHunger(int hungerInput) // sets hunger (0-100)
{
    hunger = hungerInput;
}
int Player::getHunger() // returns hunger (0-100)
{
    return hunger;
}

void Player::setThirst(int thirstInput) // sets thirst (0-100)
{
    thirst = thirstInput;
}
int Player::getThirst() // returns thirst (0-100)
{
    return thirst;
}

void Player::setPlayerKills(int playerKillsInput)
{
    playerKills = playerKillsInput;
}
int Player::getPlayerKills()
{
    return playerKills;
}

void Player::setFallenTribute(bool fallenTributeInput)
{
    fallenTribute = fallenTributeInput;
}
bool Player::getFallenTribute()
{
    return fallenTribute;
}

void Player::setMedicineInventory(int medicineInventoryInput)
{
    medicineInventory = medicineInventoryInput;
}
int Player::getMedicineInventory()
{
    return medicineInventory;
}

void Player::setFoodInventory(int foodInventoryInput)
{
    foodInventory = foodInventoryInput;
}
int Player::getFoodInventory()
{
    return foodInventory;
}

void Player::setWaterInventory(int waterInventoryInput)
{
    waterInventory = waterInventoryInput;
}
int Player::getWaterInventory()
{
    return waterInventory;
}

void Player::setWeaponInventory(int weaponInventoryInput)
{
    weaponInventory = weaponInventoryInput;
}
int Player::getWeaponInventory()
{
    return weaponInventory;
}