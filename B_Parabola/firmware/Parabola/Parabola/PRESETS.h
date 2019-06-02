/*
 * PRESETS.h
 *
 * Created: 02-06-2019 03:44:42
 *  Author: tiago
 */ 


#ifndef PRESETS_H_
#define PRESETS_H_

/*#include <iostream>
#include <string>
#include <sstream>*/

struct synthpreset{
	// SEQUENCER
	float bpm;
	float divisions; // beats per measure
	float noteduration; // percentage of clock_ms 1.0
	// OSCILLATORS
	float oscAfreq, oscBfreq, oscCfreq, oscDfreq; // oscillators frequencies in Hz
	float oscAmodMin, oscCmodMin; // OscB gain and OscD gain respectively
	float oscAmodMax, oscCmodMax; // OscB gain and OscD gain respectively
	float oscAvol, oscCvol, noiseVol; // OscMix gains
	// ENVELOPES
	uint16_t envAatk, envBatk, envCatk, envDatk, envNatk, envFatk; // attack time in ms (max=11880)
	uint16_t envAdcy, envBdcy, envCdcy, envDdcy, envNdcy, envFdcy; // decay time in ms (max=11880)
	float envAsus, envBsus, envCsus, envDsus, envNsus, envFsus; // sustain value from 0. to 1.
	uint16_t envArel, envBrel, envCrel, envDrel, envNrel, envFrel; // release time in ms (max=11880)
	// LOWPASS FILTER
	float filterFreq; // cutoff frequency
	float filterRes; // filter resonance from 0.7 to 5.0
	float filterEnv; // filter envelope amount
} preset[1];// => SET AMOUNT OF PRESETS MANUALLY !!!!

void loadPresets(){ // declare preset values
	// begin PRESET #1
	int p = 0; // set preset num
	// SEQUENCER
	preset[curPreset].bpm = 100.f;
	preset[curPreset].divisions = 4.f; // beats per measure
	preset[curPreset].noteduration = 0.5; // percentage of clock_ms 1.0
	// OSC FREQ
	preset[p].oscAfreq = 220.f;
	preset[p].oscBfreq = 220.f;
	preset[p].oscCfreq = 220.f;
	preset[p].oscDfreq = 220.f;
	// FM MODULATION AMOUNT
	preset[p].oscAmodMin = 0.f;
	preset[p].oscAmodMax = 1.f;
	preset[p].oscCmodMin = 0.f;
	preset[p].oscCmodMax = 1.f;
	// ENVELOPE A
	preset[p].envAatk = 0;
	preset[p].envAdcy = 35;
	preset[p].envAsus = 0.5;
	preset[p].envArel = 300;
	// ENVELOPE B
	preset[p].envBatk = 0;
	preset[p].envBdcy = 35;
	preset[p].envBsus = 0.5;
	preset[p].envBrel = 300;
	// ENVELOPE C
	preset[p].envCatk = 0;
	preset[p].envCdcy = 35;
	preset[p].envCsus = 0.5;
	preset[p].envCrel = 300;
	// ENVELOPE D
	preset[p].envDatk = 0;
	preset[p].envDdcy = 35;
	preset[p].envDsus = 0.5;
	preset[p].envDrel = 300;
	// NOISE ENVELOPE
	preset[p].envNatk = 0;
	preset[p].envNdcy = 35;
	preset[p].envNsus = 0.5;
	preset[p].envNrel = 300;
	// MIX
	preset[p].oscAvol = 1.f;
	preset[p].oscCvol = 0.f;
	preset[p].noiseVol = 0.f;
	//LOWPASS FILTER
	preset[p].filterFreq = 8000.f;
	preset[p].filterRes = 0.707f;
	preset[p].filterEnv = 0.f; 
	// FILTER ENVELOPE
	preset[p].envFatk = 0;
	preset[p].envFdcy = 35;
	preset[p].envFsus = 0.5;
	preset[p].envFrel = 300;
	
	numPresets++; // autocalc
	// end PRESET #1
}





#endif /* PRESETS_H_ */