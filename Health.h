#pragma once
#include <string>

using std::string;

class Health
{
private:
	int current;
	int max;

public:
	Health(int maxHp);

	int get() const { return current; }
	int getMax() const { return max; }
	bool isDead() const { return current <= 0; }

	void set(int value);
	void takeDamage(int value, const string& entityName);
	void heal(int value, const string& entityName);
	void fullyHeal(const string& entityName);
	void display(const string& entityName) const;
};
