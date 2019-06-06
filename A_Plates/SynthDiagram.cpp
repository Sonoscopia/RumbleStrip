#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   ModulatorB1;    //xy=85,131
AudioSynthWaveformSine   ModulatorA1;    //xy=86,87
AudioSynthWaveformSine   ModulatorB2;    //xy=90,419
AudioSynthWaveformSine   ModulatorA2;    //xy=91,375
AudioSynthWaveformDc     FilterEnvAmt1; //xy=215,211
AudioSynthWaveformDc     FilterEnvAmt2; //xy=220,499
AudioEffectFade          ModFadeB1;      //xy=231,132
AudioEffectFade          ModFadeA1;      //xy=233,87
AudioEffectFade          ModFadeB2;      //xy=236,419
AudioEffectFade          ModFadeA2;      //xy=238,375
AudioSynthNoiseWhite     Noise1;         //xy=359,170
AudioSynthNoiseWhite     Noise2;         //xy=364,458
AudioEffectFade          FilterFade1;    //xy=371,212
AudioEffectFade          FilterFade2;    //xy=376,499
AudioSynthWaveformSineModulated CarrierB1;      //xy=380,131
AudioSynthWaveformSineModulated CarrierA1;      //xy=381,87
AudioSynthWaveformSineModulated CarrierB2;      //xy=385,419
AudioSynthWaveformSineModulated CarrierA2;      //xy=386,375
AudioEffectFade          FadeA1;         //xy=507,87
AudioFilterStateVariable BP1;            //xy=507,177
AudioEffectFade          FadeB1;         //xy=509,130
AudioFilterStateVariable BP2;            //xy=512,465
AudioEffectFade          FadeA2;         //xy=513,375
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
AudioConnection          patchCord4(ModulatorA2, ModFadeA2);
AudioConnection          patchCord5(FilterEnvAmt1, FilterFade1);
AudioConnection          patchCord6(FilterEnvAmt2, FilterFade2);
AudioConnection          patchCord7(ModFadeB1, CarrierB1);
AudioConnection          patchCord8(ModFadeA1, CarrierA1);
AudioConnection          patchCord9(ModFadeB2, CarrierB2);
AudioConnection          patchCord10(ModFadeA2, CarrierA2);
AudioConnection          patchCord11(Noise1, 0, BP1, 0);
AudioConnection          patchCord12(Noise2, 0, BP2, 0);
AudioConnection          patchCord13(FilterFade1, 0, BP1, 1);
AudioConnection          patchCord14(FilterFade2, 0, BP2, 1);
AudioConnection          patchCord15(CarrierB1, FadeB1);
AudioConnection          patchCord16(CarrierA1, FadeA1);
AudioConnection          patchCord17(CarrierB2, FadeB2);
AudioConnection          patchCord18(CarrierA2, FadeA2);
AudioConnection          patchCord19(FadeA1, 0, SynthMix1, 0);
AudioConnection          patchCord20(BP1, 1, SynthMix1, 2);
AudioConnection          patchCord21(FadeB1, 0, SynthMix1, 1);
AudioConnection          patchCord22(BP2, 1, SynthMix2, 2);
AudioConnection          patchCord23(FadeA2, 0, SynthMix2, 0);
AudioConnection          patchCord24(FadeB2, 0, SynthMix2, 1);
AudioConnection          patchCord25(SynthMix2, 0, FXMix2, 0);
AudioConnection          patchCord26(SynthMix2, BitCrush2);
AudioConnection          patchCord27(SynthMix1, 0, Feedback1, 0);
AudioConnection          patchCord28(SynthMix1, 0, FXMix1, 0);
AudioConnection          patchCord29(Delay1, 0, Feedback1, 3);
AudioConnection          patchCord30(Delay1, 0, FXMix1, 1);
AudioConnection          patchCord31(BitCrush2, 0, FXMix2, 1);
AudioConnection          patchCord32(Feedback1, Delay1);
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
AudioControlSGTL5000     AudioShield;    //xy=1457,370
// GUItool: end automatically generated code
