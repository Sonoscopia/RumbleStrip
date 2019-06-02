/*
 * GLOBALS.h
 *
 * Created: 02-06-2019 01:12:56
 *  Author: tiago
 */ 


#ifndef GLOBALS_H_
#define GLOBALS_H_

// SYSTEM
#define DEBUG 1 // print messages to console?
#define WAIT 1000 // setup wait time in ms
// VOLUMES
#define UGAIN 1.0f // unity gain 
#define MASTERVOL 0.707f
#define MAINTRACKS 0.25f // 4 tracks at MainMix normalize at 0.25
#define SENDATRACKS 0.333f // 3 tracks at SendA normalize at 0.33
#define SENDBTRACKS 0.333f // 3 tracks at SendB normalize at 0.33
#define OSCTRACKS 0.333f // 3 tracks at OscMix normalize at 0.33 
// OUTPUT
#define HPF 120.f // Highpass frequency
#define HPQ 0.707f // Highpass Q
#define SHELFFREQ 12000.f // Highshelf frequency
#define SHELFGAIN -12.f // Highshelf attenuation
// SOUND
#define LPFRANGE 7.f // Lowpass octaveControl (from 0. to 7.)
#define MINDELAYSIZE 10 // Min. delay size
#define MAXDELAYFBK 0.9f // Max. delay feedback
#define MAXREVSIZE 0.9f // Max. reverb size
#define MINREVDAMP 0.1f // Min. reverb damping
// SEQUENCER
#define RPM 2.5f // AC motor RPM 2.5 to 3.0
#define ONEHUNDRED 100 // used for probabilities
#define  PROBMIN 10
#define PROBMAX 100
#define PROBINC 5

// Composition
uint8_t numPresets = 0; // value is auto-updated in PRESETS.h
uint8_t curPreset;
//uint8_t tension = 0; // from 0 to 100
int8_t prob = PROBMIN; // current probability from 0 to 100
int8_t direction = 1; // 1 (up) or -1 (down)
 
boolean synthsilence; 
boolean samplersilence; 
uint16_t clock_ms; // sequencer clock in ms
 
// Sound
uint16_t delaytime; // delay time in ms
uint16_t delayfbk; // feedback level from 0. to 1.
float revsize; // reverb room size from 0. to 1. 
float revdamp; // reverb hi freq damping from 0. to 1. 

#endif /* GLOBALS_H_ */