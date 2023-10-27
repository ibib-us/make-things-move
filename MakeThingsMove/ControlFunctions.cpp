#include "Robot.h"
#include <Arduino.h>

/* 
 * Functions to set robot speed and steering angle 
 * in response to button press and release events.
 */

Robot robot;

void init_robot() {
  robot.init();
}

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