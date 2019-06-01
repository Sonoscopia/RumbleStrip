#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <Metro.h> // include Metro Lib

// GUItool: begin automatically generated code
AudioSynthNoiseWhite     noise;         //xy=73,263
AudioEffectEnvelope      env;      //xy=204,267
AudioMixer4              mixer1;         //xy=369,270
AudioEffectFreeverb      freeverb;      //xy=377,352
AudioOutputI2S           Output;         //xy=613,277
AudioConnection          patchCord1(noise, env);
AudioConnection          patchCord2(env, 0, mixer1, 0);
AudioConnection          patchCord3(env, freeverb);
AudioConnection          patchCord4(mixer1, 0, Output, 0);
AudioConnection          patchCord5(mixer1, 0, Output, 1);
AudioConnection          patchCord6(freeverb, 0, mixer1, 1);
AudioControlSGTL5000     AudioShield;     //xy=85,33
// GUItool: end automatically generated code
Metro clock1 = Metro(250);
byte prob = 50; 


void setup(){
  AudioMemory(320);
  
  AudioShield.enable();
  AudioShield.volume(0.707);
  
  noise.amplitude(0.5);
  
  env.attack(0);
  env.decay(25);
  env.sustain(0.0);
  env.release(5);

  mixer1.gain(0, 0.5);
  mixer1.gain(0, 0.5);

  freeverb.roomsize(0.33);
  freeverb.damping(0.66);
  
  delay(1000);
}

void loop(){
  /*if(!env.isActive()){
    env.noteOn();
    delay(30);
    env.noteOff();
    delay(3000);
  }*/
  if(clock1.check()){
  byte stepRnd = random(100);
    if(stepRnd < prob){
      env.noteOn();
      delay(30);
      env.noteOff();
    }
  }
}
