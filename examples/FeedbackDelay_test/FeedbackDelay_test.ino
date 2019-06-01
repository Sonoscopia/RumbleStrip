#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   OscA;           //xy=63,267
AudioEffectEnvelope      env;      //xy=204,267
AudioEffectDelay         delay1;         //xy=444,421
AudioMixer4              mixer1;         //xy=445,263
AudioOutputI2S           Output;         //xy=764,219
AudioConnection          patchCord1(OscA, env);
AudioConnection          patchCord2(env, 0, mixer1, 0);
AudioConnection          patchCord3(delay1, 0, Output, 0);
AudioConnection          patchCord4(delay1, 0, mixer1, 3);
AudioConnection          patchCord5(delay1, 0, Output, 1);
AudioConnection          patchCord6(mixer1, delay1);
AudioControlSGTL5000     AudioShield;     //xy=85,33
// GUItool: end automatically generated code





void setup() {
  AudioMemory(320);
  
  AudioShield.enable();
  AudioShield.volume(0.9);
  
  OscA.amplitude(0.25);
  OscA.frequency(220);

  env.attack(10);
  env.decay(100);
  env.sustain(0.66);
  env.release(100);

  delay1.delay(0, 500); // set delay size
  // disable unnecessary delay channels
  /*for(int i = 1; i < 8; i++){
    delay1.disable(i);
  }*/
  mixer1.gain(0, 0.4); // dry vol
  mixer1.gain(3, 0.8); // feedback 

  delay(1000);
}

void loop() {
  if(!env.isActive()){
    env.noteOn();
    delay(100);
    env.noteOff();
    delay(10000);
  }
}
