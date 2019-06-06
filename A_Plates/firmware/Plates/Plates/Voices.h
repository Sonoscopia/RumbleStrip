/*
 * Voice1.h
 *
 * Created: 06-06-2019 02:14:10
 *  Author: tiago
 */ 


#ifndef VOICE1_H_
#define VOICE1_H_

boolean cA1Trig[2] = {false, false};
boolean mA1Trig[2] = {false, false};
boolean cB1Trig[2] = {false, false};
boolean mB1Trig[2] = {false, false};
boolean n1Trig[2] = {false, false};
boolean bp1Trig[2] = {false, false};
boolean cA2Trig[2] = {false, false};
boolean mA2Trig[2] = {false, false};
boolean cB2Trig[2] = {false, false};
boolean mB2Trig[2] = {false, false};
boolean n2Trig[2] = {false, false};
boolean bp2Trig[2] = {false, false};


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

void resetTriggers(){
	for(int i = 0; i < 2; i++){
		cA1Trig[i] = false;
		mA1Trig[i] = false;
		cB1Trig[i] = false;
		mB1Trig[i] = false;
		n1Trig[i] = false;
		bp1Trig[i] = false;
		cA2Trig[i] = false;
		mA2Trig[i] = false;
		cB2Trig[i] = false;
		mB2Trig[i] = false;
		n2Trig[i] = false;
		bp2Trig[i] = false;
	}
}

void voice1TriggerEvents(uint32_t ctime){ // (clockTimer)
	// TRIGGER FADE IN
	if (ctime > preset[curPreset].carrierA1Onset && cA1Trig[0] == false) // Carrier A1
	{	
		cA1Trig[0] = true;
		FadeA1.fadeIn(preset[curPreset].carrierA1FadeIn);
	}
	if (ctime > preset[curPreset].modA1Onset && mA1Trig[0] == false) // Modulator A1
	{
		mA1Trig[0] = true;
		ModFadeA1.fadeIn(preset[curPreset].modA1FadeIn);
	}
	if (ctime > preset[curPreset].carrierB1Onset && cB1Trig[0] == false) // Carrier B1
	{
		cB1Trig[0] = true;
		FadeB1.fadeIn(preset[curPreset].carrierB1FadeIn);
	}
	if (ctime > preset[curPreset].modB1Onset && mB1Trig[0] == false) // Modulator B1
	{
		mB1Trig[0] = true;
		ModFadeB1.fadeIn(preset[curPreset].modB1FadeIn);
	}
	if (ctime > preset[curPreset].noise1Onset && n1Trig[0] == false) // Noise1
	{
		n1Trig[0] = true;
		FadeN1.fadeIn(preset[curPreset].noise1FadeIn);
	}
	if (ctime > preset[curPreset].bp1EnvOnset && bp2Trig[0] == false) // BandPass1
	{
		bp1Trig[0] = true;
		FilterFade1.fadeIn(preset[curPreset].bp1EnvFadeIn);
	}
	
	
	
	// TRIGGER FADEOUT 
	if (ctime > (preset[curPreset].carrierA1Onset 
				+ preset[curPreset].carrierA1FadeIn 
				+ preset[curPreset].carrierA1Hold) 
		&& cA1Trig[1] == false){
			cA1Trig[1] = true;
			FadeA1.fadeOut(preset[curPreset].carrierA1FadeOut);
	} // Carrier A1
	
	if (ctime > (preset[curPreset].modA1Onset
	+ preset[curPreset].modA1FadeIn
	+ preset[curPreset].modA1Hold)
	&& mA1Trig[1] == false){
		mA1Trig[1] = true;
		ModFadeA1.fadeOut(preset[curPreset].modA1FadeOut);
	} // Modulator A1
	
	if (ctime > (preset[curPreset].carrierB1Onset
	+ preset[curPreset].carrierB1FadeIn
	+ preset[curPreset].carrierB1Hold)
	&& cB1Trig[1] == false){
		cB1Trig[1] = true;
		FadeB1.fadeOut(preset[curPreset].carrierB1FadeOut);
	} // Carrier B1
	
	if (ctime > (preset[curPreset].modB1Onset
	+ preset[curPreset].modB1FadeIn
	+ preset[curPreset].modB1Hold)
	&& mB1Trig[1] == false){
		mB1Trig[1] = true;
		ModFadeB1.fadeOut(preset[curPreset].modB1FadeOut);
	} // Modulator B1
	
	if (ctime > (preset[curPreset].noise1Onset
	+ preset[curPreset].noise1FadeIn
	+ preset[curPreset].noise1Hold)
	&& n1Trig[1] == false){
		n1Trig[1] = true;
		FadeN1.fadeOut(preset[curPreset].noise1FadeOut);
	} // Noise1

	if (ctime > (preset[curPreset].bp1EnvOnset
	+ preset[curPreset].bp1EnvFadeIn
	+ preset[curPreset].bp1EnvHold)
	&& bp1Trig[1] == false){
		bp1Trig[1] = true;
		FilterFade1.fadeOut(preset[curPreset].bp1EnvFadeOut);
	} // BandPass1
}

