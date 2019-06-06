/*
 * AudioRouting.h
 *
 * Created: 06-06-2019 00:48:39
 *  Author: tiago
 */ 


#ifndef AUDIOROUTING_H_
#define AUDIOROUTING_H_

// GUItool: begin automatically generated code
AudioSynthWaveformSine   ModulatorB1;    //xy=85,131
AudioSynthWaveformSine   ModulatorA1;    //xy=86,87
AudioSynthWaveformSine   ModulatorB2;    //xy=90,419
AudioSynthWaveformDc     FilterEnvAmt1; //xy=91.25000762939453,219.75000190734863
AudioSynthWaveformSine   ModulatorA2;    //xy=91,375
AudioSynthWaveformDc     FilterEnvAmt2; //xy=100,507.75000762939453
AudioEffectFade          ModFadeB1;      //xy=231,132
AudioEffectFade          ModFadeA1;      //xy=233,87
AudioSynthNoiseWhite     Noise1;         //xy=235.25000762939453,178.75000190734863
AudioEffectFade          ModFadeB2;      //xy=236,419
AudioEffectFade          ModFadeA2;      //xy=238,375
AudioSynthNoiseWhite     Noise2;         //xy=244,466.75000762939453
AudioEffectFade          FilterFade1;    //xy=247.25000762939453,220.75000190734863
AudioEffectFade          FilterFade2;    //xy=256,507.75000762939453
AudioSynthWaveformSineModulated CarrierB1;      //xy=380,131
AudioSynthWaveformSineModulated CarrierA1;      //xy=381,87
AudioFilterStateVariable BP1;            //xy=383.25000762939453,185.75000190734863
AudioSynthWaveformSineModulated CarrierB2;      //xy=385,419
AudioSynthWaveformSineModulated CarrierA2;      //xy=386,375
AudioFilterStateVariable BP2;            //xy=392,473.75000762939453
AudioEffectFade          FadeA1;         //xy=507,87
AudioEffectFade          FadeN1; //xy=508.75000762939453,185.00000190734863
AudioEffectFade          FadeB1;         //xy=509,130
AudioEffectFade          FadeA2;         //xy=513,375
AudioEffectFade          FadeN2; //xy=513.7500076293945,472.50000762939453
AudioEffectFade          FadeB2;         //xy=515,418
AudioMixer4              SynthMix2;      //xy=660,426
AudioMixer4              SynthMix1;      //xy=673,125
AudioEffectDelay         Delay1;         //xy=691,304
AudioEffectBitcrusher    BitCrush2;    //xy=692,510
AudioMixer4              Feedback1;      //xy=701,201
AudioPlaySdWav           Sample2;        //xy=844,507
AudioMixer4              FXMix2;         //xy=846,446
AudioPlaySdWav           Sample1;        //xy=848,189
AudioMixer4              FXMix1;         //xy=850,128
AudioMixer4              OutMixer2;      //xy=994,485
AudioMixer4              OutMixer1;      //xy=998,167
AudioFilterBiquad        EQ1;            //xy=1131,166
AudioFilterBiquad        EQ2;            //xy=1133,486
AudioAmplifier           VolTrack1;      //xy=1257,165
AudioAmplifier           VolTrack2;      //xy=1262,487
AudioOutputI2S           LineOut;        //xy=1448,331
AudioConnection          patchCord1(ModulatorB1, ModFadeB1);
AudioConnection          patchCord2(ModulatorA1, ModFadeA1);
AudioConnection          patchCord3(ModulatorB2, ModFadeB2);
AudioConnection          patchCord4(FilterEnvAmt1, FilterFade1);
AudioConnection          patchCord5(ModulatorA2, ModFadeA2);
AudioConnection          patchCord6(FilterEnvAmt2, FilterFade2);
AudioConnection          patchCord7(ModFadeB1, CarrierB1);
AudioConnection          patchCord8(ModFadeA1, CarrierA1);
AudioConnection          patchCord9(Noise1, 0, BP1, 0);
AudioConnection          patchCord10(ModFadeB2, CarrierB2);
AudioConnection          patchCord11(ModFadeA2, CarrierA2);
AudioConnection          patchCord12(Noise2, 0, BP2, 0);
AudioConnection          patchCord13(FilterFade1, 0, BP1, 1);
AudioConnection          patchCord14(FilterFade2, 0, BP2, 1);
AudioConnection          patchCord15(CarrierB1, FadeB1);
AudioConnection          patchCord16(CarrierA1, FadeA1);
AudioConnection          patchCord17(BP1, 1, FadeN1, 0);
AudioConnection          patchCord18(CarrierB2, FadeB2);
AudioConnection          patchCord19(CarrierA2, FadeA2);
AudioConnection          patchCord20(BP2, 1, FadeN2, 0);
AudioConnection          patchCord21(FadeA1, 0, SynthMix1, 0);
AudioConnection          patchCord22(FadeN1, 0, SynthMix1, 2);
AudioConnection          patchCord23(FadeB1, 0, SynthMix1, 1);
AudioConnection          patchCord24(FadeA2, 0, SynthMix2, 0);
AudioConnection          patchCord25(FadeN2, 0, SynthMix2, 2);
AudioConnection          patchCord26(FadeB2, 0, SynthMix2, 1);
AudioConnection          patchCord27(SynthMix2, 0, FXMix2, 0);
AudioConnection          patchCord28(SynthMix2, BitCrush2);
AudioConnection          patchCord29(SynthMix1, 0, Feedback1, 0);
AudioConnection          patchCord30(SynthMix1, 0, FXMix1, 0);
AudioConnection          patchCord31(Delay1, 0, Feedback1, 3);
AudioConnection          patchCord32(Delay1, 0, FXMix1, 1);
AudioConnection          patchCord33(BitCrush2, 0, FXMix2, 1);
AudioConnection          patchCord34(Feedback1, Delay1);
AudioConnection          patchCord35(Sample2, 0, OutMixer2, 1);
AudioConnection          patchCord36(FXMix2, 0, OutMixer2, 0);
AudioConnection          patchCord37(Sample1, 0, OutMixer1, 1);
AudioConnection          patchCord38(FXMix1, 0, OutMixer1, 0);
AudioConnection          patchCord39(OutMixer2, EQ2);
AudioConnection          patchCord40(OutMixer1, EQ1);
AudioConnection          patchCord41(EQ1, VolTrack1);
AudioConnection          patchCord42(EQ2, VolTrack2);
AudioConnection          patchCord43(VolTrack1, 0, LineOut, 0);
AudioConnection          patchCord44(VolTrack2, 0, LineOut, 1);
AudioControlSGTL5000     AudioShield;    //xy=1457,370
// GUItool: end automatically generated code


void initAudioObjects(){
	// AUDIO SHIELD
	AudioShield.enable();
	AudioShield.volume(MASTERVOL);
	
	// FEEDBACK DELAY
	for(int i = 1; i < 8; i++){ // disable unused delay taps
		Delay1.disable(i);
	}
	
	// INIT VOLUMES TRACK1
	CarrierA1.amplitude(UGAIN);
	CarrierB1.amplitude(UGAIN);
	Noise1.amplitude(HGAIN);
	Feedback1.gain(0, HGAIN);
	// INIT VOLUMES TRACK2
	CarrierA2.amplitude(UGAIN);
	CarrierB2.amplitude(UGAIN);
	Noise2.amplitude(HGAIN);
	
}

#endif /* AUDIOROUTING_H_ */