#pragma once
#include <iostream>
#include <string>
#include <vector>

#include "DifficultySettings.h"
#include "Item.h"
#include "Health.h"
#include "Inventory.h"
#include "Wallet.h"

using std::string;
using std::vector;

class Player
{
private:

public:
	string name;
	Health health;
	Inventory inventory;
	Wallet wallet;

	Player(string newName, DifficultySettings difficulty)
		: health(difficulty.maxHealth),
		  inventory(difficulty.maxCarryWeight),
		  wallet(difficulty.startingMoney)
	{
		name = newName;
	}

	void checkHealth() const			{ health.get(); }
	void takeDamage(int value)			{ health.takeDamage(value, name); }
	void heal(int value)				{ health.heal(value, name); }
	void fullyHeal()					{ health.fullyHeal(name); }
	void displayHealth() const			{ health.display(name); }

	void checkMoney() const				{ wallet.get(); }
	void addMoney(int value)			{ wallet.add(value); }
	void deductMoney(int value)			{ wallet.deduct(value); }
	void displayMoney() const			{ wallet.display(); }

	bool tryAddItem(const Item& item)		{ return inventory.tryAddItem(item); }
	bool tryDropItemAtIndex(int itemIndex)	{ return inventory.tryDropItemByIndex(itemIndex); }
	void displayInventory() const			{ inventory.displayInventory(); }
};
