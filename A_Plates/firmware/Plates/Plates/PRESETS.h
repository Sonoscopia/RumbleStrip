/*
 * PRESETS.h
 *
 * Created: 06-06-2019 01:32:42
 *  Author: tiago
 */ 


#ifndef PRESETS_H_
#define PRESETS_H_

// calc total section duration to trigger next preset (one preset per section)
void setTimesAndCalcTotalDuration(uint32_t* cA1, uint32_t* mA1, uint32_t* cB1, uint32_t* mB1, uint32_t* n1, uint32_t* bp1, uint32_t* cA2, uint32_t* mA2, uint32_t* cB2, uint32_t* mB2, uint32_t* n2, uint32_t* bp2);
uint8_t p; // preset shortcut for easy copy-paste

struct synthpreset{
	uint32_t sectionDuration = 0; // section longest duration event

	// TRACK_1 Synth Params
	// synth A1
	float carrierA1Freq;
	float modA1Freq;
	float modA1Amt; // modulation amount from 0. to 1.
	// synth B1
	float carrierB1Freq;
	float modB1Freq;
	float modB1Amt; // modulation amount from 0. to 1.
	// synth Noise1
	float bp1freq;
	float bp1res;
	float bp1AmtOctaves; //Range is 0 to 7 octaves
	float bp1EnvAmt;
	// SynthMix1 
	float synthA1vol;
	float synthB1vol;
	float synthN1vol;
	// FX1
	float delay1size;
	float delay1fbk;
	float fxmix1; // 0 = synth, 100 = fx
	
	// TRACK_2 Synth Params
	// synth A2
	float carrierA2Freq;
	uint16_t carrierA2FadeTime;
	float modA2Freq;
	float modA2Amt; // modulation amount from 0. to 1.
	uint16_t modA2FadeTime;
	// synth B2
	float carrierB2Freq;
	uint16_t carrierB2FadeTime;
	float modB2Freq;
	float modB2Amt; // modulation amount from 0. to 1.
	uint16_t modB2FadeTime;
	// synth Noise2
	float bp2freq;
	float bp2res;
	float bp2AmtOctaves; //Range is 0 to 7 octaves
	float bp2EnvAmt;
	uint16_t bp2EnvFadeTime;
	// SynthMix2
	float synthA2vol;
	float synthB2vol;
	float synthN2vol;
	// FX2
	uint8_t crush2bits; // bit depth from 1 to 16
	uint16_t crush2sr; // xsampleRate sets the frequency, from 1 to 44100Hz
	float fxmix2; // 0 = synth, 100 = fx
	
	// SEQUENCING (onset=time before fadeIn, hold=time between fadeIn & fadeOut)
	// TRACK1
	uint32_t carrierA1Onset, carrierA1FadeIn, carrierA1Hold, carrierA1FadeOut; // track1
	uint32_t modA1Onset, modA1FadeIn, modA1Hold, modA1FadeOut;
	uint32_t carrierB1Onset, carrierB1FadeIn, carrierB1Hold, carrierB1FadeOut; // track1
	uint32_t modB1Onset, modB1FadeIn, modB1Hold, modB1FadeOut;
	uint32_t noise1Onset, noise1FadeIn, noise1Hold, noise1FadeOut;
	uint32_t bp1EnvOnset, bp1EnvFadeIn, bp1EnvHold, bp1EnvFadeOut;
	// TRACK2
	uint32_t carrierA2Onset, carrierA2FadeIn, carrierA2Hold, carrierA2FadeOut; // track1
	uint32_t modA2Onset, modA2FadeIn, modA2Hold, modA2FadeOut;
	uint32_t carrierB2Onset, carrierB2FadeIn, carrierB2Hold, carrierB2FadeOut; // track1
	uint32_t modB2Onset, modB2FadeIn, modB2Hold, modB2FadeOut;
	uint32_t noise2Onset, noise2FadeIn, noise2Hold, noise2FadeOut;
	uint32_t bp2EnvOnset, bp2EnvFadeIn, bp2EnvHold, bp2EnvFadeOut;
} preset[1];// => SET AMOUNT OF PRESETS MANUALLY !!!!


