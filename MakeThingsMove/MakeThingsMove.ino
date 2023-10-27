#include "Controller.h"
#include "ControlFunctions.h"

// Robot name
#define ROBOT_NAME "grahamdroid"

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

Controller controller;

void setup() {
  // Initialize serial connection
  Serial.begin(115200);

  // Initialize controller
  controller.init(ROBOT_NAME);

  // Initialize robot
  init_robot();

  // Connect controller buttons to robot functions
  controller.registerCallback("triangle", driveForward);
  controller.registerCallback("x", driveBackward);
  controller.registerCallback("left", steerLeft);
  controller.registerCallback("right", steerRight);

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

}

/*
 * Run the controller's update() function to allow it to 
 * check for button presses and perform the associated robot actions.
 */
void loop() {
  #if AUDIO_ENABLED
    player.copy(); // refresh audio
  #endif
  controller.update();
}