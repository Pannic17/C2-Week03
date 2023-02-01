#include "ofApp.h"

ofApp::~ofApp(){
    for (int i = 0; i < creatures.size(); i++) {
        delete creatures[i];
    }
}

//--------------------------------------------------------------
void ofApp::setup(){
    int screenW = ofGetScreenWidth();
    int screenH = ofGetScreenHeight();
    
    ofBackground(0, 50, 50);


    for (int i = 0; i < 50; i++) {
        creatures.push_back(new Boid());
    }

    creatures.push_back(new LeadGoose());
}

//--------------------------------------------------------------
void ofApp::update(){
    ofVec3f min(0, 0);
    ofVec3f max(ofGetWidth(), ofGetHeight());
    
    for (int i = 0; i < creatures.size(); i++) {
        creatures[i]->update(creatures, min, max);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    for (int i = 0; i < creatures.size(); i++) {
        creatures[i]->draw();
    }
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
    int num = ofRandom(0, 49);
    creatures[num]->setColour(ofRandom(255), ofRandom(255), ofRandom(255));
//    LeadGoose leadGoose = (LeadGoose) creatures[0];
    creatures[50]->click(x, y, button);
    cout << creatures[50]->getColour() << endl;
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