/*############################ PRESETS ###################################################*/
void loadPresets(){ // declare preset values
	
	// begin PRESET #1
	p = 0; // set preset
	
	// TRACK_1
	// synth A1
	preset[p].carrierA1Freq = 110;
	preset[p].modA1Freq = 64;
	preset[p].modA1Amt = 1.f; // modulation amount from 0. to 1.
	// synth B1
	preset[p].carrierB1Freq = 110;
	preset[p].modB1Freq = 111;
	preset[p].modB1Amt = 1.f; // modulation amount from 0. to 1.
	// synth Noise1
	preset[p].bp1freq = 400;
	preset[p].bp1res = 0.707;
	preset[p].bp1AmtOctaves = 1.5; //Range is 0 to 7 octaves
	preset[p].bp1EnvAmt = 0;
	// SynthMix1
	preset[p].synthA1vol = 1.f;
	preset[p].synthB1vol = 0.f;
	preset[p].synthN1vol = 0.f;
	// FX1
	preset[p].delay1size = 10.4;
	preset[p].delay1fbk = 0.7;
	preset[p].fxmix1 = DRY; // 0 = synth, 100 = fx
	
	// TRACK_2
	// synth A2
	preset[p].carrierA2Freq = 110;
	preset[p].modA2Freq = 64;
	preset[p].modA2Amt = 1.f; // modulation amount from 0. to 1.
	// synth B1
	preset[p].carrierB2Freq = 110;
	preset[p].modB2Freq = 111;
	preset[p].modB2Amt = 1.f; // modulation amount from 0. to 1.
	// synth Noise1
	preset[p].bp2freq = 400;
	preset[p].bp2res = 0.707;
	preset[p].bp2AmtOctaves = 1.5; //Range is 0 to 7 octaves
	preset[p].bp2EnvAmt = 0;
	// SynthMix1
	preset[p].synthA1vol = 1.f;
	preset[p].synthB1vol = 0.f;
	preset[p].synthN1vol = 0.f;
	// FX2
	preset[p].crush2bits = BD; // bit depth from 1 to 16
	preset[p].crush2sr = SR; // xsampleRate sets the frequency, from 1 to 44100Hz
	preset[p].fxmix2 = DRY; // 0 = synth, 100 = fx
	
	// SEQUENCING (onset=time before fadeIn, hold=time between fadeIn & fadeOut)
	//		{onset time, fade in, hold time, fade out}
	uint32_t carrierA1Times[4] = {0, 8000, 12000, 12000}; // track1
	uint32_t modA1Times[4] = {0, 8000, 12000, 12000};
	uint32_t carrierB1Times[4] = {0, 8000, 12000, 12000};
	uint32_t modB1Times[4] = {0, 8000, 12000, 12000};
	uint32_t noise1Times[4] = {0, 8000, 12000, 12000};
	uint32_t bp1EnvTimes[4] = {0, 8000, 12000, 12000};
	uint32_t carrierA2Times[4] = {0, 8000, 12000, 12000}; // track2
	uint32_t modA2Times[4] = {0, 8000, 12000, 12000};
	uint32_t carrierB2Times[4] = {0, 8000, 12000, 12000};
	uint32_t modB2Times[4] = {0, 8000, 12000, 12000};
	uint32_t noise2Times[4] = {0, 8000, 12000, 12000};
	uint32_t bp2EnvTimes[4] = {0, 8000, 12000, 12000};
	
	setTimesAndCalcTotalDuration(carrierA1Times, modA1Times, carrierB1Times, modB1Times, noise1Times, bp1EnvTimes, carrierA2Times, modA2Times, carrierB2Times, modB2Times, noise2Times, bp2EnvTimes);
	numPresets++; // autocalc
	// end PRESET #1
	
	
	/* -----> INSERT PRESETS HERE <----- */
	
	
}
/*###################### END OF PRESETS ###################################################*/


