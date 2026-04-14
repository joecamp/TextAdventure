// DifficultySettings.h
#pragma once

struct DifficultySettings {
	int maxHealth;
	float maxCarryWeight;
	int startingMoney;

	static constexpr DifficultySettings Easy() { return { 150, 75.0f, 200 }; }
	static constexpr DifficultySettings Medium() { return { 100, 50.0f, 100 }; }
	static constexpr DifficultySettings Hard() { return { 75, 30.0f, 50 }; }
};