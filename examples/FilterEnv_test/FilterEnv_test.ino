#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthNoiseWhite     Noise;         //xy=214,56
AudioSynthWaveformDc     dc1;            //xy=225,133
AudioEffectEnvelope      FilterEnv; //xy=369,130
AudioFilterStateVariable Lowpass;        //xy=552,63
AudioOutputI2S           Output;         //xy=718.4285774230957,62.42856979370117
AudioConnection          patchCord1(Noise, 0, Lowpass, 0);
AudioConnection          patchCord2(dc1, FilterEnv);
AudioConnection          patchCord3(FilterEnv, 0, Lowpass, 1);
AudioConnection          patchCord4(Lowpass, 0, Output, 0);
AudioConnection          patchCord5(Lowpass, 0, Output, 1);
AudioControlSGTL5000     AudioShield;     //xy=727.8571472167969,110.4285659790039
// GUItool: end automatically generated code



void setup() {
  AudioMemory(80);
  
  AudioShield.enable();
  AudioShield.volume(0.707);
  
  Noise.amplitude(0.2);
  Lowpass.frequency(40);
  Lowpass.resonance(5.0);
  Lowpass.octaveControl(7);

  dc1.amplitude(1.0);
  FilterEnv.attack(250);
  FilterEnv.decay(250);
  FilterEnv.sustain(0.5);
  FilterEnv.release(1000);
  
  delay(1000);
}

void loop() {
  if(!FilterEnv.isActive()){
    FilterEnv.noteOn();
    delay(1000);
    FilterEnv.noteOff();
    delay(2000);
  }
}
