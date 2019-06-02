# RUMBLE STRIP

The sonic and musical content of this installation is grounded in the use of idiosyncratic loudspeakers,  exploring their particular sound diffusion and the resulting reflections created by the interaction between different sounding objects, such as resonant metal plates and directional loudspeakers pointed at a moving parabolic reflector. The resulting generative composition thus explores the relations between sounding objects and the acoustic space, providing an acoustic image or footprint of a given physical space, leading the listener(s) to explore this space using their listening apparatus.

# Contents

There are two different sounding objects: Parabola and Plates.
Both use Teensy 3.6 and Audio Shield. 

## Parabola
Parabola is comprised of a compression driver mounted in a static parabolic copper object pointed at a similar rotating object. 
The rotating dish diffuses the sound in different directions. 
The sound generation is comprised of a 4-Operator FM (B->A + D->C) synth with a noise generator and a lowpass filter at the output. 
Additionally there is a crossfade between two sample players who act as background generators. 
Both these sources - the synth and the sampler - can be sent to a reverb and a feedback delay.
On the compositional side the synth as a set of presets that are selected according to a varying "tension" value. 
Where the synth is played by a stochastic sequencer which generates triggers, which by sending the synth to the delay line act as sonar pings, scanning the acoustic space. 


