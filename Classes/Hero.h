//
//  Hero.h
//  InTheField
//
//  Created by Minko on 14-4-26.
//
//

#ifndef __InTheField__Hero__
#define __InTheField__Hero__

#include <cocos2d.h>

USING_NS_CC;

class Hero:public Sprite
{
public:
    virtual void jump() = 0;
    inline bool isJumpInProcess(){return jumpProcess;};
    virtual void reset() = 0;
    inline void bindingWorld(Layer* gameLayer){world = gameLayer;};
    inline int getVx(){return vx;};
    inline int getVy(){return vy;};
    CC_SYNTHESIZE(bool, live, Live);
private:
    
    
protected:
    float vy;
    float vx;
    Layer* world;
    bool jumpProcess;
    Hero(){};
};

#endif /* defined(__InTheField__Hero__) */
