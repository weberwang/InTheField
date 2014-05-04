//
//  Pet.cpp
//  InTheField
//
//  Created by Minko on 14-4-28.
//
//

#include "Pet.h"
#include "GameScene.h"

void Pet::onEnter()
{
    Sprite::onEnter();
    addLight();
    scheduleUpdate();
}

void Pet::addLight()
{
    auto textureCache = Director::getInstance()->getTextureCache();
    auto light = Sprite::createWithTexture(textureCache->getTextureForKey("Light.png"));
    
    BlendFunc blend;
    blend.src = GL_ONE_MINUS_DST_ALPHA;
    blend.dst = GL_SRC_COLOR;
    light->setBlendFunc(blend);
    light->setAnchorPoint(Point::ZERO);
    light->setPosition(-1200, -230);
    addChild(light,101);
}

void Pet::update(float dtime)
{
    if(!active) return;
    if(hero == NULL)
    {
        hero = static_cast<GameScene*>(world)->getHero();
    }
    auto disX = hero->getPositionX() - getPositionX();

    vx = 0;
    if(disX >= 40)
    {
        setScaleX(1);
        vx = 3.0f;
    }
    else if(disX <= -40)
    {
        setScaleX(-1);
        vx = -3.0f;
    }
    auto nextX = getPositionX() + vx;
    setPositionX(nextX);
    
    auto disY = hero->getPositionY() - getPositionY();
    if(disY >= 20 && !jumped)
    {
        vy = 5;
        jumped = true;
    }
    vy -= 0.2;
    auto nextY = getPositionY() + vy;
    auto bottom = 170 + getContentSize().height/2;
    if(nextY <= bottom)
    {
        jumped = false;
        nextY = bottom;
    }

    setPositionY(nextY);
}