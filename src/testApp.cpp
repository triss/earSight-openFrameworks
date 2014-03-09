#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
	// initialise sound
	soundStream.setup(this, 2, 0, SAMPLE_RATE, BUFFER_SIZE, 4);
	
	camWidth = 640;
	camHeight = 480;

	// init web cam
	vidGrabber.setDeviceID(0);
	vidGrabber.setDesiredFrameRate(60);
	vidGrabber.initGrabber(camWidth, camHeight);

	// set size of image that we're grabbing
	image = new unsigned char[camWidth*camWidth*3];
	videoTexture.allocate(camWidth, camHeight, GL_RGB);

	// TODO what does this do?
	ofSetVerticalSync(true);

}

//--------------------------------------------------------------
void testApp::audioOut(float * output, int bufferSize, int nChannels){
	synth.addAudioOut(output, bufferSize, nChannels);
}

//--------------------------------------------------------------
void testApp::update(){
	// grab frame of video
	vidGrabber.update();

	if(vidGrabber.isFrameNew()) {
		image = vidGrabber.getPixels();
		videoTexture.loadData(image, camWidth, camHeight, GL_RGB);
	}
}

//--------------------------------------------------------------
void testApp::getImagePixelRGB(int x, int y, int * r, int * g, int * b){
	*r = (int)image[((y * camWidth) + x) * 3];
	*g = (int)image[((y * camWidth) + x) * 3 + 1];
	*b = (int)image[((y * camWidth) + x) * 3 + 2];
}

//--------------------------------------------------------------
void testApp::draw(){
	videoTexture.draw(0, 0, camWidth, camHeight);
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y){
	if(x < camWidth && y < camHeight) {
		int r, g, b;

		// get rgb from image int r, g, b;
		getImagePixelRGB(x, y, &r, &g, &b);
		
		// get colour magnitudes
		double white, black, grey, blue, yellow, green, red;
		rgbToColourMags(&white, &black, &grey, &green, &red, &blue, &yellow, r, g, b);	
	
		synth.mapColourMags(white, black, grey, green, red, blue, yellow);
	} else {
		synth.fadeOut();
	}
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
