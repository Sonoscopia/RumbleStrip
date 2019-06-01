#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>

// GUItool: begin automatically generated code
AudioSynthWaveformSine   modulator;          //xy=91.33332824707031,158.33334350585938
AudioEffectEnvelope      envelope;      //xy=236,158
AudioSynthWaveformSineModulated carrier;       //xy=380.33331298828125,158.33334350585938
AudioOutputI2S           output;           //xy=549.3333129882812,156.33334350585938
AudioConnection          patchCord1(modulator, envelope);
AudioConnection          patchCord2(envelope, carrier);
AudioConnection          patchCord3(carrier, 0, output, 0);
AudioConnection          patchCord4(carrier, 0, output, 1);
AudioControlSGTL5000     AudioShield;    //xy=292.3333282470703,38.333335876464844
// GUItool: end automatically generated code

void setup() {
  AudioMemory(10);
  
  AudioShield.enable();
  AudioShield.volume(0.5);

  modulator.amplitude(0.99999);
  modulator.frequency(80);
  carrier.amplitude(0.99999);
  carrier.frequency(220);

  envelope.attack(0);
  envelope.decay(200);
  envelope.sustain(0.66);
  envelope.release(1000);
}

void loop() {
  if(!envelope.isActive()){
    envelope.noteOn();
    delay(500);
    envelope.noteOff();
    delay(3000);
  }
}
