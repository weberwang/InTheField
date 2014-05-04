//
//  GameScene.h
//  InTheField
//
//  Created by Minko on 14-4-26.
//
//

#ifndef __InTheField__GameScene__
#define __InTheField__GameScene__

#include <cocos2d.h>
#include "Hero.h"
#include "Pet.h"
#include "Wife.h"

USING_NS_CC;

class GameScene: public Layer
{
public:
    static Scene* createScene();
    CREATE_FUNC(GameScene);
    inline Size getWorldSize(){return worldSize;};
    inline Hero* getHero(){return hero;};
private:
    Size worldSize;
    void onEnter();
    void initBackground();
    void addHero();
    void addWife();
    void addPet();
    void addMonster();
    void update(float dtime);
    void gameOver();
private:
    Hero* hero;
    Pet* pet;
    Wife* wife;
    Vector<Sprite*> monsters;
    static const int GROUND_HEIGHT = 170;
};

#endif /* defined(__InTheField__GameScene__) */
