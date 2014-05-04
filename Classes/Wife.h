//
//  Wife.h
//  InTheField
//
//  Created by Minko on 14-4-27.
//
//

#ifndef __InTheField__Wife__
#define __InTheField__Wife__

#include <cocos2d.h>

USING_NS_CC;

class Wife: public Sprite
{
public:
    CREATE_WITH_NAME_FUNC(Wife);
    inline void bindingWorld(Layer* gameLayer){world = gameLayer;};
    void clean();
private:
    Wife();
    Layer* world;
    void onEnter();
    void onExit();
    void update(float dtime);
private:
    Label* sayLbl;
    bool said;
};

#endif /* defined(__InTheField__Wife__) */
