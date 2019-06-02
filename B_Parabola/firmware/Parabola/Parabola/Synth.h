/*
 * Synth.h
 *
 * Created: 02-06-2019 04:26:53
 *  Author: tiago
 *
 * ( 4-Op FM (B->A + D->C) + Noise) to Lowpass filter
 */ 


#ifndef SYNTH_H_
#define SYNTH_H_

void synthNoteOn(){
	EnvA.noteOn();
	EnvB.noteOn();
	EnvC.noteOn();
	EnvD.noteOn();
	NoiseEnv.noteOn();
	FilterEnv.noteOn();
	/*if(!EnvA.isActive()) EnvA.noteOn();
	if(!EnvB.isActive()) EnvB.noteOn();
	if(!EnvC.isActive()) EnvC.noteOn();
	if(!EnvD.isActive()) EnvD.noteOn();
	if(!NoiseEnv.isActive()) NoiseEnv.noteOn();
	if(!FilterEnv.isActive()) FilterEnv.noteOn();*/
}

void synthNoteOff(){
	EnvA.noteOff();
	EnvB.noteOff();
	EnvC.noteOff();
	EnvD.noteOff();
	NoiseEnv.noteOff();
	FilterEnv.noteOff();
}

void synthSetVols(float _oscA, float _oscC, float _noise){
	OscMix.gain(0, _oscA*OSCTRACKS);
	OscMix.gain(1, _oscC*OSCTRACKS);
	OscMix.gain(2, _noise*OSCTRACKS);
}

void synthLoadPreset(uint8_t p){ // run this function once when a new sequence is generated
	// STATIC VARIABLES
	// oscillators' frequencies
	OscA.frequency(preset[p].oscAfreq);
	OscB.frequency(preset[p].oscBfreq);
	OscC.frequency(preset[p].oscCfreq);
	OscD.frequency(preset[p].oscDfreq);
	// Envelope A
	EnvA.attack(preset[p].envAatk);
	EnvA.decay(preset[p].envAdcy);
	EnvA.sustain(preset[p].envAsus);
	EnvA.release(preset[p].envArel);
	// Envelope B
	EnvB.attack(preset[p].envBatk);
	EnvB.decay(preset[p].envBdcy);
	EnvB.sustain(preset[p].envBsus);
	EnvB.release(preset[p].envBrel);
	// Envelope C
	EnvC.attack(preset[p].envCatk);
	EnvC.decay(preset[p].envCdcy);
	EnvC.sustain(preset[p].envCsus);
	EnvC.release(preset[p].envCrel);
	// Envelope D
	EnvD.attack(preset[p].envDatk);
	EnvD.decay(preset[p].envDdcy);
	EnvD.sustain(preset[p].envDsus);
	EnvD.release(preset[p].envDrel);
	// Noise Envelope
	NoiseEnv.attack(preset[p].envNatk);
	NoiseEnv.decay(preset[p].envNdcy);
	NoiseEnv.sustain(preset[p].envNsus);
	NoiseEnv.release(preset[p].envNrel);
	// Filter Envelope
	FilterEnv.attack(preset[p].envFatk);
	FilterEnv.decay(preset[p].envFdcy);
	FilterEnv.sustain(preset[p].envFsus);
	FilterEnv.release(preset[p].envFrel);
	
}

void synthUpdateParams(uint8_t p, uint8_t sp){ // run this function every sequencer increment (p=preset, s=seq position)
	// VARIABLES CHANGED BY SEQUENCER POSITION
	
	// Oscillators+Noise Mix
	OscMix.gain(0, preset[p].oscAvol[sp]);
	OscMix.gain(1, preset[p].oscCvol[sp]);
	OscMix.gain(2, preset[p].noiseVol[sp]);
	
	// FM modulation amount
	OscB.amplitude(preset[p].oscAmod[sp]);
	OscD.amplitude(preset[p].oscCmod[sp]);
	
	// Lowpass Filter
	Lowpass.frequency(preset[p].filterFreq[sp]);
	Lowpass.resonance(preset[p].filterRes[sp]);
	FilterEnvOffset.amplitude(preset[p].filterEnv[sp]);
	
	// Reverb 
	Reverb.roomsize(preset[p].revSize[sp]);
	Reverb.damping(preset[p].revDamp[sp]);
	SendA.gain(0, preset[p].revSend[sp]);
	
	// Delay
	SendB.gain(3, preset[p].dlyFb[sp]);
	FbkDelay.delay(DLYTAP, preset[p].dlyFactor[sp] * clock_ms);
	SendB.gain(0, preset[p].dlySend[sp]);
	SendA.gain(3, preset[p].dlyRev[sp]);
}

#endif /* SYNTH_H_ */