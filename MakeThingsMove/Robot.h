#pragma once

// Servo constants

// The duty cycle at which the robot's servo motor points the robot all the way to the left
#define MIN_DUTY 1800
// The duty cycle at which the robot's servo motor points the robot all the way to the right
#define MAX_DUTY 7800
// TODO what is this?
#define TIMER_WIDTH 16
// The pin that the servo's control wire is connected to
#define SERVO_PIN 16
// TODO what is this?
#define SERVO_CHANNEL 1

// Drive motor constants

// The pin that the motor's forward control wire is connected to
#define drivePos 17
// The pin that the motor's reverse control wire is connected to
#define driveNeg 21
// TODO what is this?
#define FWD_CHANNEL 2
// TODO what is this?
#define REV_CHANNEL 3
// The minimum PWM frequency at which the robot's drive motor will move the robot
// TODO experiment to find actual value
#define MIN_HZ 50
// The maximum PWM frequency for the robot's drive motor
// TODO experiment to find actual value
#define MAX_HZ 200

class Robot {
public:
  Robot();
  void init();
  void move(float speed);
  float getSpeed();
  void stop();
  void steer(float angle);
  float getSteeringAngle();

private:
  float currentSpeed;
  float currentAngle;
};