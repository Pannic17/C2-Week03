//
//  Creature.hpp
//  Week03
//
//  Created by Nicholas Pan on 2023/1/31.
//

#ifndef Creature_hpp
#define Creature_hpp

#include <stdio.h>
#include "ofMain.h"

class Creature {
protected:
    ofVec3f position;
    ofVec3f velocity;
    ofVec3f colour;

    float separationWeight;
    float cohesionWeight;
    float alignmentWeight;

    float separationThreshold;
    float neighbourhoodSize;

public:
    ofVec3f getPosition();
    ofVec3f getVelocity();
    ofVec3f getColour();
    void setColour(int r, int g, int b);

    float getSeparationWeight();
    float getCohesionWeight();
    float getAlignmentWeight();

    float getSeparationThreshold();
    float getNeighbourhoodSize();

    void setSeparationWeight(float f);
    void setCohesionWeight(float f);
    void setAlignmentWeight(float f);

    void setSeparationThreshold(float f);
    void setNeighbourhoodSize(float f);

    virtual void update(vector<Creature *> &otherCreature, ofVec3f &min, ofVec3f &max) = 0;
    virtual void draw() = 0;

    virtual void click(int x, int y, int b);

    void walls(ofVec3f &min, ofVec3f &max);
};

#endif /* Creature_hpp */
