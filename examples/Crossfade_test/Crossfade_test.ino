#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// Use these with the Teensy Audio Shield
#define SDCARD_CS_PIN    10
#define SDCARD_MOSI_PIN  7
#define SDCARD_SCK_PIN   14


// GUItool: begin automatically generated code
AudioPlaySdWav           playSdWav1;     //xy=274,279
AudioPlaySdWav           playSdWav2;     //xy=274,279
AudioEffectFade          fade1;          //xy=352,117
AudioEffectFade          fade2; //xy=356,173
AudioMixer4              mixer;         //xy=538,118
AudioOutputI2S           i2s1;           //xy=458,280
AudioConnection          patchCord1(playSdWav1, 0, fade1, 0);
AudioConnection          patchCord2(fade1, 0, mixer, 0);
AudioConnection          patchCord3(playSdWav2, 0, fade2, 0);
AudioConnection          patchCord4(fade2, 0, mixer, 1);
AudioConnection          patchCord5(mixer, 0, i2s1, 0);
AudioConnection          patchCord6(mixer, 0, i2s1, 1);
AudioControlSGTL5000     AudioShield;     //xy=269,175
// GUItool: end automatically generated code

boolean dir = false; 

void setup() {
  Serial.begin(9600);
  
  AudioMemory(8); 
  
  AudioShield.enable();
  AudioShield.volume(0.707);

  SPI.setMOSI(SDCARD_MOSI_PIN);
  SPI.setSCK(SDCARD_SCK_PIN);

   if (!(SD.begin(SDCARD_CS_PIN))) {
    while (1) {
      Serial.println("Unable to access the SD card");
      delay(500);
    }
  }

  mixer.gain(0, 0.5);
  mixer.gain(1, 0.5);

  fade1.fadeIn(5);
  fade2.fadeIn(5);
  delay(1000);
}

void loop() {
  if(!playSdWav1.isPlaying()){
    dir = !dir;
    if(dir){
      fade1.fadeIn(5000);
      fade2.fadeOut(5000);
    }
    else{
      fade1.fadeOut(5000);
      fade2.fadeIn(5000);
    }
    playSdWav1.play("SAMPLE1.WAV");
    delay(10); // wait for library to parse WAV info
  }
  if(!playSdWav2.isPlaying()){
    playSdWav2.play("SAMPLE2.WAV");
    delay(10); // wait for library to parse WAV info
  }
}
