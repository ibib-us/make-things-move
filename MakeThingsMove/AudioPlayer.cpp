#include <Arduino.h>

/*
 * Audio player logic.
 */

// Uncomment the following line to enable audio
// #define AUDIO_ENABLED

#ifdef AUDIO_ENABLED
  #include "AudioPlayer.h"
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

void init_audio() {
  #ifdef AUDIO_ENABLED
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

void update_audio() {
  #ifdef AUDIO_ENABLED
    player.copy(); // refresh audio
  #endif
}