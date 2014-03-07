#ifndef _SOUND_GEN
#define _SOUND_GEN

class SoundGen {
	protected:
		float volume;

	public:
		virtual void addAudioOut(float *, int, int) {};
		void setVolume(float volume);
};

#endif
