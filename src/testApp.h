#pragma once

#include "ofMain.h"

#include "soundGenerators/AudioConstants.h"
#include "soundGenerators/SoundGen.h"
#include "soundGenerators/Chord.h"
#include "soundGenerators/PinkNoise.h" 

#include "synth/SynthConstants.h"

class testApp : public ofBaseApp {
	public:
		void setup();
		void update();
		void draw();
		
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y);
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofSoundStream soundStream;
		void audioOut(float * output, int bufferSize, int nChannels);

		//vector < SinOsc * > oscs;
		Chord * c;
		PinkNoise * n;
		vector < SoundGen * > sgs;
};