void setTimesAndCalcTotalDuration(uint32_t* cA1, uint32_t* mA1, uint32_t* cB1, uint32_t* mB1, uint32_t* n1, uint32_t* bp1, uint32_t* cA2, uint32_t* mA2, uint32_t* cB2, uint32_t* mB2, uint32_t* n2, uint32_t* bp2){
	// TRACK 1
	preset[p].carrierA1Onset = cA1[0]; // carrier A1
	preset[p].carrierA1FadeIn = cA1[1];
	preset[p].carrierA1Hold = cA1[2];
	preset[p].carrierA1FadeOut = cA1[3];
	preset[p].modA1Onset = mA1[0]; // modulator A1
	preset[p].modA1FadeIn = mA1[1];
	preset[p].modA1Hold = mA1[2];
	preset[p].modA1FadeOut = mA1[3];
	preset[p].carrierB1Onset = cB1[0]; // carrier B1
	preset[p].carrierB1FadeIn = cB1[1];
	preset[p].carrierB1Hold = cB1[2];
	preset[p].carrierB1FadeOut = cB1[3];
	preset[p].modB1Onset = mB1[0]; // modulator B1
	preset[p].modB1FadeIn = mB1[1];
	preset[p].modB1Hold = mB1[2];
	preset[p].modB1FadeOut = mB1[3];
	preset[p].noise1Onset = n1[0]; // noise1
	preset[p].noise1FadeIn = n1[1];
	preset[p].noise1Hold = n1[2];
	preset[p].noise1FadeOut = n1[3];
	preset[p].bp1EnvOnset = bp1[0]; // bp1
	preset[p].bp1EnvFadeIn = bp1[1];
	preset[p].bp1EnvHold = bp1[2];
	preset[p].bp1EnvFadeOut = bp1[3];
	// TRACK 2
	preset[p].carrierA2Onset = cA1[0]; // carrier A2
	preset[p].carrierA2FadeIn = cA1[1];
	preset[p].carrierA2Hold = cA1[2];
	preset[p].carrierA2FadeOut = cA1[3];
	preset[p].modA2Onset = mA1[0]; // modulator A2
	preset[p].modA2FadeIn = mA1[1];
	preset[p].modA2Hold = mA1[2];
	preset[p].modA2FadeOut = mA1[3];
	preset[p].carrierB2Onset = cB1[0]; // carrier B2
	preset[p].carrierB2FadeIn = cB1[1];
	preset[p].carrierB2Hold = cB1[2];
	preset[p].carrierB2FadeOut = cB1[3];
	preset[p].modB2Onset = mB1[0]; // modulator B2
	preset[p].modB2FadeIn = mB1[1];
	preset[p].modB2Hold = mB1[2];
	preset[p].modB2FadeOut = mB1[3];
	preset[p].noise2Onset = n1[0]; // noise2
	preset[p].noise2FadeIn = n1[1];
	preset[p].noise2Hold = n1[2];
	preset[p].noise2FadeOut = n1[3];
	preset[p].bp2EnvOnset = bp1[0]; // bp2
	preset[p].bp2EnvFadeIn = bp1[1];
	preset[p].bp2EnvHold = bp1[2];
	preset[p].bp2EnvFadeOut = bp1[3];
	
	// CALC SECTION DURATION
	uint32_t dur = 0, biggest_dur = 0;
	
	for(int i = 0; i < ES; i++) // carrier A1
	{
		dur += cA1[i];
	}
	if(dur > biggest_dur){
		preset[p].sectionDuration = dur;
		biggest_dur = dur;  
	}
	dur = 0; 
	
	for(int i = 0; i < ES; i++) // carrier B1
	{
		dur += cB1[i];
	}
	if(dur > biggest_dur){
		preset[p].sectionDuration = dur;
		biggest_dur = dur;
	}
	dur = 0;
	
	for(int i = 0; i < ES; i++) // carrier N1
	{
		dur += n1[i];
	}
	if(dur > biggest_dur){
		preset[p].sectionDuration = dur;
		biggest_dur = dur;
	}
	dur = 0;
	
	for(int i = 0; i < ES; i++) // carrier A2
	{
		dur += cA2[i];
	}
	if(dur > biggest_dur){
		preset[p].sectionDuration = dur;
		biggest_dur = dur;
	}
	dur = 0;
	
	for(int i = 0; i < ES; i++) // carrier B2
	{
		dur += cB2[i];
	}
	if(dur > biggest_dur){
		preset[p].sectionDuration = dur;
		biggest_dur = dur;
	}
	dur = 0;
	
	for(int i = 0; i < ES; i++) // carrier N2
	{
		dur += n2[i];
	}
	if(dur > biggest_dur){
		preset[p].sectionDuration = dur;
		biggest_dur = dur;
	}
	 
}

#endif /* PRESETS_H_ */