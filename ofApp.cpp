#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {
	ofSetFrameRate(60);
	ofBackground(0);
	ofSetWindowTitle("Insta");
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {
	this->cam.begin();

	float x, y;
	float noise_value;
	ofVec2f prev_point;

	for (int radius = 50; radius < 350; radius += 10) {
		noise_value = 45 + 360 * ofNoise(ofGetFrameNum() * 0.01 + radius * 0.005);

		for (int deg = 0; deg <= noise_value; deg += 1) {
			x = radius * cos(deg * DEG_TO_RAD);
			y = radius * sin(deg * DEG_TO_RAD);

			if (deg > 0) {
				ofDrawLine(prev_point, ofVec2f(x, y));
			}

			prev_point = ofVec3f(x, y);
		}

		ofDrawCircle(prev_point, 3);
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {
	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}