//
//  MKNormalPeople.h
//  InTheField
//
//  Created by Minko on 14-4-26.
//
//

#ifndef __InTheField__MKNormalPeople__
#define __InTheField__MKNormalPeople__

#include "Hero.h"

class MKNormalPeople: public Hero
{
public:
    void jump();
    void reset();
    CREATE_WITH_NAME_FUNC(MKNormalPeople);
protected:
    MKNormalPeople();
    
private:
    const float dy = -0.2;
    const float dx = 1.0;
    
    void update(float dtime);
};

#endif /* defined(__InTheField__MKNormalPeople__) */
