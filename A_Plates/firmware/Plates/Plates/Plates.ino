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
#include <Metro.h>

// my includes
#include "GLOBALS.h"
#include "AudioRouting.h"
#include "PRESETS.h"
#include "Voices.h"


void setup()
{
	if(DEBUG) Serial.begin(9600);
	randomSeed(analogRead(0));
	
	AudioMemory(360);// set available buffers
	initAudioObjects();
	loadPresets();
	
	delay(WAIT);
}

void loop()
{
	delay(TIMERINC); // 1ms delay used to update clockTimer 
	clockTimer+=TIMERINC; 
	voice1TriggerEvents(clockTimer);
	voice2TriggerEvents(clockTimer);
	if(clockTimer > preset[curPreset].sectionDuration) {
		newPreset();
	}
}

void newPreset(){
	curPreset = random(numPresets);
	voice1LoadPreset(curPreset);
	voice2LoadPreset(curPreset);
	resetTriggers();
}