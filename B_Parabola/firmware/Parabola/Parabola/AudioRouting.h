/*
 * AudioRouting.h
 *
 * Created: 02-06-2019 01:33:08
 *  Author: tiago
 * 
 * Teensy Audio Routing (aka synth diagram)
 */ 


#ifndef AUDIOROUTING_H_
#define AUDIOROUTING_H_

// GUItool: begin automatically generated code
AudioSynthWaveformSine   OscB;           //xy=56,27
AudioSynthWaveformSine   OscD;           //xy=56,71
AudioEffectEnvelope      EnvB;           //xy=188,27
AudioEffectEnvelope      EnvD;           //xy=188,71
AudioPlaySdWav           SampleA;        //xy=302,202
AudioPlaySdWav           SampleB;        //xy=303,250
AudioSynthNoiseWhite     Noise;          //xy=305,117
AudioSynthWaveformSineModulated OscA;           //xy=325,27
AudioSynthWaveformSineModulated OscC;           //xy=325,71
AudioSynthWaveformDc     FilterEnvOffset; //xy=422,153
AudioEffectFade          FadeA;          //xy=443,195
AudioEffectFade          FadeB;          //xy=444,243
AudioEffectEnvelope      NoiseEnv;       //xy=454,117
AudioEffectEnvelope      EnvA;           //xy=462,27
AudioEffectEnvelope      EnvC;           //xy=462,71
AudioEffectEnvelope      FilterEnv;      //xy=575,153
AudioMixer4              SampleMix;      //xy=594,232
AudioMixer4              OscMix;         //xy=608,78
AudioEffectFade          SampleFade;     //xy=746,232
AudioFilterStateVariable Lowpass;        //xy=758,84
AudioMixer4              SendB;          //xy=993,311
AudioMixer4              SendA;          //xy=995,237
AudioEffectFreeverb      Reverb;         //xy=1129,237
AudioEffectDelay         FbkDelay;       //xy=1130,420
AudioMixer4              MainMix;        //xy=1365,85
AudioFilterBiquad        Highpass;       //xy=1498,85
AudioFilterBiquad        HighShelf;      //xy=1640,85
AudioOutputI2S           Output;         //xy=1771,90
AudioConnection          patchCord1(OscB, EnvB);
AudioConnection          patchCord2(OscD, EnvD);
AudioConnection          patchCord3(EnvB, OscA);
AudioConnection          patchCord4(EnvD, OscC);
AudioConnection          patchCord5(SampleA, 0, FadeA, 0);
AudioConnection          patchCord6(SampleB, 0, FadeB, 0);
AudioConnection          patchCord7(Noise, NoiseEnv);
AudioConnection          patchCord8(OscA, EnvA);
AudioConnection          patchCord9(OscC, EnvC);
AudioConnection          patchCord10(FilterEnvOffset, FilterEnv);
AudioConnection          patchCord11(FadeA, 0, SampleMix, 0);
AudioConnection          patchCord12(FadeB, 0, SampleMix, 1);
AudioConnection          patchCord13(NoiseEnv, 0, OscMix, 2);
AudioConnection          patchCord14(EnvA, 0, OscMix, 0);
AudioConnection          patchCord15(EnvC, 0, OscMix, 1);
AudioConnection          patchCord16(FilterEnv, 0, Lowpass, 1);
AudioConnection          patchCord17(SampleMix, SampleFade);
AudioConnection          patchCord18(OscMix, 0, Lowpass, 0);
AudioConnection          patchCord19(SampleFade, 0, MainMix, 1);
AudioConnection          patchCord20(SampleFade, 0, SendA, 1);
AudioConnection          patchCord21(SampleFade, 0, SendB, 1);
AudioConnection          patchCord22(Lowpass, 0, MainMix, 0);
AudioConnection          patchCord23(Lowpass, 0, SendA, 0);
AudioConnection          patchCord24(Lowpass, 0, SendB, 0);
AudioConnection          patchCord25(SendB, FbkDelay);
AudioConnection          patchCord26(SendA, Reverb);
AudioConnection          patchCord27(Reverb, 0, MainMix, 2);
AudioConnection          patchCord28(FbkDelay, 0, MainMix, 3);
AudioConnection          patchCord29(FbkDelay, 0, SendB, 3);
AudioConnection          patchCord30(FbkDelay, 0, SendA, 3);
AudioConnection          patchCord31(MainMix, Highpass);
AudioConnection          patchCord32(Highpass, HighShelf);
AudioConnection          patchCord33(HighShelf, 0, Output, 0);
AudioControlSGTL5000     AudioShield;    //xy=1758,133
// GUItool: end automatically generated code


void initAudioObjects(){
	// AUDIO SHIELD
	AudioShield.enable();
	AudioShield.volume(MASTERVOL);
	
	// OSCILLATORS+NOISE
	OscA.amplitude(UGAIN);
	OscC.amplitude(UGAIN);
	Noise.amplitude(UGAIN);
	
	// SAMPLES
	
	// FEEDBACK DELAY
	for(int i = 1; i < 8; i++){ // disable unused delay taps
		FbkDelay.disable(i);
	}
	
	// MAINMIX
	MainMix.gain(0, 0.25f); // synth track
	MainMix.gain(1, 0.f); // sampler track
	MainMix.gain(2, 0.f); // rev track
	MainMix.gain(3, 0.f); // delay track
	SendA.gain(0, 0.f);
	SendA.gain(1, 0.f);
	SendA.gain(3, 0.f);
	SendB.gain(0, 0.f);
	SendB.gain(1, 0.f);
	SendB.gain(3, 0.f); // feedback gain
	// HPF AND HIGH SHELF
	Highpass.setHighpass(0, HPF, HPQ);
	HighShelf.setHighShelf(0, SHELFFREQ, SHELFGAIN);
}


#endif /* AUDIOROUTING_H_ */