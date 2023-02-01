//
//  LeadGoose.cpp
//  Week03
//
//  Created by Nicholas Pan on 2023/1/31.
//

#include "LeadGoose.hpp"

LeadGoose::LeadGoose() {
    separationWeight = 3.0f;
    cohesionWeight = 0.3f;
    alignmentWeight = 0.3f;

    separationThreshold = 30;
    neighbourhoodSize = 300;

    position = ofVec3f(ofRandom(0, 200), ofRandom(0, 200));
    velocity = ofVec3f(ofRandom(-2, 2), ofRandom(-2, 2));
    colour = ofVec3f(255, 0, 0);
}

LeadGoose::~LeadGoose() {

}

void LeadGoose::clickPosition(int x, int y) {
//    ofVec3f direction(0, 0, 0);
    ofVec3f target(x, y);
    ofVec3f d = target - position;

    d.normalize();

    cout << d << endl;

    velocity = d * 5;
}

void LeadGoose::clickColour() {

}

void LeadGoose::update(vector<Creature *> &otherBoids, ofVec3f &min, ofVec3f &max) {
    walls(min, max);
    position += velocity;
}

void LeadGoose::draw() {
    ofSetColor(colour.x, colour.y, colour.z);
    ofRectangle(position.x, position.y, 100, 200);
    ofCircle(position.x, position.y, 15);
}

void LeadGoose::click(int x, int y, int b) {
    clickPosition(x, y);
}
