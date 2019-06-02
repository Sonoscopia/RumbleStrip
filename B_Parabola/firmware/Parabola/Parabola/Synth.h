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

void synthSetPreset(uint8_t p){
	// oscillators' frequencies
	OscA.frequency(preset[p].oscAfreq);
	OscB.frequency(preset[p].oscBfreq);
	OscC.frequency(preset[p].oscCfreq);
	OscD.frequency(preset[p].oscDfreq);
	// FM modulation amount (start with min. value) 
	OscB.amplitude(preset[p].oscAmodMin);
	OscD.amplitude(preset[p].oscCmodMin);
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
	// Oscillators+Noise Mix
	OscMix.gain(0, preset[p].oscAvol);
	OscMix.gain(1, preset[p].oscCvol);
	OscMix.gain(2, preset[p].noiseVol);
	// Lowpass Filter
	Lowpass.frequency(preset[p].filterFreq);
	Lowpass.resonance(preset[p].filterRes);
	FilterEnvOffset.amplitude(preset[p].filterEnv);
	// Filter Envelope
	FilterEnv.attack(preset[p].envFatk);
	FilterEnv.decay(preset[p].envFdcy);
	FilterEnv.sustain(preset[p].envFsus);
	FilterEnv.release(preset[p].envFrel);
}


#endif /* SYNTH_H_ */