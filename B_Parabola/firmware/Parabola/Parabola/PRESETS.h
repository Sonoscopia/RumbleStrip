/*
 * PRESETS.h
 *
 * Created: 02-06-2019 03:44:42
 *  Author: tiago
 */ 


#ifndef PRESETS_H_
#define PRESETS_H_

void generateIncrements();
uint8_t p; // preset shortcut for easy copy-paste
struct synthpreset{
	// SEQUENCER
	float bpm;
	float divisions; // beats per measure
	float noteduration; // percentage of clock_ms 1.0
	// OSCILLATORS
	float oscAfreq, oscBfreq, oscCfreq, oscDfreq; // oscillators frequencies in Hz
	// OscMix gains
	float oscAvol[SINC]; 
	float oscCvol[SINC];
	float noiseVol[SINC]; 
	// FM amount
	float oscAmod[SINC]; // OscB gain 
	float oscCmod[SINC]; // OscD gain 
	// ENVELOPES
	uint16_t envAatk, envBatk, envCatk, envDatk, envNatk, envFatk; // attack time in ms (max=11880)
	uint16_t envAdcy, envBdcy, envCdcy, envDdcy, envNdcy, envFdcy; // decay time in ms (max=11880)
	float envAsus, envBsus, envCsus, envDsus, envNsus, envFsus; // sustain value from 0. to 1.
	uint16_t envArel, envBrel, envCrel, envDrel, envNrel, envFrel; // release time in ms (max=11880)
	// LOWPASS FILTER
	float filterFreq[SINC]; // cutoff frequency
	float filterRes[SINC]; // filter resonance from 0.7 to 5.0
	float filterEnv[SINC]; // filter envelope amount
	// REVERB
	float revSize[SINC]; // reverb roomsize from 0. to 1.
	float revDamp[SINC]; // reverb hi freq damping from 0. to 1.
	float revSend[SINC]; // OscMix>Filter to Reverb from 0. to 1. 
	// DELAY
	float dlyFb[SINC]; // delay feedback amount from 0. to 1. (or bigger => lookout for clipping on SendB mixer)
	float dlyFactor[SINC]; // delay size factor relative to sequencer clock
	float dlySend[SINC]; // OscMix>Filter to Delay from 0. to 1.
	float dlyRev[SINC]; // Delay to Reverb send from 0. to 1.  
} preset[1];// => SET AMOUNT OF PRESETS MANUALLY !!!!

void loadPresets(){ // declare preset values
	// [0] is the starting value [SINC] is the last value (= min, max)
	
	// begin PRESET #1
	p = 0; // set preset 
	// SEQUENCER
	preset[p].bpm = 100.f;
	preset[p].divisions = 2.f; // beats per measure
	preset[p].noteduration = 0.125; // percentage of clock_ms 1.0
	// OSC FREQ
	preset[p].oscAfreq = 220.f;
	preset[p].oscBfreq = 32.f;
	preset[p].oscCfreq = 440.f;
	preset[p].oscDfreq = 64.f;
	// OSC MIX
	preset[p].oscAvol[0] = 1.f;
	preset[p].oscAvol[SINC-1] = 1.f;
	preset[p].oscCvol[0] = 0.f;
	preset[p].oscCvol[SINC-1] = 1.f;
	preset[p].noiseVol[0] = 0.f;
	preset[p].noiseVol[SINC-1] = 0.f;
	// FM MODULATION AMOUNT
	preset[p].oscAmod[0] = 0.f;
	preset[p].oscAmod[SINC-1] = 1.f;
	preset[p].oscCmod[0] = 0.f;
	preset[p].oscCmod[SINC-1] = 1.f;
	
	// ENVELOPE A
	preset[p].envAatk = 0;
	preset[p].envAdcy = 35;
	preset[p].envAsus = 0.5;
	preset[p].envArel = 100;
	// ENVELOPE B
	preset[p].envBatk = 0;
	preset[p].envBdcy = 35;
	preset[p].envBsus = 0.5;
	preset[p].envBrel = 100;
	// ENVELOPE C
	preset[p].envCatk = 0;
	preset[p].envCdcy = 35;
	preset[p].envCsus = 0.5;
	preset[p].envCrel = 100;
	// ENVELOPE D
	preset[p].envDatk = 0;
	preset[p].envDdcy = 35;
	preset[p].envDsus = 0.5;
	preset[p].envDrel = 100;
	// NOISE ENVELOPE
	preset[p].envNatk = 0;
	preset[p].envNdcy = 35;
	preset[p].envNsus = 0.5;
	preset[p].envNrel = 100;
	
	//LOWPASS FILTER
	preset[p].filterFreq[0] = 8000.f;
	preset[p].filterFreq[SINC-1] = 8000.f;
	preset[p].filterRes[0] = 0.707f;
	preset[p].filterRes[SINC-1] = 0.707f;
	preset[p].filterEnv[0] = 0.f; 
	preset[p].filterEnv[SINC-1] = 0.f; 
	// FILTER ENVELOPE
	preset[p].envFatk = 0;
	preset[p].envFdcy = 35;
	preset[p].envFsus = 0.5;
	preset[p].envFrel = 300;
	
	// REVERB
	preset[p].revSize[0] = 0.9;
	preset[p].revSize[SINC-1] = 0.1;
	preset[p].revDamp[0] = 0.7;
	preset[p].revDamp[SINC-1] = 0.1;
	preset[p].revSend[0] = 0.7;
	preset[p].revSend[SINC-1] = 0.1;
	// DELAY
	preset[p].dlyFb[0] = 0.9;
	preset[p].dlyFb[SINC-1] = 0.1;
	preset[p].dlyFactor[0] = 1.5;
	preset[p].dlyFactor[SINC-1] = 0.125;
	preset[p].dlySend[0] = 1.2;
	preset[p].dlySend[SINC-1] = 0.1;
	preset[p].dlyRev[0] = 0.8;
	preset[p].dlyRev[SINC-1] = 0.1;
	
	generateIncrements();
	numPresets++; // autocalc
	// end PRESET #1
	
	
	/* -----> INSERT PRESETS HERE <----- */ 
	
	


}

