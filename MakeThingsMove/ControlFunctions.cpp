#include <Arduino.h>
#include "AudioPlayer.h"
#include "Controller.h"
#include "Robot.h"

/* 
 * Functions to set robot speed and steering angle 
 * in response to button press and release events.
 * Update this code if different robot behavior or control scheme is desired.
 */

 // Robot name
#define ROBOT_NAME "grahamdroid"

Robot robot;
Controller controller;

/*
 * Drive the robot full speed forwards when a button is pressed.
 * Stop the robot when the button is released.
 */
void driveForward(bool pressed) {
  Serial.print("Robot ");
  if (pressed) {
      Serial.print("is moving forward");
      robot.move(1.0f);
  } else {
      Serial.print("has stopped");
      robot.stop();
  }
  Serial.println();
}

/*
 * Drive the robot full speed backwards when a button is pressed.
 * Stop the robot when the button is released.
 */
void driveBackward(bool pressed) {
  Serial.print("Robot ");
  if (pressed) {
      Serial.print("is moving backward");
      robot.move(-1.0f);
  } else {
      Serial.print("has stopped");
      robot.stop();
  }
  Serial.println();
}

/*
 * Steer the robot all the way to the right when a button is pressed.
 * Return the robot to the forward direction when the button is released.
 */
void steerRight(bool pressed) {
  Serial.print("Robot ");
  if (pressed) {
      Serial.print("is steering right");
      robot.steer(180.0f);
  } else {
      Serial.print("is steering forward");
      robot.steer(90.0f);
  }
  Serial.println();
}

/*
 * Steer the robot all the way to the left when a button is pressed.
 * Return the robot to the forward direction when the button is released.
 */
void steerLeft(bool pressed) {
  Serial.print("Robot ");
  if (pressed) {
      Serial.print("is steering left");
      robot.steer(0.0f);
  } else {
      Serial.print("is steering forward");
      robot.steer(90.0f);
  }
  Serial.println();
}

/*
 * Connect controller buttons to robot functions
 */
void registerRobotFunctions() {
  controller.registerCallback("triangle", driveForward);
  controller.registerCallback("x", driveBackward);
  controller.registerCallback("left", steerLeft);
  controller.registerCallback("right", steerRight);
}

/*
 * Functions below this comment are generic and do not need to be modified.
 */

/*
 * Set up robot and controller.
 */
void init_everything() {
  // Initialize serial connection
  Serial.begin(115200);

  // Initialize controller
  controller.init(ROBOT_NAME);

  // Initialize robot
  robot.init();

  // Connect controller buttons to robot functions
  registerRobotFunctions();

  // Initialize audio player
  init_audio();
}

/*
 * Updates the robot by allowing the controller to check for
 * inputs and call the associated robot functions.
 */
void update() {
  controller.update();
  update_audio();
}