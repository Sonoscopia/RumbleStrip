/*
 * Parabola.ino
 *
 * Created: 5/31/2019 11:11:02 PM
 * Author: tiago
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
#include "Utilities.h"
#include "Synth.h"
//#include "Sampler.h"
#include "Master.h"

Metro* clockmotor;
Metro* clockseq;
uint8_t seqpos = 0; // sequencer incremental position 


void setup(){
  if(DEBUG) Serial.begin(9600);
  
  randomSeed(analogRead(A0)); // set random seed
  
  AudioMemory(360);// set available buffers
  loadPresets(); // load ALL presets (must go before initAudioObjects)
  newPreset(); // load new preset
  synthUpdateParams(curPreset, 0);
  initAudioObjects(); //  
	  
  //
  masterVolumes(0.8, 0., 0.8, 0.8);
  Reverb.damping(0.1);
  Reverb.roomsize(0.8);
  sendSynthToA(1.f);
  sendSynthToB(1.f);
  delayFeedback(1.f);
  sendDelayToA(1.f);
  FbkDelay.delay(0, clock_ms);
  
  
  delay(WAIT);
  if (DEBUG)
  {
    printMaxMemUsage();
    Serial.print("clock_ms: ");
    Serial.println(clock_ms);
  }
}

void loop(){
  
  if( clockmotor->check() && clockseq->check() ){
    prob += (direction * PROBINC);
	seqpos += direction; 
	synthUpdateParams(curPreset, seqpos);
    
	// reverse direction 
	if (prob >= PROBMAX)
    {
      direction = -1;
      prob = PROBMAX;
    }
    if (prob <= PROBMIN)
    {
      direction = 1; 
      prob = PROBMIN; 
	  newPreset(); 
    }
    
	
    if(DEBUG){ 
      Serial.println("seq advance");
      Serial.print("direction: ");
      Serial.println(direction);
      Serial.print("prob: ");
      Serial.println(prob);
    }
  } 
  
  
  if( clockseq->check() ){
    uint8_t stepprob = random(ONEHUNDRED);
    
    if (stepprob < prob)
    {
      //NOTE ON
      synthNoteOn();
      if(DEBUG){
        printMemUsage();
        Serial.print("step prob: ");
        Serial.println(stepprob);
      }
      // NOTE OFF 
      uint16_t notedur = noteduration2ms(clock_ms, preset[curPreset].noteduration);
      delay( 25 );
      if (DEBUG)
      {
        Serial.print("notedur: ");
        Serial.println(notedur);
      }
      synthNoteOff(); 
    } 
  }
}

void newPreset(){
  curPreset = random(numPresets); // select random preset
  synthLoadPreset(curPreset);
  // set tempo
  clockmotor = new Metro( bpm2ms(RPM) );
  clock_ms = bpmclock2ms(preset[curPreset].bpm, preset[curPreset].divisions);
  clockseq = new Metro( clock_ms );
}
