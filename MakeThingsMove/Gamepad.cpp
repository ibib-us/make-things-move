// Dabble 
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

#include "Gamepad.h"

Gamepad::Gamepad() {
    // Initialize the button states as false (unpressed)
    buttonStates = {
        {"up", false},
        {"down", false},
        {"left", false},
        {"right", false},
        {"triangle", false},
        {"square", false},
        {"circle", false},
        {"x", false},
        {"select", false},
        {"start", false}
    };
}

void Gamepad::setButtonState(const std::string& buttonName, bool newState) {
    // Check if the button exists in our map
    if (buttonStates.find(buttonName) != buttonStates.end()) {
        bool prevState = buttonStates[buttonName];
        // Check if the button state has changed
        if (prevState != newState) {
            buttonStates[buttonName] = newState;

            // Call the common callback method with button name and state information
            commonCallback(buttonName, newState, prevState);
        }
    }
}

void Gamepad::commonCallback(const std::string& buttonName, bool newState, bool prevState) {
    Serial.print("Button \"");
    Serial.print(buttonName.c_str());
    Serial.print("\" was ");
    if (newState) {
        Serial.print("pressed");
    } else {
        Serial.print("released");
    }
    Serial.println();
}

bool Gamepad::isButtonPressed(const std::string& buttonName) const {
    if (buttonStates.find(buttonName) != buttonStates.end()) {
        return buttonStates.at(buttonName);
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