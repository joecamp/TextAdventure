#include <iostream>

#include "Inventory.h"

using std::cout;
using std::endl;

bool Inventory::tryAddItem(const Item& item) {
	float totalWeight = getInventoryWeight();
	if (totalWeight + item.weight <= maxCarryWeight) {
		addItem(item);
		cout << item.name << " was added to inventory." << endl;
		return true;
	}
	else {
		cout << "Could not add " << item.name << " to inventory, too heavy!" << endl;
		return false;
	}
}

void Inventory::addItem(const Item& item) {
	items.push_back(item);
}

bool Inventory::tryDropItemByIndex(int itemIndex) {
	if (itemIndex < 0 || itemIndex >= items.size()) {
		cout << "Given inventory index '" << itemIndex << "' out of range." << endl;
		return false;
	}

	// Remove element at index 'itemIndex' from the items vector
	cout << items[itemIndex].name << " was dropped." << endl;
	items.erase(items.begin() + itemIndex);

	return true;
}

float Inventory::getInventoryWeight() const {
	float totalWeight = 0;

	//for (int i = 0; i < items.size(); i++) {
	//	totalWeight += items[i].weight;
	//}
	// range-based for loop instead of iterative
	for (const auto& item : items) {
		totalWeight += item.weight;
	}

	return totalWeight;
}

void Inventory::displayInventory() const {
	cout << "-----------------------------" << endl;
	displayInventoryWeight();

	int index = 0;
	for (const auto& item : items) {
		cout << "[" << index << "] ";
		item.display();
		index++;
	}
	
	cout << "-----------------------------" << endl;
}

void Inventory::displayInventoryWeight() const {
	float totalWeight = getInventoryWeight();

	cout << "Total Inventory Weight: " << totalWeight << "kg" << endl;
}