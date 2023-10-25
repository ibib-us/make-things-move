#ifndef GAMEPAD_H
#define GAMEPAD_H

#include <unordered_map>
#include <functional>

class Gamepad {
public:
    struct ButtonData {
        bool state;
        std::function<void(bool)> callback;
    };

    Gamepad();

    void setButtonState(const std::string& buttonName, bool newState);
    bool isButtonPressed(const std::string& buttonName) const;

    void registerCallback(const std::string& buttonName, std::function<void(bool)> callback);

    static void defaultCallback(bool newState);

    // Function to start Dabble service
    void init(const std::string& robotName);
    
    // Function to check Dabble gamepad state
    void update();

private:
    std::unordered_map<std::string, ButtonData> buttonStates;
};

#endif