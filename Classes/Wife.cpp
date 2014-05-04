//
//  Wife.cpp
//  InTheField
//
//  Created by Minko on 14-4-27.
//
//

#include "Wife.h"
#include "Hero.h"
#include "GameScene.h"

Wife::Wife()
:world(NULL),
sayLbl(NULL),
said(false)
{
    
}

void Wife::onEnter()
{
    Sprite::onEnter();
    scheduleUpdate();
}


void Wife::onExit()
{
    unscheduleUpdate();
    Sprite::onExit();
}


void Wife::update(float dtime)
{
    if(world == NULL || said) return;
//    auto hero = static_cast<GameScene*>(world)->getHero();
//    auto dis = abs(hero->getPositionX() - getPositionX());
    
    if(sayLbl == NULL)
    {
        sayLbl = Label::createWithTTF("It's dangerous to go alone.\nTake this.", "Marker Felt.ttf", 20);
        sayLbl->setAnchorPoint(Point(0.5, 0));
        sayLbl -> setPosition(getPositionX(), getPositionY() + getContentSize().height/2 + sayLbl->getContentSize().height);
        world->addChild(sayLbl);
        said = true;
    }
}

void Wife::clean()
{
    if(sayLbl)
    {
        sayLbl->removeFromParentAndCleanup(true);
    }
}