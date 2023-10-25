// Dabble 
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

#include "Gamepad.h"

Gamepad::Gamepad() {
    // Initialize the button states as false (unpressed)
    buttonStates = {
        {"up", {false, Gamepad::defaultCallback}},
        {"down", {false, Gamepad::defaultCallback}},
        {"left", {false, Gamepad::defaultCallback}},
        {"right", {false, Gamepad::defaultCallback}},
        {"triangle", {false, Gamepad::defaultCallback}},
        {"square", {false, Gamepad::defaultCallback}},
        {"circle", {false, Gamepad::defaultCallback}},
        {"x", {false, Gamepad::defaultCallback}},
        {"select", {false, Gamepad::defaultCallback}},
        {"start", {false, Gamepad::defaultCallback}}
    };
}

void Gamepad::defaultCallback(bool newState) {
  // No-op
}

void Gamepad::registerCallback(const std::string& buttonName, std::function<void(bool)> callback) {
    if (buttonStates.find(buttonName) != buttonStates.end()) {
        buttonStates[buttonName].callback = callback;
    }
}

void Gamepad::setButtonState(const std::string& buttonName, bool newState) {
    // Check if the button exists in our map
    if (buttonStates.find(buttonName) != buttonStates.end()) {
        ButtonData& buttonData = buttonStates[buttonName];
        // Check if the button state has changed
        if (buttonData.state != newState) {
            buttonData.state = newState;

            // Call the button's callback with state information
            buttonData.callback(newState);
        }
    }
}

bool Gamepad::isButtonPressed(const std::string& buttonName) const {
    if (buttonStates.find(buttonName) != buttonStates.end()) {
        return buttonStates.at(buttonName).state;
    }
    return false; // Button not found, default to unpressed
}

void Gamepad::init(const std::string& robotName) {
  Dabble.begin(robotName);
  Serial.begin(115200);
}

void Gamepad::update() {
  Dabble.processInput();
  setButtonState("up", GamePad.isUpPressed());
  setButtonState("down", GamePad.isDownPressed());
  setButtonState("left", GamePad.isLeftPressed());
  setButtonState("right", GamePad.isRightPressed());
  setButtonState("circle", GamePad.isCirclePressed());
  setButtonState("x", GamePad.isCrossPressed());
  setButtonState("square", GamePad.isSquarePressed());
  setButtonState("triangle", GamePad.isTrianglePressed());
  setButtonState("select", GamePad.isSelectPressed());
  setButtonState("start", GamePad.isStartPressed());
}