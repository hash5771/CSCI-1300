#include "arena.cpp"
#include "player.cpp"
#include "items.cpp"
//#include "victor.h" cannot be included because it will redefine player.cpp and code cannot compile, use of #ifndef, #define, and #endif did not fix problem
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <ctime>
#include <string>
#include <ios> //used to get stream size
#include <limits>

using namespace std;

// CS1300 Fall 2020
// Author: Hassan Shahzad
// Recitation: 518 – Madhusudhan
// Project 3

// requirements missed: file output, use of an array of object from one class as a data member in another class, four user-defined classes (only 3)

int split(string phrase, char del, string words[], int size) //used for reading the tribute name and district from a file
{
    if (phrase.length() == 0)
    {
        return 0;
    }

    string piece = "";
    int arrpos = 0;

    for (int pos = 0; pos < phrase.length(); pos++)
    {
        if (phrase[pos] != del)
        {
            piece = piece + phrase[pos];
        }
        else
        {
            if (pos != 0 && pos != (phrase.length() - 1))
            {
                words[arrpos] = piece;
                piece = "";
                arrpos++;

                int check = pos + 1;
                if (phrase[check] == del)
                {
                    pos++;
                }
            }
            else
            {
                if (pos == (phrase.length() - 1))
                {
                    pos++;
                }
            }
        }
    }
    words[arrpos] = piece;

    int count = arrpos + 1;
    if (count > size)
    {
        return -1;
    }
    return count;
}

void setInitialTributeStats(string filename, Player tributeArray[], int tributeArraySize) //reads tribute name and district from a file
{
    tributeArray[tributeArraySize];
    ifstream file;
    file.open(filename);

    if (!file.is_open())
    {
        cout << "File could not be opened." << endl;
    }
    else
    {
        string lines = "";
        string splitArray[2];
        int i = 0;
        while (getline(file, lines))
        {
            if (lines != "")
            {
                split(lines, ',', splitArray, tributeArraySize);
                tributeArray[i].setPlayerName(splitArray[0]);
                tributeArray[i].setDistrict(stoi(splitArray[1]));
                tributeArray[i].setHealth(100);
                tributeArray[i].setHunger(100);
                tributeArray[i].setThirst(100);
                tributeArray[i].setPlayerKills(0);
                tributeArray[i].setFallenTribute(false);
                tributeArray[i].setMedicineInventory(0);
                tributeArray[i].setFoodInventory(0);
                tributeArray[i].setWaterInventory(0);
                i++;
            }
        }
    }
    file.close();
}

void setItemsArena(Items &itemsObject, Arena arenaObject) // sets the available items in the arena depending on the randomly returned arena
{
    if (arenaObject.getArena() == "Jungle")
    {
        itemsObject.setWeaponsAmount(48);
        itemsObject.setFoodAmount(2400);
        itemsObject.setWaterAmount(2000);
        itemsObject.setMedicineAmount(800);
    }
    else if (arenaObject.getArena() == "Desert")
    {
        itemsObject.setWeaponsAmount(48);
        itemsObject.setFoodAmount(1600);
        itemsObject.setWaterAmount(800);
        itemsObject.setMedicineAmount(2000);
    }
    else if (arenaObject.getArena() == "Ocean")
    {
        itemsObject.setWeaponsAmount(48);
        itemsObject.setFoodAmount(2000);
        itemsObject.setWaterAmount(2400);
        itemsObject.setMedicineAmount(1200);
    }
    else if (arenaObject.getArena() == "Mountain")
    {
        itemsObject.setWeaponsAmount(48);
        itemsObject.setFoodAmount(1200);
        itemsObject.setWaterAmount(1600);
        itemsObject.setMedicineAmount(1600);
    }
    else if (arenaObject.getArena() == "Tundra")
    {
        itemsObject.setWeaponsAmount(48);
        itemsObject.setFoodAmount(800);
        itemsObject.setWaterAmount(1200);
        itemsObject.setMedicineAmount(2400);
    }
}

