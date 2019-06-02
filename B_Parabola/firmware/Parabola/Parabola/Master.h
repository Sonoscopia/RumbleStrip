/*
 * Master.h
 *
 * Created: 02-06-2019 06:10:02
 *  Author: tiago
 *
 * Master Mixer (Synth, Sampler, Reverb, Delay)
 */ 


#ifndef MASTER_H_
#define MASTER_H_
// 4-CH MainMix
void masterVolumes(float synth, float samplr, float rev, float dly){
	MainMix.gain(0, synth*MAINTRACKS);
	MainMix.gain(1, samplr*MAINTRACKS);
	MainMix.gain(2, rev*MAINTRACKS);
	MainMix.gain(3, dly*MAINTRACKS);
}
void masterSynthVol(float vol){
	MainMix.gain(0, vol*MAINTRACKS);
}
void masterSamplerVol(float vol){
	MainMix.gain(1, vol*MAINTRACKS);
}
void masterReverbVol(float vol){
	MainMix.gain(2, vol*MAINTRACKS);
}
void masterDelayVol(float vol){
	MainMix.gain(3, vol*MAINTRACKS);
}

// SENDS
// synth track
void sendsSynth(float rev, float dly){
	SendA.gain(0, rev*SENDATRACKS);
	SendB.gain(0, dly*SENDBTRACKS);
}
void sendSynthToA(float vol){
	SendA.gain(0, vol*SENDATRACKS);
}
void sendSynthToB(float vol){
	SendB.gain(0, vol*SENDBTRACKS);
}
// sampler track
void sendsSampler(float rev, float dly){
	SendA.gain(1, rev*SENDATRACKS);
	SendB.gain(1, dly*SENDBTRACKS);
}
void sendSamplerToA(float vol){
	SendA.gain(1, vol*SENDATRACKS);
}
void sendSamplerToB(float vol){
	SendB.gain(1, vol*SENDBTRACKS);
}
// delay track
void sendDelayToA(float vol){
	SendA.gain(3, vol*SENDATRACKS);
}
void delayFeedback(float fbk){
	SendB.gain(3, fbk*SENDBTRACKS);
}

#endif /* MASTER_H_ */