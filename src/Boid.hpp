//
//  Boid.hpp
//  Week03
//
//  Created by Nicholas Pan on 2023/1/31.
//

#ifndef Boid_hpp
#define Boid_hpp

#include <stdio.h>
#include "ofMain.h"
#import "Creature.hpp"
#import "LeadGoose.hpp"

class Boid: public Creature
{
// all the methods and variables after the
// private keyword can only be used inside
// the class
private:
    ofVec3f separation(std::vector<Creature *> &otherBoids);
    ofVec3f cohesion(std::vector<Creature *> &otherBoids);
    ofVec3f alignment(std::vector<Creature *> &otherBoids);
    ofVec3f heading(std::vector<Creature *> &otherBoids);
    
// all the methods and variables after the
// public keyword can only be used by anyone
public:
    Boid();
    Boid(ofVec3f &pos, ofVec3f &vel);
    
    ~Boid();
    
    void update(std::vector<Creature *> &otherBoids, ofVec3f &min, ofVec3f &max);
    
    void draw();
};



#endif /* Boid_hpp */