int main() // controller of the game
{
    int playerkills = 0;
    string fileName = "tributeList.txt";
    int tributeArraySize = 24;
    Player tributeArray[tributeArraySize];
    setInitialTributeStats(fileName, tributeArray, tributeArraySize);

    int userArrayIndex = 0;

    cout << "Welcome to the Hunger Games" << endl;

    string userName;
    cout << "Enter your Tribute Name: ";
    getline(cin, userName);

    int userDistrict = 0;
    do
    {
        cout << "Enter your District Number (1-12): ";
        cin >> userDistrict;
        if (userDistrict == 1 || userDistrict == 2 || userDistrict == 3 || userDistrict == 4 || userDistrict == 5 || userDistrict == 6 || userDistrict == 7 || userDistrict == 8 || userDistrict == 9 || userDistrict == 10 || userDistrict == 11 || userDistrict == 12)
        {
            break;
        }
        else if (cin.fail())
        {
            cout << "Invalid District Number" << endl;

            // get rid of failure state
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        else
        {
            cout << "Invalid District Number" << endl;
        }
    } while (userDistrict != 1 || userDistrict != 2 || userDistrict != 3 || userDistrict != 4 || userDistrict != 5 || userDistrict != 6 || userDistrict != 7 || userDistrict != 8 || userDistrict != 9 || userDistrict != 10 || userDistrict != 11 || userDistrict != 12);

    switch (userDistrict)
    {
    case 1:
        userArrayIndex = 0;
        break;
    case 2:
        userArrayIndex = 2;
        break;
    case 3:
        userArrayIndex = 4;
        break;
    case 4:
        userArrayIndex = 6;
        break;
    case 5:
        userArrayIndex = 8;
        break;
    case 6:
        userArrayIndex = 10;
        break;
    case 7:
        userArrayIndex = 12;
        break;
    case 8:
        userArrayIndex = 14;
        break;
    case 9:
        userArrayIndex = 16;
        break;
    case 10:
        userArrayIndex = 18;
        break;
    case 11:
        userArrayIndex = 20;
        break;
    case 12:
        userArrayIndex = 22;
        break;
    }

    string userGender;
    do
    {
        cout << "Enter your Tribute Gender (M/F): ";
        cin >> userGender;
        if (userGender == "M" || userGender == "F")
        {
            break;
        }
        else
        {
            cout << "Invalid Gender" << endl;
        }
    } while (userGender != "M" || userGender != "F");

    if (userGender == "M")
    {
        userArrayIndex++;
    }

    tributeArray[userArrayIndex].setPlayerName(userName); // sets the players name in the array contingent on inputs among the AI

    Arena currentArena;
    cout << endl;
    if (currentArena.getYear() == 1 || currentArena.getYear() == 21 || currentArena.getYear() == 31 || currentArena.getYear() == 41 || currentArena.getYear() == 51 || currentArena.getYear() == 61 || currentArena.getYear() == 71 || currentArena.getYear() == 81 || currentArena.getYear() == 91)
    {
        cout << "Welcome to the " << currentArena.getYear() << "st Annual Hunger Games! This year's games will take place in a(n) " << currentArena.getArena() << "." << endl
             << endl;
    }
    else if (currentArena.getYear() == 2 || currentArena.getYear() == 22 || currentArena.getYear() == 32 || currentArena.getYear() == 42 || currentArena.getYear() == 52 || currentArena.getYear() == 62 || currentArena.getYear() == 72 || currentArena.getYear() == 82 || currentArena.getYear() == 92)
    {
        cout << "Welcome to the " << currentArena.getYear() << "nd Annual Hunger Games! This year's games will take place in a(n) " << currentArena.getArena() << "." << endl
             << endl;
    }
    else if (currentArena.getYear() == 3 || currentArena.getYear() == 23 || currentArena.getYear() == 33 || currentArena.getYear() == 43 || currentArena.getYear() == 53 || currentArena.getYear() == 63 || currentArena.getYear() == 73 || currentArena.getYear() == 83 || currentArena.getYear() == 93)
    {
        cout << "Welcome to the " << currentArena.getYear() << "rd Annual Hunger Games! This year's games will take place in a(n) " << currentArena.getArena() << "." << endl
             << endl;
    }
    else
    {
        cout << "Welcome to the " << currentArena.getYear() << "th Annual Hunger Games! This year's games will take place in a(n) " << currentArena.getArena() << "." << endl
             << endl;
    }

    Items itemsAmount;
    setItemsArena(itemsAmount, currentArena);

    int menuOneInput = 0;
    int menuTwoInput = 0;
    int menuThreeInput = 0;
    int menuFourInput = 0;
    int numTributes = 23; // keeps track of tributes alive as the game progresses.
    int days = 0;
    do
    {
        cout << "=== MENU ===" << endl
             << "1. Proceed to the Games" << endl
             << "2. See Credits" << endl
             << "3. Quit" << endl;
        cin >> menuOneInput;

        if (menuOneInput == 1)
        {
            do // initial menu option (user only gets to choose once)
            {
                cout << "-------------------------------------------------------" << endl
                     << "You're lifted into the arena. You notice the " << currentArena.getArena() << " environment around you." << endl
                     << "You're met with the first big decision of the games." << endl
                     << "The cornucopia houses copious amounts of weapons, food, water, and medicine." << endl
                     << "Because of this, many tributes risk their lives to gather supplies at the start of the games." << endl
                     << "The countdown quickly rings down to 3, 2, 1..." << endl
                     << "What do you do?" << endl
                     << "1. Run Towards the Cornucopia" << endl
                     << "2. Run Away From the Cornucopia" << endl
                     << "3. Quit" << endl
                     << "-------------------------------------------------------" << endl;
                cin >> menuTwoInput;
                if (menuTwoInput == 1 || menuTwoInput == 2)
                {
                    srand(time(NULL));
                    for (int j = 0; j < 24; j++)
                    {
                        int bloodBathChance = rand() % 3 + 1;
                        if (bloodBathChance == 2)
                        {
                            if (j == userArrayIndex && menuTwoInput == 2)
                            {
                                tributeArray[userArrayIndex].setFallenTribute(false);
                            }
                            else // randomly picks off tributes from the array despite user choice (cornucopia fighting)
                            {
                                tributeArray[j].setHealth(0);
                                tributeArray[j].setHunger(0);
                                tributeArray[j].setThirst(0);
                                tributeArray[j].setFallenTribute(true);
                                cout << "A cannon has sounded, Tribute " << tributeArray[j].getPlayerName() << " from District " << tributeArray[j].getDistrict() << " has fallen." << endl;
                                cout << numTributes-- << " out of 24 remain." << endl
                                     << endl;
                                if (j == userArrayIndex)
                                {
                                    return 0;
                                }
                            }
                        }
                        else // randomly distributes resources among tributes if they go to the cornucopia, depending on the current arena (health, hunger, and thirst bars go down)
                        {
                            int numWeapons;
                            int numMeds;
                            int numFood;
                            int numWater;
                            if (currentArena.getArena() == "Jungle")
                            {
                                numWeapons = rand() % 2;
                                numFood = rand() % 75 + 1;
                                numWater = rand() % 60 + 1;
                                numMeds = rand() % 15 + 1;
                            }
                            else if (currentArena.getArena() == "Desert")
                            {
                                numWeapons = rand() % 2;
                                numFood = rand() % 45 + 1;
                                numWater = rand() % 15 + 1;
                                numMeds = rand() % 60 + 1;
                            }
                            else if (currentArena.getArena() == "Ocean")
                            {
                                numWeapons = rand() % 2;
                                numFood = rand() % 60 + 1;
                                numWater = rand() % 75 + 1;
                                numMeds = rand() % 30 + 1;
                            }
                            else if (currentArena.getArena() == "Mountain")
                            {
                                numWeapons = rand() % 2;
                                numFood = rand() % 30 + 1;
                                numWater = rand() % 45 + 1;
                                numMeds = rand() % 45 + 1;
                            }
                            else if (currentArena.getArena() == "Tundra")
                            {
                                numWeapons = rand() % 2;
                                numFood = rand() % 15 + 1;
                                numWater = rand() % 30 + 1;
                                numMeds = rand() % 75 + 1;
                            }
                            if (menuTwoInput == 1)
                                tributeArray[j].setWeaponInventory(numWeapons);
                            itemsAmount.setWeaponsAmount(itemsAmount.getWeaponsAmount() - numWeapons);
                            tributeArray[j].setMedicineInventory(numMeds);
                            itemsAmount.setMedicineAmount(itemsAmount.getMedicineAmount() - numMeds);
                            tributeArray[j].setFoodInventory(numFood);
                            itemsAmount.setFoodAmount(itemsAmount.getFoodAmount() - numFood);
                            tributeArray[j].setWaterInventory(numWater);
                            itemsAmount.setWaterAmount(itemsAmount.getWaterAmount() - numWater);
                            int healthDown = rand() % 60;
                            tributeArray[j].setHealth(tributeArray[j].getHealth() - healthDown);
                            int hungerDown = rand() % 60;
                            tributeArray[j].setHunger(tributeArray[j].getHunger() - hungerDown);
                            int thirstDown = rand() % 60;
                            tributeArray[j].setThirst(tributeArray[j].getThirst() - thirstDown);
                            if (j == userArrayIndex && menuTwoInput == 2)
                            {
                                tributeArray[userArrayIndex].setHealth(100);
                                tributeArray[userArrayIndex].setHunger(100);
                                tributeArray[userArrayIndex].setThirst(100);
                                tributeArray[userArrayIndex].setMedicineInventory(0);
                                itemsAmount.setMedicineAmount(itemsAmount.getMedicineAmount() + numMeds);
                                tributeArray[userArrayIndex].setWeaponInventory(0);
                                itemsAmount.setWeaponsAmount(itemsAmount.getWeaponsAmount() + numWeapons);
                                tributeArray[userArrayIndex].setWaterInventory(0);
                                itemsAmount.setWaterAmount(itemsAmount.getWaterAmount() + numWater);
                                tributeArray[userArrayIndex].setFoodInventory(0);
                                itemsAmount.setFoodAmount(itemsAmount.getFoodAmount() + numFood);
                            }
                        }
                    }

                    if (menuTwoInput == 1)
                    {
                        cout << "You've made it past the bloodbath, but you've sustained some damage from fighting other Tributes." << endl
                             << endl
                             << "Here is what you gathered: " << endl
                             << "Weapons: " << tributeArray[userArrayIndex].getWeaponInventory() << endl
                             << "Food: " << tributeArray[userArrayIndex].getFoodInventory() << endl
                             << "Water: " << tributeArray[userArrayIndex].getWaterInventory() << endl
                             << "Medicine: " << tributeArray[userArrayIndex].getMedicineInventory() << endl
                             << endl;
                    }
                    else if (menuTwoInput == 2)
                    {
                        cout << "You've made it past the bloodbath." << endl
                             << endl
                             << "Here is what you have: " << endl
                             << "Weapons: " << tributeArray[userArrayIndex].getWeaponInventory() << endl
                             << "Food: " << tributeArray[userArrayIndex].getFoodInventory() << endl
                             << "Water: " << tributeArray[userArrayIndex].getWaterInventory() << endl
                             << "Medicine: " << tributeArray[userArrayIndex].getMedicineInventory() << endl
                             << endl;
                    }
                    do // second set of options will continuously loop until player chooses to quit the game
                    {
                        if ((numTributes - 1) == 1 && tributeArray[userArrayIndex].getFallenTribute() == false)
                        {
                            cout << "Congratulations to the victor of the annual Hunger Games! " << tributeArray[userArrayIndex].getPlayerName() << " from District " << tributeArray[userArrayIndex].getDistrict() << "!" << endl;
                            return 0;
                        }
                        cout << "-------------------------------------------------------" << endl;
                        cout << "What is your next decision?" << endl
                             << "1. Find/Eat Food" << endl
                             << "2. Find/Drink Water" << endl
                             << "3. Find/Use Medicine" << endl
                             << "4. Find Weapons" << endl
                             << "5. Go after another Tribute" << endl
                             << "6. Rest for the Day" << endl
                             << "7. Check Statistics" << endl
                             << "8. Quit" << endl
                             << "-------------------------------------------------------" << endl;
                        cin >> menuThreeInput;
                        if (numTributes == 1 && tributeArray[userArrayIndex].getFallenTribute() == false)
                        {
                            break;
                        }
                        if (menuThreeInput == 1)
                        {
                            int menuItemOne = 0;
                            int eatFood = 0;
                            do
                            {
                                cout << "-------------------------------------------------------" << endl
                                     << "Current Food Inventory: " << tributeArray[userArrayIndex].getFoodInventory() << endl
                                     << "Current Hunger Level: " << tributeArray[userArrayIndex].getHunger() << endl
                                     << "Food Left in the Arena: " << itemsAmount.getFoodAmount() << endl
                                     << "1. Attempt to Find Food" << endl
                                     << "2. Eat Food from Inventory" << endl
                                     << "3. Return to Options" << endl
                                     << "-------------------------------------------------------" << endl;
                                cin >> menuItemOne;
                                if (menuItemOne == 1)
                                {
                                    int chanceOfFindingFood = rand() % 5 + 1;

                                    if (tributeArray[userArrayIndex].getHunger() <= 0)
                                    {
                                        cout << "A cannon has sounded, Tribute " << tributeArray[userArrayIndex].getPlayerName() << " from District " << tributeArray[userArrayIndex].getDistrict() << " has fallen." << endl;
                                        cout << numTributes-- << " out of 24 remain." << endl
                                             << endl;
                                        tributeArray[userArrayIndex].setHealth(0);
                                        tributeArray[userArrayIndex].setHunger(0);
                                        tributeArray[userArrayIndex].setThirst(0);
                                        tributeArray[userArrayIndex].setFallenTribute(true);
                                        return 0;
                                    }

                                    if (itemsAmount.getFoodAmount() <= 0)
                                    {
                                        itemsAmount.setFoodAmount(0);
                                        cout << "No more food in the Arena, you must take food from other tributes." << endl;
                                        break;
                                    }
                                    else
                                    {
                                        if (chanceOfFindingFood == 1 || chanceOfFindingFood == 5)
                                        {
                                            cout << "You found " << chanceOfFindingFood << " food!" << endl;
                                            tributeArray[userArrayIndex].setFoodInventory(tributeArray[userArrayIndex].getFoodInventory() + chanceOfFindingFood);
                                            itemsAmount.setFoodAmount(itemsAmount.getFoodAmount() - chanceOfFindingFood);
                                            if (itemsAmount.getFoodAmount() <= 0)
                                            {
                                                itemsAmount.setFoodAmount(0);
                                            }
                                        }
                                        else
                                        {
                                            cout << "Could not find any food. Hunger has increased." << endl;
                                            for (int a = 0; a < 24; a++)
                                            {
                                                if (a != userArrayIndex)
                                                {
                                                    int randomFood = rand() % 2;
                                                    tributeArray[a].setFoodInventory(tributeArray[a].getFoodInventory() + randomFood);
                                                    itemsAmount.setFoodAmount(itemsAmount.getFoodAmount() - randomFood);
                                                    if (itemsAmount.getFoodAmount() <= 0)
                                                    {
                                                        itemsAmount.setFoodAmount(0);
                                                    }
                                                }
                                                else
                                                {
                                                    tributeArray[userArrayIndex].setHunger(tributeArray[userArrayIndex].getHunger() - 3);
                                                }
                                            }
                                            cout << "Other tributes have found food." << endl;
                                        }
                                    }
                                }
                                else if (menuItemOne == 2)
                                {
                                    cout << "How much Food would you like to eat?" << endl;
                                    cin >> eatFood;
                                    if (eatFood > tributeArray[userArrayIndex].getFoodInventory() && eatFood != 0)
                                    {
                                        cout << "You don't have that much food!" << endl;
                                    }
                                    else if (eatFood <= tributeArray[userArrayIndex].getFoodInventory() && 100 >= (eatFood + tributeArray[userArrayIndex].getHunger()) && eatFood != 0)
                                    {
                                        tributeArray[userArrayIndex].setHunger(tributeArray[userArrayIndex].getHunger() + eatFood);
                                        tributeArray[userArrayIndex].setFoodInventory(tributeArray[userArrayIndex].getFoodInventory() - eatFood);
                                    }
                                    else if (eatFood <= tributeArray[userArrayIndex].getFoodInventory() && 100 < (eatFood + tributeArray[userArrayIndex].getHunger()) && eatFood != 0)
                                    {
                                        cout << "Cannot have a hunger level greater than 100!" << endl;
                                    }
                                    else if (cin.fail())
                                    {
                                        cout << "Invalid Input" << endl;

                                        // get rid of failure state
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    }
                                    else
                                    {
                                        cout << "Invalid Input" << endl;
                                    }
                                }
                                else if (menuItemOne == 3)
                                {
                                    break;
                                }
                                else if (cin.fail())
                                {
                                    cout << "Invalid Input" << endl;

                                    // get rid of failure state
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }
                                else
                                {
                                    cout << "Invalid Input." << endl;
                                }
                            } while (menuItemOne != 3);
                        }
                        else if (menuThreeInput == 2)
                        {
                            int menuItemTwo = 0;
                            int drinkWater = 0;
                            do
                            {
                                cout << "-------------------------------------------------------" << endl
                                     << "Current Water Inventory: " << tributeArray[userArrayIndex].getWaterInventory() << endl
                                     << "Current Thirst Level: " << tributeArray[userArrayIndex].getThirst() << endl
                                     << "Water Left in the Arena: " << itemsAmount.getWaterAmount() << endl
                                     << "1. Attempt to Find Water" << endl
                                     << "2. Drink Water from Inventory" << endl
                                     << "3. Return to Options" << endl
                                     << "-------------------------------------------------------" << endl;
                                cin >> menuItemTwo;
                                if (menuItemTwo == 1)
                                {
                                    int chanceOfFindingWater = rand() % 5 + 1;

                                    if (tributeArray[userArrayIndex].getThirst() <= 0)
                                    {
                                        cout << "A cannon has sounded, Tribute " << tributeArray[userArrayIndex].getPlayerName() << " from District " << tributeArray[userArrayIndex].getDistrict() << " has fallen." << endl;
                                        cout << numTributes-- << " out of 24 remain." << endl
                                             << endl;
                                        tributeArray[userArrayIndex].setHealth(0);
                                        tributeArray[userArrayIndex].setHunger(0);
                                        tributeArray[userArrayIndex].setThirst(0);
                                        tributeArray[userArrayIndex].setFallenTribute(true);
                                        return 0;
                                    }

                                    if (itemsAmount.getWaterAmount() <= 0)
                                    {
                                        itemsAmount.setWaterAmount(0);
                                        cout << "No more water in the Arena, you must take water from other tributes." << endl;
                                        break;
                                    }

                                    else
                                    {
                                        if (chanceOfFindingWater == 1 || chanceOfFindingWater == 5)
                                        {
                                            cout << "You found " << chanceOfFindingWater << " water!" << endl;
                                            tributeArray[userArrayIndex].setWaterInventory(tributeArray[userArrayIndex].getWaterInventory() + chanceOfFindingWater);
                                            itemsAmount.setWaterAmount(itemsAmount.getWaterAmount() - chanceOfFindingWater);
                                            if (itemsAmount.getWaterAmount() <= 0)
                                            {
                                                itemsAmount.setWaterAmount(0);
                                            }
                                        }
                                        else
                                        {
                                            cout << "Could not find any water. Thirst has increased." << endl;
                                            for (int a = 0; a < 24; a++)
                                            {
                                                if (a != userArrayIndex)
                                                {
                                                    int randomWater = rand() % 2;
                                                    tributeArray[a].setWaterInventory(tributeArray[a].getWaterInventory() + randomWater);
                                                    itemsAmount.setWaterAmount(itemsAmount.getWaterAmount() - randomWater);
                                                    if (itemsAmount.getWaterAmount() <= 0)
                                                    {
                                                        itemsAmount.setWaterAmount(0);
                                                    }
                                                }
                                                else
                                                {
                                                    tributeArray[userArrayIndex].setThirst(tributeArray[userArrayIndex].getThirst() - 3);
                                                }
                                            }
                                            cout << "Other tributes have found water." << endl;
                                        }
                                    }
                                }
                                else if (menuItemTwo == 2)
                                {
                                    cout << "How much water would you like to drink?" << endl;
                                    cin >> drinkWater;
                                    if (drinkWater > tributeArray[userArrayIndex].getWaterInventory() && drinkWater != 0)
                                    {
                                        cout << "You don't have that much water!" << endl;
                                    }
                                    else if (drinkWater <= tributeArray[userArrayIndex].getWaterInventory() && 100 >= (drinkWater + tributeArray[userArrayIndex].getThirst()) && drinkWater != 0)
                                    {
                                        tributeArray[userArrayIndex].setThirst(tributeArray[userArrayIndex].getThirst() + drinkWater);
                                        tributeArray[userArrayIndex].setWaterInventory(tributeArray[userArrayIndex].getWaterInventory() - drinkWater);
                                    }
                                    else if (drinkWater <= tributeArray[userArrayIndex].getWaterInventory() && 100 < (drinkWater + tributeArray[userArrayIndex].getThirst()) && drinkWater != 0)
                                    {
                                        cout << "Cannot have a thirst level greater than 100!" << endl;
                                    }
                                    else if (cin.fail())
                                    {
                                        cout << "Invalid Input" << endl;

                                        // get rid of failure state
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    }
                                    else
                                    {
                                        cout << "Invalid Input" << endl;
                                    }
                                }
                                else if (menuItemTwo == 3)
                                {
                                    break;
                                }
                                else if (cin.fail())
                                {
                                    cout << "Invalid Input" << endl;

                                    // get rid of failure state
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }
                                else
                                {
                                    cout << "Invalid Input." << endl;
                                }
                            } while (menuItemTwo != 3);
                        }
                        else if (menuThreeInput == 3)
                        {
                            int menuItemThree = 0;
                            int useMeds = 0;
                            do
                            {
                                cout << "-------------------------------------------------------" << endl
                                     << "Current Medicine Inventory: " << tributeArray[userArrayIndex].getMedicineInventory() << endl
                                     << "Current Health Level: " << tributeArray[userArrayIndex].getHealth() << endl
                                     << "Medicine Left in the Arena: " << itemsAmount.getMedicineAmount() << endl
                                     << "1. Attempt to Find Medicine" << endl
                                     << "2. Use Medicine from Inventory" << endl
                                     << "3. Return to Options" << endl
                                     << "-------------------------------------------------------" << endl;
                                cin >> menuItemThree;
                                if (menuItemThree == 1)
                                {
                                    int chanceOfFindingMeds = rand() % 5 + 1;

                                    if (tributeArray[userArrayIndex].getHealth() <= 0)
                                    {
                                        cout << "A cannon has sounded, Tribute " << tributeArray[userArrayIndex].getPlayerName() << " from District " << tributeArray[userArrayIndex].getDistrict() << " has fallen." << endl;
                                        cout << numTributes-- << " out of 24 remain." << endl
                                             << endl;
                                        tributeArray[userArrayIndex].setHealth(0);
                                        tributeArray[userArrayIndex].setHunger(0);
                                        tributeArray[userArrayIndex].setThirst(0);
                                        tributeArray[userArrayIndex].setFallenTribute(true);
                                        return 0;
                                    }

                                    if (itemsAmount.getMedicineAmount() <= 0)
                                    {
                                        itemsAmount.setMedicineAmount(0);
                                        cout << "No more medicine in the Arena, you must take medicine from other tributes." << endl;
                                        break;
                                    }

                                    else
                                    {
                                        if (chanceOfFindingMeds == 1 || chanceOfFindingMeds == 5)
                                        {
                                            cout << "You found " << chanceOfFindingMeds << " medicine!" << endl;
                                            tributeArray[userArrayIndex].setMedicineInventory(tributeArray[userArrayIndex].getMedicineInventory() + chanceOfFindingMeds);
                                            itemsAmount.setMedicineAmount(itemsAmount.getMedicineAmount() - chanceOfFindingMeds);
                                            if (itemsAmount.getMedicineAmount() <= 0)
                                            {
                                                itemsAmount.setMedicineAmount(0);
                                            }
                                        }
                                        else
                                        {
                                            cout << "Could not find any medicine. Health has decreased." << endl;
                                            for (int a = 0; a < 24; a++)
                                            {
                                                if (a != userArrayIndex)
                                                {
                                                    int randomMeds = rand() % 2;
                                                    tributeArray[a].setMedicineInventory(tributeArray[a].getMedicineInventory() + randomMeds);
                                                    itemsAmount.setMedicineAmount(itemsAmount.getMedicineAmount() - randomMeds);
                                                    if (itemsAmount.getMedicineAmount() <= 0)
                                                    {
                                                        itemsAmount.setMedicineAmount(0);
                                                    }
                                                }
                                                else
                                                {
                                                    tributeArray[userArrayIndex].setHealth(tributeArray[userArrayIndex].getHealth() - 3);
                                                }
                                            }
                                            cout << "Other tributes have found medicine." << endl;
                                        }
                                    }
                                }
                                else if (menuItemThree == 2)
                                {
                                    cout << "How much Medicine would you like to use?" << endl;
                                    cin >> useMeds;
                                    if (useMeds > tributeArray[userArrayIndex].getMedicineInventory() && useMeds != 0)
                                    {
                                        cout << "You don't have that much medicine!" << endl;
                                    }
                                    else if (useMeds <= tributeArray[userArrayIndex].getMedicineInventory() && 100 >= (useMeds + tributeArray[userArrayIndex].getHealth()) && useMeds != 0)
                                    {
                                        tributeArray[userArrayIndex].setHealth(tributeArray[userArrayIndex].getHealth() + useMeds);
                                        tributeArray[userArrayIndex].setMedicineInventory(tributeArray[userArrayIndex].getMedicineInventory() - useMeds);
                                    }
                                    else if (useMeds <= tributeArray[userArrayIndex].getMedicineInventory() && 100 < (useMeds + tributeArray[userArrayIndex].getHealth()) && useMeds != 0)
                                    {
                                        cout << "Cannot have a health level greater than 100!" << endl;
                                    }
                                    else if (cin.fail())
                                    {
                                        cout << "Invalid Input" << endl;

                                        // get rid of failure state
                                        cin.clear();
                                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                    }
                                    else
                                    {
                                        cout << "Invalid Input" << endl;
                                    }
                                }
                                else if (menuItemThree == 3)
                                {
                                    break;
                                }
                                else if (cin.fail())
                                {
                                    cout << "Invalid Input" << endl;

                                    // get rid of failure state
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }
                                else
                                {
                                    cout << "Invalid Input." << endl;
                                }
                            } while (menuItemThree != 3);
                        }
                        else if (menuThreeInput == 4)
                        {
                            int menuItemFour = 0;
                            do
                            {
                                cout << "-------------------------------------------------------" << endl
                                     << "Current Weapons Inventory: " << tributeArray[userArrayIndex].getWeaponInventory() << endl
                                     << "Weapons left in the Arena: " << itemsAmount.getWeaponsAmount() << endl
                                     << "1. Attempt to Find Weapons" << endl
                                     << "2. Return to Options" << endl
                                     << "-------------------------------------------------------" << endl;
                                cin >> menuItemFour;
                                if (menuItemFour == 1)
                                {
                                    int chanceOfFindingWeapons = rand() % 5 + 1;
                                    if (itemsAmount.getWeaponsAmount() > 0)
                                    {
                                        if (chanceOfFindingWeapons == 1 || chanceOfFindingWeapons == 5)
                                        {
                                            cout << "You found " << 1 << " weapon!" << endl;
                                            tributeArray[userArrayIndex].setWeaponInventory(tributeArray[userArrayIndex].getWeaponInventory() + 1);
                                            itemsAmount.setWeaponsAmount(itemsAmount.getWeaponsAmount() - 1);
                                            if (itemsAmount.getWeaponsAmount() <= 0)
                                            {
                                                itemsAmount.setWeaponsAmount(0);
                                            }
                                        }
                                        else
                                        {
                                            cout << "Could not find any weapons." << endl;
                                            for (int a = 0; a < 24; a++)
                                            {
                                                if (a != userArrayIndex)
                                                {
                                                    int randomWeapons = rand() % 2;
                                                    tributeArray[a].setWeaponInventory(tributeArray[a].getWeaponInventory() + randomWeapons);
                                                    itemsAmount.setWeaponsAmount(itemsAmount.getWeaponsAmount() - randomWeapons);
                                                    if (itemsAmount.getWeaponsAmount() <= 0)
                                                    {
                                                        itemsAmount.setWeaponsAmount(0);
                                                    }
                                                }
                                                else
                                                {
                                                    cout << "Other tributes have gathered weapons." << endl;
                                                }
                                            }
                                        }
                                    }
                                    else if (itemsAmount.getWeaponsAmount() <= 0)
                                    {
                                        itemsAmount.setWeaponsAmount(0);
                                        cout << "No more weapons in the Arena, you must take weapons from other tributes." << endl;
                                        break;
                                    }
                                }
                                else if (menuItemFour == 2)
                                {
                                    break;
                                }
                                else if (cin.fail())
                                {
                                    cout << "Invalid Input" << endl;

                                    // get rid of failure state
                                    cin.clear();
                                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                }
                                else
                                {
                                    cout << "Invalid Input." << endl;
                                }
                            } while (menuItemFour != 2);
                        }
                        else if (menuThreeInput == 5)
                        {
                            int fightTribute = 0;
                            int findTribute = rand() % 4 + 1;
                            if (findTribute == 1)
                            {
                                cout << "Could not locate other tributes." << endl
                                     << "You've expended energy." << endl;
                                tributeArray[userArrayIndex].setHunger(tributeArray[userArrayIndex].getHunger() - rand() % 5);
                                tributeArray[userArrayIndex].setThirst(tributeArray[userArrayIndex].getThirst() - rand() % 5);
                                if (tributeArray[userArrayIndex].getHunger() <= 0 || tributeArray[userArrayIndex].getThirst() <= 0)
                                {
                                    tributeArray[userArrayIndex].setHealth(0);
                                    tributeArray[userArrayIndex].setHunger(0);
                                    tributeArray[userArrayIndex].setThirst(0);
                                    tributeArray[userArrayIndex].setFallenTribute(true);
                                    cout << "A cannon has sounded, Tribute " << tributeArray[userArrayIndex].getPlayerName() << " from District " << tributeArray[userArrayIndex].getDistrict() << " has fallen." << endl;
                                    cout << numTributes-- << " out of 24 remain." << endl
                                         << endl;
                                    return 0;
                                }
                            }
                            else
                            {
                                int randomTribute = 25;

                                do
                                {
                                    randomTribute = rand() % 23;
                                } while (randomTribute == userArrayIndex && tributeArray[randomTribute].getFallenTribute() == true);

                                if (tributeArray[randomTribute].getFallenTribute() == false && randomTribute != userArrayIndex)
                                {
                                    do
                                    {
                                        if (tributeArray[randomTribute].getHealth() <= 0)
                                        {
                                            tributeArray[randomTribute].setHealth(0);
                                            tributeArray[randomTribute].setHunger(0);
                                            tributeArray[randomTribute].setThirst(0);
                                            tributeArray[randomTribute].setFallenTribute(true);
                                            cout << "A cannon has sounded, Tribute " << tributeArray[randomTribute].getPlayerName() << " from District " << tributeArray[randomTribute].getDistrict() << " has fallen." << endl;
                                            cout << numTributes-- << " out of 24 remain." << endl
                                                 << endl;
                                            tributeArray[userArrayIndex].setFoodInventory(tributeArray[userArrayIndex].getFoodInventory() + 5);
                                            tributeArray[userArrayIndex].setWaterInventory(tributeArray[userArrayIndex].getWaterInventory() + 5);
                                            tributeArray[userArrayIndex].setMedicineInventory(tributeArray[userArrayIndex].getMedicineInventory() + 5);
                                            int chanceOfGainingWeapons = rand() % 5 + 1;
                                            if (chanceOfGainingWeapons == 3)
                                            {
                                                tributeArray[userArrayIndex].setWeaponInventory(tributeArray[userArrayIndex].getWeaponInventory() + 1);
                                            }
                                            cout << "You've gained some of the fallen tribute's items." << endl << endl;
                                            tributeArray[userArrayIndex].setPlayerKills(playerkills++);
                                            break;
                                        }
                                        if (tributeArray[userArrayIndex].getHealth() <= 0)
                                        {
                                            tributeArray[userArrayIndex].setHealth(0);
                                            tributeArray[userArrayIndex].setHunger(0);
                                            tributeArray[userArrayIndex].setThirst(0);
                                            tributeArray[userArrayIndex].setFallenTribute(true);
                                            cout << "A cannon has sounded, Tribute " << tributeArray[userArrayIndex].getPlayerName() << " from District " << tributeArray[userArrayIndex].getDistrict() << " has fallen." << endl;
                                            cout << numTributes-- << " out of 24 remain." << endl
                                            << "You've fallen to " << tributeArray[randomTribute].getPlayerName() << endl << endl;
                                            return 0;
                                        }
                                        cout << "-------------------------------------------------------" << endl
                                             << "You've encountered " << tributeArray[randomTribute].getPlayerName() << " from District " << tributeArray[randomTribute].getDistrict() << "!" << endl
                                             << "Your health: " << tributeArray[userArrayIndex].getHealth() << endl
                                             << "Your weapons: " << tributeArray[userArrayIndex].getWeaponInventory() << endl
                                             << "Tribute health: " << tributeArray[randomTribute].getHealth() << endl
                                             << "Tribute weapons: " << tributeArray[randomTribute].getWeaponInventory() << endl
                                             << endl
                                             << "=== Battle Menu ===" << endl
                                             << "1. Attack" << endl
                                             << "2. Block" << endl
                                             << "3. Flee" << endl
                                             << "-------------------------------------------------------" << endl;
                                        cin >> fightTribute;
                                        if (fightTribute == 1)
                                        {
                                            int attack = rand() % 5 + 1;
                                            if (attack == 2 || attack == 4)
                                            {
                                                cout << "Tribute blocked attack! The tribute attacked!" << endl;
                                                tributeArray[userArrayIndex].setHealth(tributeArray[userArrayIndex].getHealth() - (tributeArray[randomTribute].getWeaponInventory() * 5));
                                            }
                                            else
                                            {
                                                cout << "Successfully attacked!" << endl;
                                                tributeArray[randomTribute].setHealth(tributeArray[randomTribute].getHealth() - (tributeArray[userArrayIndex].getWeaponInventory() * 5));
                                            }
                                        }

                                        else if (fightTribute == 2)
                                        {
                                            int block = rand() % 5 + 1;
                                            if (block == 2 || block == 4)
                                            {
                                                cout << "Couldn't block attack! The tribute attacked!" << endl;
                                                tributeArray[userArrayIndex].setHealth(tributeArray[userArrayIndex].getHealth() - (tributeArray[randomTribute].getWeaponInventory() * 5));
                                            }
                                            else
                                            {
                                                cout << "Successfully blocked attack! You successfully attacked!" << endl;
                                                tributeArray[randomTribute].setHealth(tributeArray[randomTribute].getHealth() - (tributeArray[userArrayIndex].getWeaponInventory() * 5));
                                            }
                                        }

                                        else if (fightTribute == 3)
                                        {
                                            int flee = rand() % 5 + 1;
                                            if (flee == 3)
                                            {
                                                cout << "Successfully fled from the tribute!" << endl;
                                                break;
                                            }
                                            else
                                            {
                                                cout << "Couldn't flee from the tribute!" << endl
                                                     << "The tribute attacked!" << endl;
                                                tributeArray[userArrayIndex].setHealth(tributeArray[userArrayIndex].getHealth() - (tributeArray[randomTribute].getWeaponInventory() * 5));
                                            }
                                        }

                                        else if (cin.fail())
                                        {
                                            cout << "Invalid Input" << endl;

                                            // get rid of failure state
                                            cin.clear();
                                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                                        }

                                        else
                                        {
                                            cout << "Invalid Input" << endl;
                                        }
                                    } while (tributeArray[randomTribute].getFallenTribute() == false || tributeArray[userArrayIndex].getFallenTribute() == false);
                                }
                                else if (randomTribute == userArrayIndex)
                                {
                                    cout << "You could not find other tributes." << endl;
                                }
                                else
                                {
                                    cout << "A hovercraft is seen recovering " << tributeArray[randomTribute].getPlayerName() << " from District " << tributeArray[randomTribute].getDistrict() << ". Other tributes must be close..." << endl;
                                }
                            }
                        }
                        else if (menuThreeInput == 6)
                        {
                            for (int l = 0; l < 24; l++)
                            {
                                if (tributeArray[l].getFallenTribute() == false)
                                {
                                    int health = rand() % 10 + 1;
                                    int hunger = rand() % 20 + 1;
                                    int thirst = rand() % 20 + 1;
                                    tributeArray[l].setHealth(tributeArray[l].getHealth() + health);
                                    tributeArray[l].setHunger(tributeArray[l].getHunger() - hunger);
                                    tributeArray[l].setThirst(tributeArray[l].getThirst() - thirst);
                                    if (tributeArray[l].getHunger() <= 25 && tributeArray[l].getHunger() > 0)
                                    {
                                        if (l != userArrayIndex)
                                        {
                                            tributeArray[l].setHunger(tributeArray[l].getHunger() + tributeArray[l].getFoodInventory());
                                            tributeArray[l].setFoodInventory(0);
                                        }
                                        else if (l == userArrayIndex && tributeArray[userArrayIndex].getFallenTribute() == false)
                                        {
                                            cout << "Current hunger level: " << tributeArray[userArrayIndex].getHunger() << endl;
                                            cout << "Your hunger level is getting critical!" << endl;
                                        }
                                    }
                                    if (tributeArray[l].getHealth() <= 25 && tributeArray[l].getHealth() > 0)
                                    {
                                        if (l != userArrayIndex)
                                        {
                                            tributeArray[l].setHealth(tributeArray[l].getHealth() + tributeArray[l].getMedicineInventory());
                                            tributeArray[l].setMedicineInventory(0);
                                        }
                                        else if (l == userArrayIndex && tributeArray[userArrayIndex].getFallenTribute() == false)
                                        {
                                            cout << "Current health level: " << tributeArray[userArrayIndex].getHealth() << endl;
                                            cout << "Your health level is getting critical!" << endl;
                                        }
                                    }
                                    if (tributeArray[l].getThirst() <= 25 && tributeArray[l].getThirst() > 0)
                                    {
                                        if (l != userArrayIndex)
                                        {
                                            tributeArray[l].setThirst(tributeArray[l].getThirst() + tributeArray[l].getWaterInventory());
                                            tributeArray[l].setWaterInventory(0);
                                        }
                                        else if (l == userArrayIndex && tributeArray[userArrayIndex].getFallenTribute() == false)
                                        {
                                            cout << "Current thirst level: " << tributeArray[userArrayIndex].getThirst() << endl;
                                            cout << "Your thirst level is getting critical!" << endl;
                                        }
                                    }
                                    if (tributeArray[l].getHunger() <= 0 || tributeArray[l].getThirst() <= 0 || tributeArray[l].getHealth() <= 0)
                                    {
                                        tributeArray[l].setHealth(0);
                                        tributeArray[l].setHunger(0);
                                        tributeArray[l].setThirst(0);
                                        tributeArray[l].setFallenTribute(true);
                                        cout << "A cannon has sounded, Tribute " << tributeArray[l].getPlayerName() << " from District " << tributeArray[l].getDistrict() << " has fallen." << endl;
                                        cout << numTributes-- << " out of 24 remain." << endl << endl;
                                    }
                                }
                            }
                            currentArena.setDays(days++);
                        }
                        else if (menuThreeInput == 7)
                        {
                            int menuItemSeven = 0;
                            cout << "1. Check Inventory" << endl
                                 << "2. Check Health, Hunger, and Thirst" << endl
                                 << "3. Check Remaining Tributes" << endl;
                            cin >> menuItemSeven;
                            if (menuItemSeven == 1)
                            {
                                cout << "Your Current Inventory, Remaining Arena Inventory" << endl
                                     << "Weapons: " << tributeArray[userArrayIndex].getWeaponInventory() << ", " << itemsAmount.getWeaponsAmount() << endl
                                     << "Food: " << tributeArray[userArrayIndex].getFoodInventory() << ", " << itemsAmount.getFoodAmount() << endl
                                     << "Water: " << tributeArray[userArrayIndex].getWaterInventory() << ", " << itemsAmount.getWaterAmount() << endl
                                     << "Medicine: " << tributeArray[userArrayIndex].getMedicineInventory() << ", " << itemsAmount.getMedicineAmount() << endl;
                            }
                            else if (menuItemSeven == 2)
                            {
                                cout << "Your Current: " << endl;
                                cout << "Health: " << tributeArray[userArrayIndex].getHealth() << endl; 
                                cout << "Hunger: " << tributeArray[userArrayIndex].getHunger() << endl;
                                cout << "Thirst: " << tributeArray[userArrayIndex].getThirst() << endl;
                            }
                            else if (menuItemSeven == 3)
                            {
                                cout << "Remaining Tributes: " << endl;
                                for (int m = 0; m < 24; m++)
                                {
                                    if (tributeArray[m].getFallenTribute() == false)
                                    {
                                        cout << tributeArray[m].getPlayerName() << " from District " << tributeArray[m].getDistrict() << endl;
                                    }
                                }
                                cout << "Number of days since the Games Began: " << days << endl;
                            }
                            else if (cin.fail())
                            {
                                cout << "Invalid Input" << endl;

                                // get rid of failure state
                                cin.clear();
                                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            }
                            else
                            {
                                cout << "Invalid Input" << endl;
                            }
                        }
                        else if (cin.fail())
                        {
                            cout << "Invalid Input" << endl;

                            // get rid of failure state
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                        }
                        else if (menuThreeInput == 8)
                        {
                            break;
                        }
                        else
                        {
                            cout << "Invalid Input" << endl;
                        }
                    } while (menuThreeInput != 8);
                    break;
                }

                else if (menuTwoInput == 3)
                {
                    break;
                }

                else if (cin.fail())
                {
                    cout << "Invalid Input" << endl;

                    // get rid of failure state
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                }

                else
                {
                    cout << "Invalid Input" << endl;
                }

            } while (menuTwoInput != 3);
            break;
        }

        else if (menuOneInput == 2)
        {
            cout << "-------------------------------------------------------" << endl
                 << "The Hunger Games - Text-Based Adventure" << endl
                 << "Written by Hassan Shahzad" << endl
                 << "Programmed in C++" << endl
                 << "November 2020" << endl
                 << "-------------------------------------------------------" << endl;
        }

        else if (menuOneInput == 3)
        {
            break;
        }

        else if (cin.fail())
        {
            cout << "Invalid Input" << endl;

            // get rid of failure state
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        else
        {
            cout << "Invalid Input" << endl;
        }

    } while (menuOneInput != 3);

    cout << "Thank you for playing!" << endl;
    return 0;
}