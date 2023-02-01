//
//  LeadGoose.hpp
//  Week03
//
//  Created by Nicholas Pan on 2023/1/31.
//

#ifndef LeadGoose_hpp
#define LeadGoose_hpp

#include <stdio.h>
#include "ofMain.h"
#import "Creature.hpp"

class LeadGoose: public Creature {
private:
    void clickPosition(int x, int y);
    void clickColour();
public:
    LeadGoose();
    ~LeadGoose();


    // Random Oscillate
    void update(std::vector<Creature *> &otherBoids, ofVec3f &min, ofVec3f &max);

    void draw();
    void click(int x, int y, int b) override;
};

#endif /* LeadGoose_hpp */
