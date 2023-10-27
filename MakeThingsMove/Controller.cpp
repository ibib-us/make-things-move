// Import Dabble library
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

#include "Controller.h"

/*
 * A class which allows custom functions to be called 
 * when buttons on a Dabble gamepad are pressed or released.
 * Does not require any modifications in order to be used in different projects.
 */
Controller::Controller() {
  // All the buttons start in the unpressed state with no action assigned.
  buttonStates = {
    {"up", {false, Controller::defaultCallback}},
    {"down", {false, Controller::defaultCallback}},
    {"left", {false, Controller::defaultCallback}},
    {"right", {false, Controller::defaultCallback}},
    {"triangle", {false, Controller::defaultCallback}},
    {"square", {false, Controller::defaultCallback}},
    {"circle", {false, Controller::defaultCallback}},
    {"x", {false, Controller::defaultCallback}},
    {"select", {false, Controller::defaultCallback}},
    {"start", {false, Controller::defaultCallback}}
  };
}

/*
 * Default button action; intentionally does nothing.
 */
void Controller::defaultCallback(bool newState) {}

/*
 * Associates the given function with the given button.
 */
void Controller::registerCallback(const std::string& buttonName, std::function<void(bool)> callback) {
    if (buttonStates.find(buttonName) != buttonStates.end()) {
        buttonStates[buttonName].callback = callback;
    }
}

/*
 * Internal method used to update a button's state 
 * and trigger the associated function if the state has changed.
 */
void Controller::setButtonState(const std::string& buttonName, bool newState) {
  // Check if a button exists with the given name
  if (buttonStates.find(buttonName) != buttonStates.end()) {
      ButtonData& buttonData = buttonStates[buttonName];
      // Check if the button state has changed
      if (buttonData.state != newState) {
          buttonData.state = newState;
          // Call the button's callback with its state information
          buttonData.callback(newState);
      }
  }
}

/*
 * Sets up the Dabble connection.
 */
void Controller::init(const std::string& robotName) {
  Dabble.begin(robotName);
}

/*
 * Checks for input from the Dabble gamepad and updates internal states.
 */
void Controller::update() {
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