#pragma once

#include "ofMain.h"

extern "C" {
	#include "colourMapping/RGBtoColourMags.h"
}
#include "synth/Synth.h"

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

		// sound generation setup
		ofSoundStream soundStream;
		void audioOut(float * output, int bufferSize, int nChannels);

		// synth setup
		Synth synth;

		// video input
		ofVideoGrabber 	vidGrabber;
		unsigned char * image;
		ofTexture 		videoTexture;

		// video scaling
		int 			xOffset;
		int 			yOffset;
		int 			camWidth;
		int 			camHeight;
		float 			scaling;

		// function to return rgb values at x, y
		void getImagePixelRGB(int x, int y, int * r, int * g, int * b);

		// function that returns wether x, y screen coordinates are inside image or not
		bool onImage(int x, int y);
};
