/*
 * Voice1.h
 *
 * Created: 06-06-2019 02:14:10
 *  Author: tiago
 */ 


#ifndef VOICE1_H_
#define VOICE1_H_

void voice1LoadPreset(uint8_t p){ // preset number
	// synth A
	CarrierA1.frequency(preset[p].carrierA1Freq);
	ModulatorA1.frequency(preset[p].modA1Freq);
	// synth B
	CarrierB1.frequency(preset[p].carrierB1Freq);
	ModulatorB1.frequency(preset[p].modB1Freq);
	// noise
	BP1.frequency(preset[p].bp1freq);
	BP1.resonance(preset[p].bp1res);
	BP1.octaveControl(preset[p].bp1AmtOctaves);
	FilterEnvAmt1.amplitude(preset[p].bp1EnvAmt);
	// synth mix
	SynthMix1.gain(0, preset[p].synthA1vol * SYNTHMIX);
	SynthMix1.gain(1, preset[p].synthB1vol * SYNTHMIX);
	SynthMix1.gain(2, preset[p].synthN1vol * SYNTHMIX);
	// delay
	Delay1.delay(TAP, preset[p].delay1size);
	Feedback1.gain(3, preset[p].delay1fbk);
	// fx mix
	FXMix1.gain(0, 1.f - preset[p].fxmix1);
	FXMix1.gain(1, preset[p].fxmix1);
}

void voice2LoadPreset(uint8_t p){ // preset number
	// synth A
	CarrierA2.frequency(preset[p].carrierA2Freq);
	ModulatorA2.frequency(preset[p].modA2Freq);
	// synth B
	CarrierB2.frequency(preset[p].carrierB2Freq);
	ModulatorB2.frequency(preset[p].modB2Freq);
	// noise
	BP2.frequency(preset[p].bp2freq);
	BP2.resonance(preset[p].bp2res);
	BP2.octaveControl(preset[p].bp2AmtOctaves);
	FilterEnvAmt2.amplitude(preset[p].bp2EnvAmt);
	// synth mix
	SynthMix2.gain(0, preset[p].synthA2vol * SYNTHMIX);
	SynthMix2.gain(1, preset[p].synthB2vol * SYNTHMIX);
	SynthMix2.gain(2, preset[p].synthN2vol * SYNTHMIX);
	// bit crusher
	BitCrush2.bits(preset[p].crush2bits);
	BitCrush2.sampleRate(preset[p].crush2sr);
	// fx mix
	FXMix2.gain(0, 1.f - preset[p].fxmix2);
	FXMix2.gain(1, preset[p].fxmix2);
}

#endif /* VOICE1_H_ */