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


void setup(){
  if(DEBUG) Serial.begin(9600);
  
  randomSeed(analogRead(A0)); // set random seed
  
  AudioMemory(180);// set available buffers
  initPresets(); // instantiate presets (must go before initAudioObjects)
  initAudioObjects(); 
  
  newPreset();
  masterVolumes(1., 0., 0., 0.);
  /*Reverb.damping(0.1);
  Reverb.roomsize(0.7);
  sendSynthToA(1.f);
  sendSynthToB(1.f);
  delayFeedback(1.3f);
  sendDelayToA(1.f);
  FbkDelay.delay(0, 500);*/
  
  // tempo init
  clockmotor = new Metro( bpm2ms(RPM) );
  clock_ms = bpmclock2ms(bpm, divisions);
  clockseq = new Metro( 250 );
  
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
    if (prob >= PROBMAX)
    {
      direction = -1;
      prob = PROBMAX;
    }
    if (prob <= PROBMIN)
    {
      direction = 1; 
      prob = PROBMIN; 
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
      uint16_t notedur = noteduration2ms(clock_ms, noteduration);
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
  curPreset = random(numPresets); // selec random preset
  synthSetPreset(0);
}