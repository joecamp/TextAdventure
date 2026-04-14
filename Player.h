#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "DifficultySettings.h"
#include "Item.h"
#include "Health.h"
#include "Wallet.h"

using std::string;
using std::vector;

class Player
{
private:
	double carryWeight;

public:
	string name;
	double maxCarryWeight;
	Health health;
	Wallet wallet;

	vector<Item> items;

	Player(string newName, DifficultySettings difficulty)
		: health(difficulty.maxHealth),
		  wallet(difficulty.startingMoney)
	{
		name = newName;

		maxCarryWeight = difficulty.maxCarryWeight;

		carryWeight = maxCarryWeight;
	}

	void checkHealth() const	{ health.get(); }
	void takeDamage(int value)	{ health.takeDamage(value, name); }
	void heal(int value)		{ health.heal(value, name); }
	void fullyHeal()			{ health.fullyHeal(name); }
	void displayHealth() const	{ health.display(name); }

	void checkMoney() const		{ wallet.get(); }
	void addMoney(int value)	{ wallet.add(value); }
	void deductMoney(int value) { wallet.deduct(value); }
	void displayMoney() const	{ wallet.display(); }

	double getCarryWeight() const { return carryWeight; }
};
