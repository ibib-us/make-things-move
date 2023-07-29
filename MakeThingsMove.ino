/*
   Gamepad module provides three different mode namely Digital, JoyStick and Accerleometer.

   You can reduce the size of library compiled by enabling only those modules that you want to
   use. For this first define CUSTOM_SETTINGS followed by defining INCLUDE_modulename.

   Explore more on: https://thestempedia.com/docs/dabble/game-pad-module/
*/

// Dabble 
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>



// Servo seems to crash the uC, not sure if this is a timing or power issue.

// Servo defines for low-level operation
#define COUNT_LOW 2000
#define COUNT_HIGH 7600
#define TIMER_WIDTH 16
#define SERVO_PIN 16
#define SERVO_CHANNEL 1
int servoCount = 4800;

// drive pins
int drivePos = 17;
int driveNeg = 21;
int driveSpd = 14;
#define FWD_CHANNEL 3
#define REV_CHANNEL 2
#define SPD_CHANNEL 4

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);      // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin("MS1m");       //set bluetooth name of your device



  // Set up servo PWM, fixed at 50 hz
  ledcSetup(SERVO_CHANNEL,50,TIMER_WIDTH);
  ledcAttachPin(SERVO_PIN, SERVO_CHANNEL);
    

  // Set drive pins
  // Tried to PWM the EN pin on the L293, but that doesn't seem to be working, reverting. Update: Problem was possibly having too low a PWM.
//  pinMode(drivePos,OUTPUT);
//  pinMode(driveNeg,OUTPUT);
//  digitalWrite(driveNeg, LOW);
//  digitalWrite(drivePos, LOW);
  ledcAttachPin(drivePos, FWD_CHANNEL);
  ledcSetup(FWD_CHANNEL,5000,8);
  ledcWrite(FWD_CHANNEL,0);
  ledcAttachPin(driveNeg, REV_CHANNEL);
  ledcSetup(REV_CHANNEL, 5000,8);
  ledcWrite(REV_CHANNEL,0);
  ledcAttachPin(driveSpd, SPD_CHANNEL);
  ledcSetup(SPD_CHANNEL,5000,8);
  ledcWrite(SPD_CHANNEL,255);
  
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, HIGH);
}

void loop() {

  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  Serial.print("KeyPressed: ");
  if (GamePad.isUpPressed())
  {

    Serial.print("Up");
  }

  if (GamePad.isDownPressed())
  {

    Serial.print("Down");
  }

  if (GamePad.isLeftPressed())
  {
    Serial.print("Left");
    servoCount += 10;
    servoCount = constrain(servoCount, COUNT_LOW, COUNT_HIGH);
    ledcWrite(SERVO_CHANNEL,servoCount);
  }

  if (GamePad.isRightPressed())
  {
    Serial.print("Right");
    servoCount -= 10;
    servoCount = constrain(servoCount, COUNT_LOW, COUNT_HIGH);
    ledcWrite(SERVO_CHANNEL,servoCount);
  }

  if (GamePad.isSquarePressed())
  {
    Serial.print("Square");
  }

  if (GamePad.isCirclePressed())
  {
    Serial.print("Circle");
  }

  if (GamePad.isCrossPressed())
  {
    Serial.print("Cross");
//    digitalWrite(drivePos, HIGH);
//    digitalWrite(driveNeg, LOW);
    ledcWrite(REV_CHANNEL, 150);
    ledcWrite(FWD_CHANNEL, 0);
    
  } else if (GamePad.isTrianglePressed()) {
    Serial.print("Triangle");
//    digitalWrite(drivePos, LOW);
//    digitalWrite(driveNeg, HIGH);
    ledcWrite(REV_CHANNEL, 0);
    ledcWrite(FWD_CHANNEL, 200); // 100 is too slow.
  } else {
//    digitalWrite(drivePos, LOW);
//    digitalWrite(driveNeg, LOW);
    ledcWrite(FWD_CHANNEL, 0);
    ledcWrite(REV_CHANNEL, 0);
  } 

  if (GamePad.isStartPressed())
  {
    Serial.print("Start");
  }

  if (GamePad.isSelectPressed())
  {
    Serial.print("Select");
  }
  Serial.print('\t');

  int a = GamePad.getAngle();
  Serial.print("Angle: ");
  Serial.print(a);
  Serial.print('\t');
  int b = GamePad.getRadius();
  Serial.print("Radius: ");
  Serial.print(b);
  Serial.print('\t');
  float c = GamePad.getXaxisData();
  Serial.print("x_axis: ");
  Serial.print(c);
  Serial.print('\t');
  float d = GamePad.getYaxisData();
  Serial.print("y_axis: ");
  Serial.println(d);
  Serial.println();
}