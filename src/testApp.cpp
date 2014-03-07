#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	soundStream.setup(this, 2, 0, SAMPLE_RATE, BUFFER_SIZE, 4);

	float f[3] = BLUE_FREQS;
	c = new Chord(f, 0.1f);
	n = new PinkNoise(0.9f);

	sgs.push_back(c);
	sgs.push_back(n);
}

//--------------------------------------------------------------
void testApp::audioOut(float * output, int bufferSize, int nChannels){
	for(int i = 0; i < sgs.size(); i++) {
	
	//c->addAudioOut(output, bufferSize, nChannels);
		sgs[i]->addAudioOut(output, bufferSize, nChannels);
	}
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){

}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}
