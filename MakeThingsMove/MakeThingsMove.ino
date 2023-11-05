#include "ControlFunctions.h"

/*
 * An Arduino sketch to control a robot.
 * See Settings.h to change robot name and enable audio or debugging mode.
 * See ControlFunctions.cpp to change behavior or control scheme.
 * See Robot.cpp if changes are made to robot hardware.
 */

/*
 * This function runs on startup. It calls init_everything()
 * to set up the robot and the controller.
 */
void setup() {
  init_everything();
}

/*
 * This function runs repeatedly. It calls the update() function to  
 * make the robot move in response to button presses.
 */
void loop() {
  update();
}