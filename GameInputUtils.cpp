#include "GameInputUtils.h"
using std::string;
using std::cout;
using std::cin;
using std::endl;

DifficultySettings GameInputUtils::selectDifficulty() {
    cout << "Select difficulty: (1) Easy, (2) Medium, (3) Hard" << endl;
    string diffInput;
    getline(cin, diffInput);

    while (diffInput != "1" && diffInput != "2" && diffInput != "3") {
        cout << "Invalid input. Please enter (1), (2), or (3)." << endl;
        getline(cin, diffInput);
    }
    if (diffInput == "1") {
        cout << "Selected Easy difficulty." << endl;
        return DifficultySettings::Easy();
    }
    else if (diffInput == "2") {
        cout << "Selected Medium difficulty." << endl;
        return DifficultySettings::Medium();
    }
    else {
        cout << "Selected Hard difficulty." << endl;
        return DifficultySettings::Hard();
    }
}

string GameInputUtils::getPlayerName() {
    string input;
    cout << "Enter your name..." << endl;
    getline(cin, input);

    return input;
}

bool GameInputUtils::askYesNo(const string& prompt) {
    cout << prompt << " (Y/N)" << endl;
    string input;
    getline(cin, input);
    while (input != "Y" && input != "N" &&
        input != "y" && input != "n") {
        cout << "Invalid input. Please enter Y or N." << endl;
        getline(cin, input);
    }
    return (input == "Y" || input == "y");
}

string GameInputUtils::getInput(const string& prompt) {
    cout << prompt << endl;
    string input;
    getline(cin, input);
    return input;
}