#pragma once
#include <string>
#include <vector>

#include "Item.h"

using std::string;
using std::vector;

class Inventory
{
private:

public:
	float maxCarryWeight;
	vector<Item> items;
	
	Inventory(float maxCarryWeight)
	{
		this->maxCarryWeight = maxCarryWeight;
	}

	bool tryAddItem(const Item& item);
	void addItem(const Item& item);
	bool tryDropItemByIndex(int itemIndex);
	float getInventoryWeight() const;
	void displayInventory() const;
	void displayInventoryWeight() const;
};