//
//  Pet.h
//  InTheField
//
//  Created by Minko on 14-4-28.
//
//

#ifndef __InTheField__Pet__
#define __InTheField__Pet__

#include <cocos2d.h>
#include "Hero.h"

USING_NS_CC;

class Pet:public Sprite
{
public:
    CREATE_WITH_NAME_FUNC(Pet);
    inline void bindingWorld(Layer* gameLayer){world = gameLayer;};
    CC_SYNTHESIZE(bool, active, Active);
private:
    Layer* world;
private:
    float vx;
    float vy;
    bool jumped;
    void onEnter();
    void addLight();
    void update(float dtime);
    Hero* hero;
};

#endif /* defined(__InTheField__Pet__) */
