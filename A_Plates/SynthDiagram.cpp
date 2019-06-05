#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   ModulatorB2; //xy=90.71429443359375,419.71429443359375
AudioSynthWaveformSine   ModulatorA2; //xy=91.71429443359375,375.71429443359375
AudioSynthWaveformSine   ModulatorB1; //xy=94,101
AudioSynthWaveformSine   ModulatorA1;          //xy=95,57
AudioSynthWaveformDc     FilterEnvOffset2; //xy=220.71429443359375,499.71429443359375
AudioSynthWaveformDc     FilterEnvOffset1;            //xy=224,181
AudioAmplifier           ModulationB2; //xy=242.71429443359375,419.71429443359375
AudioAmplifier           ModulationA2; //xy=243.71429443359375,375.71429443359375
AudioAmplifier           ModulationB1; //xy=246,101
AudioAmplifier           ModulationA1;           //xy=247,57
AudioSynthNoiseWhite     Noise2; //xy=364.71429443359375,458.71429443359375
AudioEffectEnvelope      FilterEnv2; //xy=365.71429443359375,499.71429443359375
AudioSynthNoiseWhite     Noise1;         //xy=368,140
AudioEffectEnvelope      FilterEnv1; //xy=369,181
AudioSynthWaveformSineModulated CarrierB2; //xy=385.71429443359375,419.71429443359375
AudioSynthWaveformSineModulated CarrierA2; //xy=386.71429443359375,375.71429443359375
AudioSynthWaveformSineModulated CarrierB1; //xy=389,101
AudioSynthWaveformSineModulated CarrierA1;       //xy=390,57
AudioEffectEnvelope      EnvB2; //xy=510.71429443359375,419.71429443359375
AudioEffectEnvelope      EnvA2; //xy=511.71429443359375,375.71429443359375
AudioEffectEnvelope      EnvB1; //xy=514,101
AudioFilterStateVariable BP2; //xy=512.7142944335938,465.71429443359375
AudioEffectEnvelope      EnvA1;      //xy=515,57
AudioFilterStateVariable BP1;        //xy=516,147
AudioMixer4              SynthMix2; //xy=660.7142944335938,426.71429443359375
AudioMixer4              SynthMix1;         //xy=664,108
AudioEffectDelay         Delay1;         //xy=691,304
AudioEffectBitcrusher    bitcrusher1;    //xy=692.8571319580078,510.0000686645508
AudioMixer4              Feedback1;         //xy=701,201
AudioPlaySdWav           Sample2; //xy=844.7142944335938,507.71429443359375
AudioMixer4              FXMix2; //xy=846.7142944335938,446.71429443359375
AudioPlaySdWav           Sample1;     //xy=848,189
AudioMixer4              FXMix1; //xy=850,128
AudioMixer4              OutMixer2; //xy=994.7142944335938,485.71429443359375
AudioMixer4              OutMixer1; //xy=998,167
AudioFilterBiquad        EQ1;        //xy=1131.1110763549805,166.66667556762695
AudioFilterBiquad        EQ2; //xy=1133.5395812988281,486.80954027175903
AudioAmplifier           VolTrack1;           //xy=1261.2500190734863,166.78572273254395
AudioAmplifier           VolTrack2; //xy=1270.0000190734863,487.50000762939453
AudioOutputI2S           LineOut;           //xy=1449.3016319274902,333.04759407043457
AudioConnection          patchCord1(ModulatorB2, ModulationB2);
AudioConnection          patchCord2(ModulatorA2, ModulationA2);
AudioConnection          patchCord3(ModulatorB1, ModulationB1);
AudioConnection          patchCord4(ModulatorA1, ModulationA1);
AudioConnection          patchCord5(FilterEnvOffset2, FilterEnv2);
AudioConnection          patchCord6(FilterEnvOffset1, FilterEnv1);
AudioConnection          patchCord7(ModulationB2, CarrierB2);
AudioConnection          patchCord8(ModulationA2, CarrierA2);
AudioConnection          patchCord9(ModulationB1, CarrierB1);
AudioConnection          patchCord10(ModulationA1, CarrierA1);
AudioConnection          patchCord11(Noise2, 0, BP2, 0);
AudioConnection          patchCord12(FilterEnv2, 0, BP2, 1);
AudioConnection          patchCord13(Noise1, 0, BP1, 0);
AudioConnection          patchCord14(FilterEnv1, 0, BP1, 1);
AudioConnection          patchCord15(CarrierB2, EnvB2);
AudioConnection          patchCord16(CarrierA2, EnvA2);
AudioConnection          patchCord17(CarrierB1, EnvB1);
AudioConnection          patchCord18(CarrierA1, EnvA1);
AudioConnection          patchCord19(EnvB2, 0, SynthMix2, 1);
AudioConnection          patchCord20(EnvA2, 0, SynthMix2, 0);
AudioConnection          patchCord21(EnvB1, 0, SynthMix1, 1);
AudioConnection          patchCord22(BP2, 1, SynthMix2, 2);
AudioConnection          patchCord23(EnvA1, 0, SynthMix1, 0);
AudioConnection          patchCord24(BP1, 1, SynthMix1, 2);
AudioConnection          patchCord25(SynthMix2, 0, FXMix2, 0);
AudioConnection          patchCord26(SynthMix2, bitcrusher1);
AudioConnection          patchCord27(SynthMix1, 0, FXMix1, 0);
AudioConnection          patchCord28(SynthMix1, 0, Feedback1, 0);
AudioConnection          patchCord29(Delay1, 0, Feedback1, 3);
AudioConnection          patchCord30(bitcrusher1, 0, FXMix2, 1);
AudioConnection          patchCord31(Feedback1, Delay1);
AudioConnection          patchCord32(Feedback1, 0, FXMix1, 1);
AudioConnection          patchCord33(Sample2, 0, OutMixer2, 1);
AudioConnection          patchCord34(FXMix2, 0, OutMixer2, 0);
AudioConnection          patchCord35(Sample1, 0, OutMixer1, 1);
AudioConnection          patchCord36(FXMix1, 0, OutMixer1, 0);
AudioConnection          patchCord37(OutMixer2, EQ2);
AudioConnection          patchCord38(OutMixer1, EQ1);
AudioConnection          patchCord39(EQ1, VolTrack1);
AudioConnection          patchCord40(EQ2, VolTrack2);
AudioConnection          patchCord41(VolTrack1, 0, LineOut, 0);
AudioConnection          patchCord42(VolTrack2, 0, LineOut, 1);
AudioControlSGTL5000     AudioShield;     //xy=1455.936424255371,381.21027183532715
// GUItool: end automatically generated code
