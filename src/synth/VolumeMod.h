#ifndef _VOLUME_MOD 
#define _VOLUME_MOD

#include "ofMain.h"
#include "SoundGen.h"
#include "AudioConstants.h"

class VolumeMod {
	private:
		float volume;

		float fadeInPos;
		float fadeOutPos;

		UGen * ugen;

	public:
		void setVolume(float volume);
		void fadeOut(float fadeOutTime);
		void fadeTo(float fadeTime)

	VolumeMod(UGen * ugen);
};

#endif
