#include "Robot.h"
#include "esp32-hal-ledc.h"
#include <cmath>

/*
 * A class which defines how a robot moves.
 */
Robot::Robot() {
  // Robot is initially stopped
  float currentSpeed = 0;

  // Robot is initially pointed straight forward 
  float currentAngle = 90;
}

/**
 * Sets up robot hardware.
 */
void Robot::init() {
  // Set up servo PWM, fixed at 50 hz
  ledcSetup(SERVO_CHANNEL,50,TIMER_WIDTH);
  ledcAttachPin(SERVO_PIN, SERVO_CHANNEL);
    

  // Set up forward and reverse drive PWMs
  ledcAttachPin(drivePos, FWD_CHANNEL);
  ledcSetup(FWD_CHANNEL,5000,8);
  ledcWrite(FWD_CHANNEL,0);
  ledcAttachPin(driveNeg, REV_CHANNEL);
  ledcSetup(REV_CHANNEL, 5000,8);
  ledcWrite(REV_CHANNEL,0);
}

/**
 * Moves the robot at the given speed.
 * Speed must be a floating-point number in the range -1 to 1, 
 * representing a percentage from -100% to 100% of the robot's top speed
 */
void Robot::move(float speed) {
  float abs_speed = std::abs(speed);
  if (abs_speed >= 0.0f && abs_speed <= 1.0f) {
    if (speed > 0) {
      // Set forward PWM frequency based on speed
      ledcWrite(FWD_CHANNEL, std::round((MAX_HZ - MIN_HZ) * abs_speed));
      ledcWrite(REV_CHANNEL, 0);
    } else if (speed < 0) {
      // Set reverse PWM frequency based on speed
      ledcWrite(REV_CHANNEL, std::round((MAX_HZ - MIN_HZ) * abs_speed));
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
  if (currentSpeed > 0) {
    // Stop forward PWM
    ledcWrite(FWD_CHANNEL, 0);
  } else if (currentSpeed < 0) {
    // Stop reverse PWM
    ledcWrite(REV_CHANNEL, 0);
  }
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
    ledcWrite(SERVO_CHANNEL, std::round((MAX_DUTY - MIN_DUTY) * (angle / 180)));
    currentAngle = angle;
  }
}

float Robot::getSteeringAngle() {
  return currentAngle;
}