//
//  MKNormalPeople.cpp
//  InTheField
//
//  Created by Minko on 14-4-26.
//
//

#include "MKNormalPeople.h"
#include "GameScene.h"
#include <SimpleAudioEngine.h>

MKNormalPeople::MKNormalPeople()
{
    jumpProcess = false;
}

void MKNormalPeople::jump()
{
    if(!isJumpInProcess())
    {
        CocosDenshion::SimpleAudioEngine::getInstance()->playEffect("jump.wav");
        jumpProcess = true;
        vy = 5.0;
        vx = 2.0;
        scheduleUpdate();
    }
}

void MKNormalPeople::reset()
{
    jumpProcess = false;
    setPositionX(100);
}

void MKNormalPeople::update(float dtime)
{
    
    auto nowY = getPositionY();
    auto nowX = getPositionX();
    vy += dy;
    auto nextY = nowY + vy;
    vx += dx;
    vx *= 0.8;
    vx = MIN(vx, 2);
    auto nextX = nowX + vx;
    if(nextY <= 170 + getContentSize().height/2)
    {
        nextY = 170 + getContentSize().height/2;
        unscheduleUpdate();
        jumpProcess = false;
    }
    setPosition(nextX, nextY);
    //镜头跟随
    auto worldLayer = static_cast<GameScene*>(world);
    if(nextX >= win_size.width/2 && worldLayer->getWorldSize().width + world->getPositionX() > win_size.width)
    {
        auto worldX = world->getPositionX();
        world->setPositionX(worldX - vx);
    }
}