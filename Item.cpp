#include <iostream>

#include "Item.h"

using std::cout;
using std::endl;

string Item::toString() const {
	return name + " | " + std::to_string(weight) + "kg | $" + std::to_string(value);
}

void Item::display() const {
	cout << name << " | " << weight << "kg | $" << value << endl;
}