// This function generates increments between the arrays' min. and max values
void generateIncrements(){
	float inc;
	
	// OSC MIX
	// oscAvol
	inc = (preset[p].oscAvol[SINC-1] - preset[p].oscAvol[0]) / SINC;
	for (int i = 1; i < SINC-1; i++)
	{
		preset[p].oscAvol[i] = preset[p].oscAvol[i-1] + inc;
	}
	// oscCvol
	inc = (preset[p].oscCvol[SINC-1] - preset[p].oscCvol[0]) / SINC;
	for (int i = 1; i < SINC-1; i++)
	{
		preset[p].oscCvol[i] = preset[p].oscCvol[i-1] + inc;
	}
	// noiseVol
	inc = (preset[p].noiseVol[SINC-1] - preset[p].noiseVol[0]) / SINC;
	for (int i = 1; i < SINC-1; i++)
	{
		preset[p].noiseVol[i] = preset[p].noiseVol[i-1] + inc;
	}
	
	
	// FM MODULATION AMOUNT
	// oscAmod
	inc = (preset[p].oscAmod[SINC-1] - preset[p].oscAmod[0]) / SINC;
	for (int i = 1; i < SINC-1; i++)
	{
		preset[p].oscAmod[i] = preset[p].oscAmod[i-1] + inc;
	}
	// oscCmod
	inc = (preset[p].oscCmod[SINC-1] - preset[p].oscCmod[0]) / SINC;
	for (int i = 1; i < SINC-1; i++)
	{
		preset[p].oscCmod[i] = preset[p].oscCmod[i-1] + inc;
	}
	
	//LOWPASS FILTER
	// filterFreq
	inc = (preset[p].filterFreq[SINC-1] - preset[p].filterFreq[0]) / SINC;
	for (int i = 1; i < SINC-1; i++)
	{
		preset[p].filterFreq[i] = preset[p].filterFreq[i-1] + inc;
	}
	// filterRes
	inc = (preset[p].filterRes[SINC-1] - preset[p].filterRes[0]) / SINC;
	for (int i = 1; i < SINC-1; i++)
	{
		preset[p].filterRes[i] = preset[p].filterRes[i-1] + inc;
	}
	// filterEnv
	inc = (preset[p].filterEnv[SINC-1] - preset[p].filterEnv[0]) / SINC;
	for (int i = 1; i < SINC-1; i++)
	{
		preset[p].filterEnv[i] = preset[p].filterEnv[i-1] + inc;
	}
	
	// REVERB
	// revSize
	inc = (preset[p].revSize[SINC-1] - preset[p].revSize[0]) / SINC;
	for (int i = 1; i < SINC-1; i++)
	{
		preset[p].revSize[i] = preset[p].revSize[i-1] + inc;
	}
	// revDamp
	inc = (preset[p].revDamp[SINC-1] - preset[p].revDamp[0]) / SINC;
	for (int i = 1; i < SINC-1; i++)
	{
		preset[p].revDamp[i] = preset[p].revDamp[i-1] + inc;
	}
	// revSend
	inc = (preset[p].revSend[SINC-1] - preset[p].revSend[0]) / SINC;
	for (int i = 1; i < SINC-1; i++)
	{
		preset[p].revSend[i] = preset[p].revSend[i-1] + inc;
	}
	
	// DELAY
	// dlyFb
	inc = (preset[p].dlyFb[SINC-1] - preset[p].dlyFb[0]) / SINC;
	for (int i = 1; i < SINC-1; i++)
	{
		preset[p].dlyFb[i] = preset[p].dlyFb[i-1] + inc;
	}
	// dlyFactor
	inc = (preset[p].dlyFactor[SINC-1] - preset[p].dlyFactor[0]) / SINC;
	for (int i = 1; i < SINC-1; i++)
	{
		preset[p].dlyFactor[i] = preset[p].dlyFactor[i-1] + inc;
	}
	// dlySend
	inc = (preset[p].dlySend[SINC-1] - preset[p].dlySend[0]) / SINC;
	for (int i = 1; i < SINC-1; i++)
	{
		preset[p].dlySend[i] = preset[p].dlySend[i-1] + inc;
	}
	// dlyRev
	inc = (preset[p].dlyRev[SINC-1] - preset[p].dlyRev[0]) / SINC;
	for (int i = 1; i < SINC-1; i++)
	{
		preset[p].dlyRev[i] = preset[p].dlyRev[i-1] + inc;
	}
}




#endif /* PRESETS_H_ */