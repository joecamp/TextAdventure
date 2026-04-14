#include "Health.h"
#include <iostream>

using std::cout;
using std::endl;

Health::Health(int maxHp) {
	max = maxHp;
	current = maxHp;
}

void Health::set(int value) {
	if (value < 0) value = 0;
	if (value > max) value = max;
	current = value;
}

void Health::takeDamage(int value, const string& entityName) {
	cout << entityName << " received " << value << " points of damage!" << endl;
	current -= value;
	if (current <= 0) {
		current = 0;
		cout << entityName << " has died!" << endl;
	}
}

void Health::heal(int value, const string& entityName) {
	cout << entityName << " healed " << value << " hit points!" << endl;
	current += value;
	if (current > max) {
		current = max;
	}
}

void Health::fullyHeal(const string& entityName) {
	current = max;
	cout << entityName << " was fully healed!" << endl;
}

void Health::display(const string& entityName) const {
	double healthPercentage = (double)current / (double)max;
	healthPercentage *= 10;

	cout << "HEALTH: " << current << "/" << max << " ";

	cout << "[";
	for (int i = 0; i < 10; i++) {
		if (i < healthPercentage) {
			cout << "O";
		}
		else {
			cout << "-";
		}
	}
	cout << "]" << endl;
}
