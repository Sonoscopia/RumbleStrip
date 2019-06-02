#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthNoiseWhite     noise1;         //xy=163,154
AudioFilterBiquad        biquad1;        //xy=353,189
AudioOutputI2S           Output;           //xy=603,191
AudioConnection          patchCord1(noise1, biquad1);
AudioConnection          patchCord2(biquad1, 0, Output, 0);
AudioConnection          patchCord3(biquad1, 0, Output, 1);
AudioControlSGTL5000     AudioShield;    //xy=292.3333282470703,38.333335876464844
// GUItool: end automatically generated code

float dBattenuation = -12; 
float freq = 4000;

void setup() {
  AudioMemory(80);

  AudioShield.enable();
  AudioShield.volume(0.707);
  
  noise1.amplitude(0.5);
  biquad1.setHighShelf(0, freq, dBattenuation); 

}

void loop() {
  // put your main code here, to run repeatedly:

}
