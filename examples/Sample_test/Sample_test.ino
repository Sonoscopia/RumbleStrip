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
AudioPlaySdWav           playSdWav;     //xy=274,279
AudioOutputI2S           i2s1;           //xy=458,280
AudioConnection          patchCord1(playSdWav, 0, i2s1, 0);
AudioConnection          patchCord2(playSdWav, 1, i2s1, 1);
AudioControlSGTL5000     AudioShield;     //xy=269,175
// GUItool: end automatically generated code


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
  delay(1000);
}

void loop() {
  if(!playSdWav.isPlaying()){
    playSdWav.play("SAMPLE1.WAV");
    delay(10); // wait for library to parse WAV info
  }
}
