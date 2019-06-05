/*
 * Plates.ino
 *
 * Created: 6/5/2019 11:17:52 PM
 * Author: tiago
 * https://github.com/Sonoscopia/RumbleStrip
 */ 

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   SineWave;          //xy=176,361
AudioOutputI2S           LineOut;           //xy=368,360
AudioConnection          patchCord1(SineWave, 0, LineOut, 0);
AudioConnection          patchCord2(SineWave, 0, LineOut, 1);
AudioControlSGTL5000     AudioShield;     //xy=192,452
// GUItool: end automatically generated code

void setup()
{
	AudioMemory(10);
	
	AudioShield.enable();
	AudioShield.volume(0.707);
	
	SineWave.amplitude(0.99999);
	SineWave.frequency(220);
	  

}

void loop()
{

	  

}
