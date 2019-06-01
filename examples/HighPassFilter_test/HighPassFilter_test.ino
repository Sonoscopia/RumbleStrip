#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthNoiseWhite     noise;         //xy=72,267
AudioFilterBiquad        hpf;        //xy=246,261
AudioOutputI2S           Output;         //xy=613,277
AudioConnection          patchCord1(noise, hpf);
AudioConnection          patchCord2(hpf, 0, Output, 0);
AudioConnection          patchCord3(hpf, 0, Output, 1);
AudioControlSGTL5000     AudioShield;     //xy=85,33
// GUItool: end automatically generated code

void setup() {
  AudioMemory(320);
  
  AudioShield.enable();
  AudioShield.volume(0.707);
  
  noise.amplitude(0.5);
  hpf.setHighpass(0, 4000, 0.707);
}

void loop() {
  

}
