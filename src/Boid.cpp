//
//  Boid.cpp
//  Week03
//
//  Created by Nicholas Pan on 2023/1/31.
//

#include "Boid.hpp"

#pragma clang diagnostic push
#pragma ide diagnostic ignored "err_typecheck_subscript_value"
#define ERROR NULL

Boid::Boid()
{
   separationWeight = 1.0f;
   cohesionWeight = 0.2f;
   alignmentWeight = 0.1f;
   
   separationThreshold = 15;
   neighbourhoodSize = 100;
   
   position = ofVec3f(ofRandom(0, 200), ofRandom(0, 200));
   velocity = ofVec3f(ofRandom(-2, 2), ofRandom(-2, 2));
   colour = ofVec3f(0, 255, 255);
}

Boid::Boid(ofVec3f &pos, ofVec3f &vel)
{
   separationWeight = 4.0f;
   cohesionWeight = 0.2f;
   alignmentWeight = 0.1f;
   
   separationThreshold = 15;
   neighbourhoodSize = 100;
   
   position = pos;
   velocity = vel;
}

Boid::~Boid()
{
   
}

ofVec3f Boid::separation(std::vector<Creature *> &otherBoids)
{
   // finds the first collision and avoids that
   // should probably find the nearest one
   // can you figure out how to do that?
   for (int i = 0; i < otherBoids.size(); i++)
   {
       if(position.distance(otherBoids[i]->getPosition()) < separationThreshold)
       {
           ofVec3f v = position -  otherBoids[i]->getPosition();
           v.normalize();
           return v;
       }
   }
    return ofVec3f();
//    return ERROR;
}

ofVec3f Boid::cohesion(std::vector<Creature *> &otherBoids)
{
   ofVec3f average(0,0,0);
   int count = 0;
   for (int i = 0; i < otherBoids.size(); i++)
   {
       if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
       {
           average += otherBoids[i]->getPosition();
           count += 1;
       }
   }
   average /= count;
   ofVec3f v =  average - position;
   v.normalize();
   return v;
}

ofVec3f Boid::alignment(std::vector<Creature *> &otherBoids)
{
   ofVec3f average(0,0,0);
   int count = 0;
   for (int i = 0; i < otherBoids.size(); i++)
   {
       if (position.distance(otherBoids[i]->getPosition()) < neighbourhoodSize)
       {
           average += otherBoids[i]->getVelocity();
           count += 1;
       }
   }
   average /= count;
   ofVec3f v =  average - velocity;
   v.normalize();
   return v;
}

ofVec3f Boid::heading(std::vector<Creature *> &otherBoids) {
    ofVec3f hp = (*otherBoids[50]).getPosition();
    ofVec3f t = hp - position;
    return t;
}

void Boid::update(std::vector<Creature *> &otherBoids, ofVec3f &min, ofVec3f &max)
{
   velocity += separationWeight*separation(otherBoids);
   velocity += cohesionWeight*cohesion(otherBoids);
   velocity += alignmentWeight*alignment(otherBoids);
   velocity += heading(otherBoids) / 1000;

    if (velocity.length() > 50) {
        velocity /= 5;
    }

   walls(min, max);
   position += velocity;
}

void Boid::draw()
{
   ofSetColor(colour.x, colour.y, colour.z);
   ofRectangle(position.x, position.y, 100, 200);
   ofCircle(position.x - 10, position.y, 10);
   ofCircle(position.x + 10, position.y, 10);
   ofSetColor(colour.x-100, colour.y-100, colour.z-100);
   ofCircle(position.x - 5, position.y, 3);
   ofCircle(position.x + 5, position.y, 3);
}

#pragma clang diagnostic pop
