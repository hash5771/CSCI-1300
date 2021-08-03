#include <iostream>
#include <stdlib.h>
#include <ctime>
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

class Player
{
public:
    Player();
    Player(string playerName, int district, int health, int hunger, int thirst, int playerKills, bool fallenTribute, int medicineInventory, int foodInventory, int waterInventory, int weaponInventory);

    void setPlayerName(string playerNameInput);
    string getPlayerName();

    void setDistrict(int districtInput);
    int getDistrict();

    void setHealth(int healthInput);
    int getHealth();

    void setMedicineInventory(int medicineInventoryInput);
    int getMedicineInventory();

    void setHunger(int hungerInput);
    int getHunger();

    void setFoodInventory(int foodInventoryInput);
    int getFoodInventory();

    void setThirst(int thirstInput);
    int getThirst();

    void setWaterInventory(int waterInventoryInput);
    int getWaterInventory();

    void setPlayerKills(int playerKillsInput);
    int getPlayerKills();

    void setFallenTribute(bool fallenTributeInput);
    bool getFallenTribute();

    void setWeaponInventory(int weaponInventoryInput);
    int getWeaponInventory();

private:
    string playerName; //player will insert name
    int district; //player will choose district number
    int health; //keeps track of players health
    int hunger; //keeps track of players hunger
    int thirst; //keeps track of players thirst
    int playerKills; //keeps track of how many kills the player has
    bool fallenTribute; //keeps track of whether or not the tribute is still alive
    int medicineInventory;
    int foodInventory;
    int waterInventory;
    int weaponInventory;
};