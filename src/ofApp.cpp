#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup()
{
	ofSetBackgroundColor(ofColor().black);
	ofNoFill();
	ofSetFrameRate(60);
	ofSetFullscreen(true);



	r1 = 400;
	r2 = 400;
	m1 = 20;
	m2 = 20;
	theta1 = PI/2;
	theta2 = PI/8;
	theta1v = 0;
	theta2v = 0;
	g = 1;

	pivot.set(0, 0, 0);
}

//--------------------------------------------------------------
void ofApp::update()
{
	theta1acc = ((-g * (2 * m1 + m2) * sin(theta1)) - (m2 * g * sin (theta1 - 2 * theta2)) - (2 * sin (theta1 - theta2) * m2 * (theta2v * theta2v * r2 + theta1v * theta1v * r1 * cos(theta1 - theta2)))) / (r1 * (2 * m1 + m2 - m2 * cos(2 * theta1 - 2 * theta2)));
	theta2acc = (2 * sin(theta1 - theta2) * (theta1v * theta1v * r1 * (m1 + m2) + g * (m1 + m2) * cos(theta1) + theta2v * theta2v * r2 * m2 * cos (theta1 - theta2)) / (r2 * (2 * m1 + m2 - m2 * cos (2* theta1 - 2 * theta2))));
	//cout << theta1acc << ", " << theta2acc << "\t";


	theta1v += theta1acc;
	theta2v += theta2acc;
	theta1 += theta1v;
	theta2 += theta2v;

	//theta1v *= 0.999999;
	//theta2v *= 0.999999;

}

//--------------------------------------------------------------
void ofApp::draw()
{
	ofSetColor(ofColor().red);

	ofTranslate(w/2, 50);

	bob1.x =  r1 * sin(theta1);
	bob1.y =  r1 * cos(theta1);

	bob2.x =  bob1.x + r2 * sin(theta2);
	bob2.y =  bob1.y + r2 * cos(theta2);
	trace.addVertex(bob2);

	ofDrawLine(pivot, bob1);
	ofDrawLine(bob1, bob2);
	ofDrawSphere(bob1, m1);
	ofDrawSphere(bob2, m2);

	ofSetColor(ofColor().green);
	trace.draw();
	//ofDrawBitmapString();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