void voice2TriggerEvents(uint32_t ctime){ // (clockTimer)
	// TRIGGER FADE IN
	if (ctime > preset[curPreset].carrierA2Onset && cA2Trig[0] == false) // Carrier A2
	{
		cA2Trig[0] = true;
		FadeA2.fadeIn(preset[curPreset].carrierA2FadeIn);
	}
	if (ctime > preset[curPreset].modA2Onset && mA2Trig[0] == false) // Modulator A2
	{
		mA2Trig[0] = true;
		ModFadeA2.fadeIn(preset[curPreset].modA2FadeIn);
	}
	if (ctime > preset[curPreset].carrierB2Onset && cB2Trig[0] == false) // Carrier B2
	{
		cB2Trig[0] = true;
		FadeB2.fadeIn(preset[curPreset].carrierB2FadeIn);
	}
	if (ctime > preset[curPreset].modB2Onset && mB2Trig[0] == false) // Modulator B2
	{
		mB2Trig[0] = true;
		ModFadeB2.fadeIn(preset[curPreset].modB2FadeIn);
	}
	if (ctime > preset[curPreset].noise2Onset && n2Trig[0] == false) // Noise2
	{
		n2Trig[0] = true;
		FadeN2.fadeIn(preset[curPreset].noise2FadeIn);
	}
	if (ctime > preset[curPreset].bp2EnvOnset && bp2Trig[0] == false) // BandPass2
	{
		bp2Trig[0] = true;
		FilterFade2.fadeIn(preset[curPreset].bp2EnvFadeIn);
	}
	
	
	
	// TRIGGER FADEOUT
	if (ctime > (preset[curPreset].carrierA2Onset
	+ preset[curPreset].carrierA2FadeIn
	+ preset[curPreset].carrierA2Hold)
	&& cA2Trig[1] == false){
		cA2Trig[1] = true;
		FadeA2.fadeOut(preset[curPreset].carrierA2FadeOut);
	} // Carrier A2
	
	if (ctime > (preset[curPreset].modA2Onset
	+ preset[curPreset].modA2FadeIn
	+ preset[curPreset].modA2Hold)
	&& mA2Trig[1] == false){
		mA2Trig[1] = true;
		ModFadeA2.fadeOut(preset[curPreset].modA2FadeOut);
	} // Modulator A2
	
	if (ctime > (preset[curPreset].carrierB2Onset
	+ preset[curPreset].carrierB2FadeIn
	+ preset[curPreset].carrierB2Hold)
	&& cB2Trig[1] == false){
		cB2Trig[1] = true;
		FadeB2.fadeOut(preset[curPreset].carrierB2FadeOut);
	} // Carrier B2
	
	if (ctime > (preset[curPreset].modB2Onset
	+ preset[curPreset].modB2FadeIn
	+ preset[curPreset].modB2Hold)
	&& mB2Trig[1] == false){
		mB2Trig[1] = true;
		ModFadeB2.fadeOut(preset[curPreset].modB2FadeOut);
	} // Modulator B2
	
	if (ctime > (preset[curPreset].noise2Onset
	+ preset[curPreset].noise2FadeIn
	+ preset[curPreset].noise2Hold)
	&& n2Trig[1] == false){
		n2Trig[1] = true;
		FadeN2.fadeOut(preset[curPreset].noise2FadeOut);
	} // Noise2

	if (ctime > (preset[curPreset].bp2EnvOnset
	+ preset[curPreset].bp2EnvFadeIn
	+ preset[curPreset].bp2EnvHold)
	&& bp2Trig[1] == false){
		bp2Trig[1] = true;
		FilterFade2.fadeOut(preset[curPreset].bp2EnvFadeOut);
	} // BandPass2
}

#endif /* VOICE1_H_ */