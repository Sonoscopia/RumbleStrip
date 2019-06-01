#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine1;          //xy=180,289
AudioSynthWaveformSineModulated sine_fm1;       //xy=329,288
AudioOutputI2S           i2s1;           //xy=497,288
AudioConnection          patchCord1(sine1, sine_fm1);
AudioConnection          patchCord2(sine_fm1, 0, i2s1, 0);
AudioConnection          patchCord3(sine_fm1, 0, i2s1, 1);
AudioControlSGTL5000     AudioShield;     //xy=269,175
// GUItool: end automatically generated code


void setup() {
  AudioMemory(10);
  
  AudioShield.enable();
  AudioShield.volume(0.707);

  sine1.amplitude(0.99999);
  sine1.frequency(220);
  sine_fm1.amplitude(0.99999);
  sine_fm1.frequency(220);
}

void loop() {
  
}
