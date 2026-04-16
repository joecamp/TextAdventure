#include <iostream>
#include <algorithm>

#include "Player.h"
#include "GameInputUtils.h"
#include "DifficultySettings.h"
#include "ItemDatabase.h"

using std::string;
using std::vector;
using std::cout;
using std::cin;
using std::endl;

int main()
{
    cout << "Creating new Player!" << endl;

    // Select difficulty
    DifficultySettings diffSetting = GameInputUtils::selectDifficulty();

    // Create the player
    string inputName = GameInputUtils::getPlayerName();
    Player player(inputName, diffSetting);

    cout << "New player created with name " << player.name << endl;

    player.displayHealth();
    player.displayMoney();

    // Item testing
    player.tryAddItem(ItemDatabase::CAMP_SUPPLIES);
    player.tryAddItem(ItemDatabase::HEALTH_POTION);
    player.tryAddItem(ItemDatabase::IRON_SWORD);
    player.tryAddItem(ItemDatabase::WOODEN_SHIELD);
    player.displayInventory();

    player.tryDropItemAtIndex(0);
    player.tryDropItemAtIndex(6);
    player.displayInventory();

    // Goblin attack
    cout << "A goblin has stabbed you!" << endl;
    player.takeDamage(50);

    player.displayHealth();
    player.displayMoney();

    // Drink the healing potion
    if (GameInputUtils::askYesNo("Drink the potion?")) {
        cout << player.name << " drank the potion!" << endl;
        player.heal(10);
    }
    else {
        cout << player.name << " tossed the potion on the ground." << endl;
    }

    player.displayHealth();
    player.displayMoney();
}