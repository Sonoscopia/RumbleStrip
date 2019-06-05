#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   ModulatorB1; //xy=85.111083984375,131.77777099609375
AudioSynthWaveformSine   ModulatorA1; //xy=86.111083984375,87.77777099609375
AudioSynthWaveformSine   ModulatorB2; //xy=90.71429443359375,419.71429443359375
AudioSynthWaveformSine   ModulatorA2; //xy=91.71429443359375,375.71429443359375
AudioSynthWaveformDc     FilterEnvOffset1; //xy=215.111083984375,211.77777099609375
AudioSynthWaveformDc     FilterEnvOffset2; //xy=220.71429443359375,499.71429443359375
AudioEffectFade          ModFadeB1; //xy=231.0634536743164,132.06344413757324
AudioEffectFade          ModFadeA1; //xy=233.2856674194336,87.6190414428711
AudioEffectFade          ModFadeB2; //xy=236.66666412353516,419.99996757507324
AudioEffectFade          ModFadeA2;          //xy=238.88887786865234,375.5555648803711
AudioSynthNoiseWhite     Noise1; //xy=359.111083984375,170.77777099609375
AudioSynthNoiseWhite     Noise2; //xy=364.71429443359375,458.71429443359375
AudioEffectFade          FilterFade1; //xy=371.06345558166504,212.06343841552734
AudioEffectFade          FilterFade2; //xy=376.6666660308838,499.99996185302734
AudioSynthWaveformSineModulated CarrierB1; //xy=380.111083984375,131.77777099609375
AudioSynthWaveformSineModulated CarrierA1; //xy=381.111083984375,87.77777099609375
AudioSynthWaveformSineModulated CarrierB2; //xy=385.71429443359375,419.71429443359375
AudioSynthWaveformSineModulated CarrierA2; //xy=386.71429443359375,375.71429443359375
AudioFilterStateVariable BP1; //xy=507.111083984375,177.77777099609375
AudioEffectFade          FadeA1; //xy=507.73011779785156,87.61899375915527
AudioEffectFade          FadeB1; //xy=509.95234298706055,130.95236587524414
AudioFilterStateVariable BP2; //xy=512.7142944335938,465.71429443359375
AudioEffectFade          FadeA2; //xy=513.3333282470703,375.5555171966553
AudioEffectFade          FadeB2; //xy=515.5555534362793,418.88888931274414
AudioMixer4              SynthMix2; //xy=660.7142944335938,426.71429443359375
AudioMixer4              SynthMix1; //xy=673.333324432373,125.55555725097656
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
AudioAmplifier           VolTrack1;           //xy=1257.5000190734863,165.53572368621826
AudioAmplifier           VolTrack2; //xy=1262.5000190734863,487.50000762939453
AudioOutputI2S           LineOut;           //xy=1448.8889083862305,331.11113357543945
AudioConnection          patchCord1(ModulatorB1, ModFadeB1);
AudioConnection          patchCord2(ModulatorA1, ModFadeA1);
AudioConnection          patchCord3(ModulatorB2, ModFadeB2);
AudioConnection          patchCord4(ModulatorA2, ModFadeA2);
AudioConnection          patchCord5(FilterEnvOffset1, FilterFade1);
AudioConnection          patchCord6(FilterEnvOffset2, FilterFade2);
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
AudioConnection          patchCord19(BP1, 1, SynthMix1, 2);
AudioConnection          patchCord20(FadeA1, 0, SynthMix1, 0);
AudioConnection          patchCord21(FadeB1, 0, SynthMix1, 1);
AudioConnection          patchCord22(BP2, 1, SynthMix2, 2);
AudioConnection          patchCord23(FadeA2, 0, SynthMix2, 0);
AudioConnection          patchCord24(FadeB2, 0, SynthMix2, 1);
AudioConnection          patchCord25(SynthMix2, 0, FXMix2, 0);
AudioConnection          patchCord26(SynthMix2, bitcrusher1);
AudioConnection          patchCord27(SynthMix1, 0, Feedback1, 0);
AudioConnection          patchCord28(SynthMix1, 0, FXMix1, 0);
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
AudioControlSGTL5000     AudioShield;     //xy=1457.0475463867188,370.79360580444336
// GUItool: end automatically generated code
