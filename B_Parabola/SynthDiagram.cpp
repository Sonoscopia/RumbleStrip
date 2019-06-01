#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   OscB;           //xy=62,27
AudioSynthWaveformSine   OscD;           //xy=62,71
AudioEffectEnvelope      EnvB;           //xy=194,27
AudioEffectEnvelope      EnvD;           //xy=194,71
AudioPlaySdWav           SampleA;        //xy=308,202
AudioPlaySdWav           SampleB;        //xy=309,250
AudioSynthNoiseWhite     Noise;          //xy=311,117
AudioSynthWaveformSineModulated OscA;           //xy=331,27
AudioSynthWaveformSineModulated OscC;           //xy=331,71
AudioSynthWaveformDc     FilterEnvOffset;            //xy=428.75000762939453,153.75000190734863
AudioEffectFade          FadeA;          //xy=449,195
AudioEffectFade          FadeB;          //xy=450,243
AudioEffectEnvelope      NoiseEnv;       //xy=460,117
AudioEffectEnvelope      EnvA;           //xy=468,27
AudioEffectEnvelope      EnvC;           //xy=468,71
AudioEffectEnvelope      FilterEnv;      //xy=581,153
AudioMixer4              SampleMix;      //xy=600,232
AudioMixer4              OscMix;         //xy=614,78
AudioEffectFade          SampleFade;     //xy=752,232
AudioFilterStateVariable Lowpass;            //xy=764,84
AudioMixer4              SendB;          //xy=1000,338
AudioMixer4              SendA;          //xy=1001,237
AudioEffectFreeverb      Reverb;         //xy=1135,237
AudioEffectDelay         FbkDelay;       //xy=1135,338
AudioMixer4              MainMix;        //xy=1371,85
AudioFilterBiquad        Highpass;            //xy=1504,85
AudioFilterBiquad        HighShelf;        //xy=1646.2500228881836,85.0000171661377
AudioOutputI2S           Output;         //xy=1777.7500267028809,90.75000190734863
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
AudioConnection          patchCord30(MainMix, Highpass);
AudioConnection          patchCord31(Highpass, HighShelf);
AudioConnection          patchCord32(HighShelf, 0, Output, 0);
AudioControlSGTL5000     AudioShield;    //xy=1764.5000267028809,133.75000286102295
// GUItool: end automatically generated code
