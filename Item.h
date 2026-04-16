#pragma once
#include <string>

using std::string;

class Item
{
public:
	string name;
	float weight;
	int value;

	Item(string name, float weight, int value)
	{
		this->name = name;
		this->weight = weight;
		this->value = value;
	}
	
	string toString() const;
	void display() const;
};