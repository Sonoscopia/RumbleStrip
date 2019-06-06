/*
 * PRESETS.h
 *
 * Created: 06-06-2019 01:32:42
 *  Author: tiago
 */ 


#ifndef PRESETS_H_
#define PRESETS_H_

uint8_t p; // preset shortcut for easy copy-paste
struct synthpreset{
	// TRACK_1 
	// synth A1
	float carrierA1Freq;
	float carrierA1FadeTime;
	float modA1Freq;
	float modA1Amt; // modulation amount from 0. to 1.
	float modA1FadeTime;
	// synth B1
	float carrierB1Freq;
	float carrierB1FadeTime;
	float modB1Freq;
	float modB1Amt; // modulation amount from 0. to 1.
	float modB1FadeTime;
	// synth Noise1
	float bp1freq;
	float bp1res;
	float bp1AmtOctaves; //Range is 0 to 7 octaves
	float bp1EnvAmt;
	float bp1EnvFadeTime;
	// SynthMix1 
	float synthA1vol;
	float synthB1vol;
	float synthN1vol;
	// FX1
	float delay1size;
	float delay1fbk;
	float fxmix1; // 0 = synth, 100 = fx
	
	// TRACK_2
	// synth A2
	float carrierA2Freq;
	float carrierA2FadeTime;
	float modA2Freq;
	float modA2Amt; // modulation amount from 0. to 1.
	float modA2FadeTime;
	// synth B2
	float carrierB2Freq;
	float carrierB2FadeTime;
	float modB2Freq;
	float modB2Amt; // modulation amount from 0. to 1.
	float modB2FadeTime;
	// synth Noise2
	float bp2freq;
	float bp2res;
	float bp2AmtOctaves; //Range is 0 to 7 octaves
	float bp2EnvAmt;
	float bp2EnvFadeTime;
	// SynthMix2
	float synthA2vol;
	float synthB2vol;
	float synthN2vol;
	// FX2
	uint8_t crush2bits; // bit depth from 1 to 16
	uint16_t crush2sr; // xsampleRate sets the frequency, from 1 to 44100Hz
	float fxmix2; // 0 = synth, 100 = fx
	
	 
} preset[1];// => SET AMOUNT OF PRESETS MANUALLY !!!!

void loadPresets(){ // declare preset values
	
	// begin PRESET #1
	p = 0; // set preset
	
	// TRACK_1
	// synth A1
	preset[0].carrierA1Freq = 110;
	preset[0].carrierA1FadeTime = 6000;
	preset[0].modA1Freq = 64;
	preset[0].modA1Amt = 1.f; // modulation amount from 0. to 1.
	preset[0].modA1FadeTime = 30000;
	// synth B1
	preset[0].carrierB1Freq = 110;
	preset[0].carrierB1FadeTime = 18000;
	preset[0].modB1Freq = 111;
	preset[0].modB1Amt = 1.f; // modulation amount from 0. to 1.
	preset[0].modB1FadeTime = 15000;
	// synth Noise1
	preset[0].bp1freq = 8000;
	preset[0].bp1res = 0.707;
	preset[0].bp1AmtOctaves = 1.5; //Range is 0 to 7 octaves
	preset[0].bp1EnvAmt = 0;
	preset[0].bp1EnvFadeTime = 0;
	// SynthMix1
	preset[0].synthA1vol = 1.f;
	preset[0].synthB1vol = 0.f;
	preset[0].synthN1vol = 0.f;
	// FX1
	preset[0].delay1size = 10.4;
	preset[0].delay1fbk = 0.7;
	preset[0].fxmix1 = DRY; // 0 = synth, 100 = fx
	
	// TRACK_2
	// synth A2
	preset[0].carrierA2Freq = 110;
	preset[0].carrierA2FadeTime = 6000;
	preset[0].modA2Freq = 64;
	preset[0].modA2Amt = 1.f; // modulation amount from 0. to 1.
	preset[0].modA2FadeTime = 30000;
	// synth B1
	preset[0].carrierB2Freq = 110;
	preset[0].carrierB2FadeTime = 18000;
	preset[0].modB2Freq = 111;
	preset[0].modB2Amt = 1.f; // modulation amount from 0. to 1.
	preset[0].modB2FadeTime = 15000;
	// synth Noise1
	preset[0].bp2freq = 8000;
	preset[0].bp2res = 0.707;
	preset[0].bp2AmtOctaves = 1.5; //Range is 0 to 7 octaves
	preset[0].bp2EnvAmt = 0;
	preset[0].bp2EnvFadeTime = 0;
	// SynthMix1
	preset[0].synthA1vol = 1.f;
	preset[0].synthB1vol = 0.f;
	preset[0].synthN1vol = 0.f;
	// FX2
	preset[0].crush2bits = BD; // bit depth from 1 to 16
	preset[0].crush2sr = SR; // xsampleRate sets the frequency, from 1 to 44100Hz
	preset[0].fxmix2 = DRY; // 0 = synth, 100 = fx
	
	numPresets++; // autocalc
	// end PRESET #1
	
	
	/* -----> INSERT PRESETS HERE <----- */
	
	


}



#endif /* PRESETS_H_ */