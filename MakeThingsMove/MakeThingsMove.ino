/*
   Gamepad module provides three different mode namely Digital, JoyStick and Accerleometer.

   You can reduce the size of library compiled by enabling only those modules that you want to
   use. For this first define CUSTOM_SETTINGS followed by defining INCLUDE_modulename.

   Explore more on: https://thestempedia.com/docs/dabble/game-pad-module/
*/

// Robot name
# define ROBOT_NAME "grahamdroid"

// Dabble 
#define CUSTOM_SETTINGS
#define INCLUDE_GAMEPAD_MODULE
#include <DabbleESP32.h>

// Audiotools 
// Uncomment the following line to enable audio
//#define AUDIO_ENABLED
#if AUDIO_ENABLED
  #include "AudioTools.h"
  #include "AudioCodecs/CodecMP3Helix.h"
  #include "AudioLibs/AudioSourceSPIFFS.h"

  // Audio setup
  const char *startFilePath="/sounds";
  const char *ext="mp3";

  AudioSourceSPIFFS source(startFilePath, ext);
  AnalogAudioStream sink;
  MP3DecoderHelix decoder;
  AudioPlayer player (source, sink, decoder);
#endif

// Servo defines for low-level operation
#define COUNT_LOW 1800
#define COUNT_HIGH 7800
#define TIMER_WIDTH 16
#define SERVO_PIN 16
#define SERVO_CHANNEL 1
int servoCount = 4800;

// drive pins
int drivePos = 17;
int driveNeg = 21;
#define FWD_CHANNEL 2
#define REV_CHANNEL 3

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);      // make sure your Serial Monitor is also set at this baud rate.
  Dabble.begin(ROBOT_NAME);       //set bluetooth name of your device
  #if AUDIO_ENABLED
    Serial.println("Audio enabled");
    AudioLogger::instance().begin(Serial, AudioLogger::Warning); // Audiotools logger level
  
    // begin audio processing
    auto cfg = sink.defaultConfig();
    sink.begin(cfg);
    player.begin();
    player.setAutoNext(false);
  #else 
    Serial.println("Audio disabled");
  #endif

  // Set up servo PWM, fixed at 50 hz
  ledcSetup(SERVO_CHANNEL,50,TIMER_WIDTH);
  ledcAttachPin(SERVO_PIN, SERVO_CHANNEL);
    

  // Set drive pins
  //pinMode(drivePos,OUTPUT);
  //pinMode(driveNeg,OUTPUT);
  //digitalWrite(driveNeg, LOW);
  //digitalWrite(drivePos, LOW);
  ledcAttachPin(drivePos, FWD_CHANNEL);
  ledcSetup(FWD_CHANNEL,5000,8);
  ledcWrite(FWD_CHANNEL,0);
  ledcAttachPin(driveNeg, REV_CHANNEL);
  ledcSetup(REV_CHANNEL, 5000,8);
  ledcWrite(REV_CHANNEL,0);
}

void loop() {
  #if AUDIO_ENABLED
    player.copy(); // refresh audio
  #endif
  Dabble.processInput();             //this function is used to refresh data obtained from smartphone.Hence calling this function is mandatory in order to get data properly from your mobile.
  if (GamePad.isUpPressed())
  {
    #if AUDIO_ENABLED
      player.setIndex(0);
    #endif
    Serial.println("Key Pressed: Up");
  }

  if (GamePad.isDownPressed())
  {
    int idx;
    idx = random(6);
    #if AUDIO_ENABLED
      player.setIndex(idx);
    #endif
    Serial.println("Key Pressed: Down");
  }

  if (GamePad.isLeftPressed())
  {
    Serial.println("Key Pressed: left");
    servoCount += 10;
    servoCount = constrain(servoCount, COUNT_LOW, COUNT_HIGH);
    ledcWrite(SERVO_CHANNEL,servoCount);
  }

  if (GamePad.isRightPressed())
  {
    Serial.println("Key Pressed: Right");
    servoCount -= 10;
    servoCount = constrain(servoCount, COUNT_LOW, COUNT_HIGH);
    ledcWrite(SERVO_CHANNEL,servoCount);
  }

  if (GamePad.isSquarePressed())
  {
    Serial.println("Key Pressed: Square");
  }

  if (GamePad.isCirclePressed())
  {
    Serial.println("Key Pressed: Circle");
  }

  if (GamePad.isCrossPressed())
  {
    Serial.println("Key Pressed: Cross");
    //digitalWrite(drivePos, HIGH);
    ledcWrite(FWD_CHANNEL,200);
    //digitalWrite(driveNeg, LOW);
    ledcWrite(REV_CHANNEL, 0);
  } else if (GamePad.isTrianglePressed()) {
    Serial.println("Key Pressed: Triangle");
    //digitalWrite(drivePos, LOW);
    ledcWrite(FWD_CHANNEL,0);
    //digitalWrite(driveNeg, HIGH);
    ledcWrite(REV_CHANNEL, 200);
  } else {
    //digitalWrite(drivePos, LOW);
    ledcWrite(FWD_CHANNEL,0);
    //digitalWrite(driveNeg, LOW);
    ledcWrite(REV_CHANNEL, 0);
  } 

  if (GamePad.isStartPressed())
  {
    Serial.println("Key Pressed: Start");
  }

  if (GamePad.isSelectPressed())
  {
    Serial.println("Key Pressed: Select");
  }

  int a = GamePad.getAngle();
  // Uncomment to turn on noisy logging of gamepad angle
  // Serial.print("Angle: ");
  // Serial.println(a);
  int b = GamePad.getRadius();
  // Uncomment to turn on noisy logging of gamepad radius
  // Serial.print("Radius: ");
  // Serial.println(b);
  float c = GamePad.getXaxisData();
  // Uncomment to turn on noisy logging of gamepad x-axis
  // Serial.print("x_axis: ");
  // Serial.println(c);
  float d = GamePad.getYaxisData();
  // Uncomment to turn on noisy logging of gamepad y-axis
  // Serial.print("y_axis: ");
  // Serial.println(d);
}