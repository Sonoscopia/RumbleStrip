/*
 * GLOBALS.h
 *
 * Created: 06-06-2019 00:50:03
 *  Author: tiago
 */ 


#ifndef GLOBALS_H_
#define GLOBALS_H_

// SYSTEM
#define DEBUG 1 // print messages to console?
#define WAIT 3000 // setup wait time in ms
#define TIMERINC 1 
// VOLUMES
#define UGAIN 1.f // unity gain
#define HGAIN 0.5f // half gain (~ -6dB)
#define MASTERVOL 0.707f
#define SYNTHMIX 0.333f // 3 tracks at SynthMix1&2 normalize at 0.33
#define TRACK1 0.891251f // Bass Shaker volume (-1dB)
#define TRACK2 0.158489f // Treble shakers volume (-16dB)
#define DRY 0.f 
#define WET 1.f
// FX
#define TAP 0 // delay tap #0
#define SR 44100 // sample rate
#define BD 16 // bit depth
// EQ - TRACK 1
#define HP1 30 // track1 hi pass freq
#define HP1RES 0.707 // track1 hi pass resonance 
#define LP1 12000 // track1 lo pass freq
#define LP1RES 0.707 // track1 lo pass resonance
// EQ - TRACK 2
#define HP2 75 // track2 hi pass freq
#define HP2RES 0.707 // track2 hi pass resonance
#define LP2 16000 // track2 lo pass freq
#define LP2RES 0.707 // track2 lo pass resonance

// Composition
uint8_t numPresets = 0; // value is auto-updated in PRESETS.h
uint8_t curPreset;
unsigned long int clockTimer = 0; // max = 4294967295 which is more than enough

#endif /* GLOBALS_H_ */