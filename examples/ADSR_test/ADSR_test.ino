#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   OscA;           //xy=73,253
AudioEffectEnvelope      env;      //xy=232,250
AudioOutputI2S           Output;         //xy=535,245
AudioConnection          patchCord1(OscA, env);
AudioConnection          patchCord2(env, 0, Output, 0);
AudioConnection          patchCord3(env, 0, Output, 1);
AudioControlSGTL5000     AudioShield;     //xy=85,33
// GUItool: end automatically generated code


void setup() {
  AudioMemory(10);
  
  AudioShield.enable();
  AudioShield.volume(0.707);
  
  OscA.amplitude(0.99999);
  OscA.frequency(220);

  env.attack(0);
  env.decay(200);
  env.sustain(0.33);
  env.release(2000);
}

void loop() {
  if(!env.isActive()){
    env.noteOn();
    delay(200);
    env.noteOff();
  }
}
