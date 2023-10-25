/*
   Gamepad module provides three different mode namely Digital, JoyStick and Accerleometer.

   You can reduce the size of library compiled by enabling only those modules that you want to
   use. For this first define CUSTOM_SETTINGS followed by defining INCLUDE_modulename.

   Explore more on: https://thestempedia.com/docs/dabble/game-pad-module/
*/

// Robot name
# define ROBOT_NAME "grahamdroid"

// Gamepad class 
#include "Gamepad.h"

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

Gamepad gamepad;

void downButtonCallback(bool pressed) {
    Serial.print("Button \"down\" was ");
    if (pressed) {
        Serial.print("pressed");
    } else {
        Serial.print("released");
    }
    Serial.println();
}

void setup() {
  gamepad.init(ROBOT_NAME);
  gamepad.registerCallback("down", downButtonCallback);

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
  gamepad.update();
}