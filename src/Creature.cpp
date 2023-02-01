//
//  Creature.cpp
//  Week03
//
//  Created by Nicholas Pan on 2023/1/31.
//

#include "Creature.hpp"

float Creature::getSeparationWeight()
{
    return separationWeight;
}
float Creature::getCohesionWeight()
{
    return cohesionWeight;
}

float Creature::getAlignmentWeight()
{
    return alignmentWeight;
}


float Creature::getSeparationThreshold()
{
    return separationThreshold;
}

float Creature::getNeighbourhoodSize()
{
    return neighbourhoodSize;
}


void Creature::setSeparationWeight(float f)
{
    separationWeight = f;
}
void Creature::setCohesionWeight(float f)
{
    cohesionWeight = f;
}

void Creature::setAlignmentWeight(float f)
{
    alignmentWeight = f;
}


void Creature::setSeparationThreshold(float f)
{
    separationThreshold = f;
}

void Creature::setNeighbourhoodSize(float f)
{
    neighbourhoodSize = f;
}


ofVec3f Creature::getPosition()
{
    return position;
}

ofVec3f Creature::getVelocity()
{
    return velocity;
}

ofVec3f Creature::getColour() {
    return colour;
}

void Creature::walls(ofVec3f &min, ofVec3f &max)
{
    if (position.x < min.x){
        position.x = min.x;
        velocity.x *= -1;
    } else if (position.x > max.x){
        position.x = max.x;
        velocity.x *= -1;
    }

    if (position.y < min.y){
        position.y = min.y;
        velocity.y *= -1;
    } else if (position.y > max.y){
        position.y = max.y;
        velocity.y *= -1;
    }
}

void Creature::setColour(int r, int g, int b) {
    colour = ofVec3f(r, g, b);
}

void Creature::click(int x, int y, int b) {

}
