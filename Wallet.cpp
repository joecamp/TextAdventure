#include "Wallet.h"
#include <iostream>

using std::cout;
using std::endl;

Wallet::Wallet(int amount) {
	if (current > max) {
		current = max;
	}
	else {
		current = amount;
	}
}

void Wallet::add(int value) {
	current += value;
	if (current > max) {
		current = max;
	}
}

void Wallet::deduct(int value) {
	current -= value;
	if (current < 0) {
		current = 0;
	}
}

void Wallet::display() const {
	cout << "$" << current << " in wallet." << endl;
}