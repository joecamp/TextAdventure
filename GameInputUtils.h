#pragma once
#include <string>
#include <iostream>
#include "DifficultySettings.h"

namespace GameInputUtils {
    DifficultySettings selectDifficulty();
    std::string getPlayerName();
    bool askYesNo(const std::string& prompt);
    std::string getInput(const std::string& prompt);
}