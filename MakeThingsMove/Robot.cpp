#include "Robot.h"
#include "esp32-hal-ledc.h"
#include <cmath>
#include <Arduino.h>
#include "Settings.h"

/*
 * A class which defines how a robot moves.
 * Update this class when changes are made to the robot hardware.
 */
Robot::Robot() {
  // Robot is initially stopped
  float currentSpeed = 0;

  // Robot is initially pointed straight forward 
  float currentAngle = 90;

  int currentDuty;
}

/**
 * Sets up robot hardware.
 */
void Robot::init() {
  // Set up servo PWM, fixed at 50 hz
  ledcSetup(SERVO_CHANNEL,50,SERVO_PWM_RESOLUTION);
  ledcAttachPin(SERVO_PIN, SERVO_CHANNEL);
  steer(90);

  // Set up forward and reverse drive PWMs
  ledcAttachPin(drivePos, FWD_CHANNEL);
  ledcSetup(FWD_CHANNEL,DRIVE_PWM_HZ,DRIVE_PWM_RESOLUTION);
  ledcWrite(FWD_CHANNEL,0);
  ledcAttachPin(driveNeg, REV_CHANNEL);
  ledcSetup(REV_CHANNEL, DRIVE_PWM_HZ,DRIVE_PWM_RESOLUTION);
  ledcWrite(REV_CHANNEL,0);

  #ifdef DEBUG_MODE
    // Light up the onboard LED to indicate that the system has power
    pinMode(LED_BUILTIN, OUTPUT);
    digitalWrite(LED_BUILTIN,HIGH);
  #endif
}

/**
 * Moves the robot at the given speed.
 * Speed must be a floating-point number in the range -1 to 1, 
 * representing a percentage from -100% to 100% of the robot's top speed
 */
void Robot::move(float speed) {
  float abs_speed = std::abs(speed);
  if (abs_speed >= 0.0f && abs_speed <= 1.0f) {
    // Calculate drive motor duty based on desired speed
    int duty = std::round((MAX_DRIVE_DUTY - MIN_DRIVE_DUTY) * abs_speed) + MIN_DRIVE_DUTY;
    if (speed > 0) {
      // Set forward PWM duty
      ledcWrite(FWD_CHANNEL, duty);
      ledcWrite(REV_CHANNEL, 0);
    } else if (speed < 0) {
      // Set reverse PWM duty
      ledcWrite(REV_CHANNEL, duty);
      ledcWrite(FWD_CHANNEL, 0);
    } else {
      stop();
    }
    currentSpeed = speed;
  }
}

float Robot::getSpeed() {
  return currentSpeed;
}

void Robot::stop() {
  ledcWrite(FWD_CHANNEL, 0);
  ledcWrite(REV_CHANNEL, 0);
  currentSpeed = 0;
}

/**
 * Steers the robot to the given angle.
 * Steering angle must be a floating-point number between 0 and 180, 
 * representing the angle of the robot's front wheels
 */
void Robot::steer(float angle) {
  if (angle >= 0.0f && angle <= 180.0f) {
    // Set steering servo duty based on angle
    int duty = std::round((MAX_SERVO_DUTY - MIN_SERVO_DUTY) * (angle / 180) + MIN_SERVO_DUTY);
    ledcWrite(SERVO_CHANNEL, duty);
    currentAngle = angle;
    currentDuty = duty;
  }
}

float Robot::getSteeringAngle() {
  return currentAngle;
}

void Robot::setDuty(int duty) {
  ledcWrite(SERVO_CHANNEL, duty);
  currentDuty = duty;
}

int Robot::getDuty() {
  return currentDuty;
}