#ifndef GAMEPAD_H
#define GAMEPAD_H

#include <unordered_map>

class Gamepad {
public:
    Gamepad();

    void setButtonState(const std::string& buttonName, bool newState);
    bool isButtonPressed(const std::string& buttonName) const;

    // Common callback method with branching logic
    void commonCallback(const std::string& buttonName, bool newState, bool prevState);

    // Function to start Dabble service
    void init(const std::string& robotName);
    
    // Function to check Dabble gamepad state
    void update();

private:
    std::unordered_map<std::string, bool> buttonStates;
};

#endif