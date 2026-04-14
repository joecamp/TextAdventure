#pragma once
#include <string>

using std::string;

class Wallet
{
private:
	int current;
	const int max = 9999;

public:
	Wallet(int amount);

	int get() const { return current; }
	int getMax() const { return max; }

	void add(int value);
	void deduct(int value);
	void display() const;
};