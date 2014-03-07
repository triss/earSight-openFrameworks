#ifndef _SIN_OSC
#define _SIN_OSC

#include "ofMain.h"
#include "AudioConstants.h"

class SinOsc : public SoundGen {
	private:
		float phase;
		float phaseAdder;
		float phaseAdderTarget;
		//float volume;
	
	public:
		void addAudioOut(float * output, int bufferSize, int nChannels);
		void setFreq(float f);
//		void setVolume(float v);

	SinOsc(float freq, float volume);
};

#endif 
