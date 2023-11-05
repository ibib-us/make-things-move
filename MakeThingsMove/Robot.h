#pragma once

// Servo constants

// The resolution of the servo PWM
#define SERVO_PWM_RESOLUTION 16
// The pin that the servo's control wire is connected to
#define SERVO_PIN 16
// Channel to control servo PWM
#define SERVO_CHANNEL 1

// Drive motor constants

// The pin that the motor's forward control wire is connected to
#define drivePos 17
// The pin that the motor's reverse control wire is connected to
#define driveNeg 21
// Channel to control forward PWM
#define FWD_CHANNEL 2
// Channel to control reverse PWM
#define REV_CHANNEL 3
// The minimum PWM duty at which the robot's drive motor will move the robot
#define MIN_DRIVE_DUTY 0
// The maximum PWM duty for the robot's drive motor
#define MAX_DRIVE_DUTY 255
// The frequency for the forward and reverse PWMs
#define DRIVE_PWM_HZ 5000
// The resolution of the drive PWM
#define DRIVE_PWM_RESOLUTION 8

class Robot {
public:
  Robot();
  void init();
  void move(float speed);
  float getSpeed();
  void stop();
  void steer(float angle);
  float getSteeringAngle();
  int getDuty();
  void setDuty(int duty);

private:
  float currentSpeed;
  float currentAngle;
  int currentDuty;
};