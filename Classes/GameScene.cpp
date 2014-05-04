//
//  GameScene.cpp
//  InTheField
//
//  Created by Minko on 14-4-26.
//
//

#include "GameScene.h"
#include "MKNormalPeople.h"
#include "Wife.h"
#include <SimpleAudioEngine.h>

using namespace CocosDenshion;

const int BACKGROUND = -100;
const int GROUND = 100;
//static const int Ground
Scene* GameScene::createScene()
{
    auto scene = Scene::create();
    auto layer = GameScene::create();
    
    scene->addChild(layer);
    return scene;
}

void GameScene::onEnter()
{
    Layer::onEnter();
    SpriteFrameCache::getInstance()->addSpriteFramesWithFile("Main.plist");
    
    initBackground();
    
    addHero();
    addWife();
    addPet();
    addMonster();
    scheduleUpdate();
}

void GameScene::initBackground()
{
    auto textureCache = Director::getInstance()->getTextureCache();
    auto background = textureCache->getTextureForKey("Background.png");
    auto backgroundSp = Sprite::createWithTexture(background);
    backgroundSp->setAnchorPoint(Point::ZERO);
    addChild(backgroundSp, BACKGROUND);
    auto ground = textureCache->getTextureForKey("Ground.png");
    auto groundSp = Sprite::createWithTexture(ground);
    groundSp->setAnchorPoint(Point::ZERO);
    addChild(groundSp, GROUND);
    auto blue = LayerColor::create(Color4B(16, 102, 190, 255), ground->getContentSize().width, win_size.height);
    addChild(blue, -101);
    worldSize = ground->getContentSize();
}

void GameScene::addHero()
{
    hero = MKNormalPeople::createWithFrameName("Hero0000");
    hero->setPosition(220, GROUND_HEIGHT + hero->getContentSize().height/2);
    hero->bindingWorld(this);
    addChild(hero);
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = [=](Touch* touch, Event* e)
    {
        if(pet->getActive())
        {
            hero->jump();
        }
        else
        {
            wife->clean();
            pet->setActive(true);
        }
        return false;
    };
    getEventDispatcher()->addEventListenerWithSceneGraphPriority
    (touchListener, this);
}

void GameScene::addWife()
{
    wife = Wife::createWithFrameName("Wife0000");
    wife->cocos2d::Node::setPosition(130, GROUND_HEIGHT + wife->getContentSize().height/2);
    wife->bindingWorld(this);
    addChild(wife);
}

void GameScene::addPet()
{
    pet = Pet::createWithFrameName("Pet0000");
    pet->cocos2d::Node::setPosition(160, GROUND_HEIGHT + pet->getContentSize().height/2);
    pet->bindingWorld(this);
    addChild(pet, 101);
}

void GameScene::addMonster()
{
    srand(time(NULL));
    for(int i = 0;i < 10; i ++ )
    {
        auto _one = roundf(CCRANDOM_0_1() * 2);
        std::string index;
        std::stringstream str;
        str<<_one;
        str>>index;
        auto name = "Monster000" + index;
        auto monster = Sprite::createWithSpriteFrameName(name);
        monster->setPosition(500 + (i * 50), 170 + monster->getContentSize().height/2);
        addChild(monster, 100);
        monsters.pushBack(monster);
    }
    
}

void GameScene::update(float dtime)
{
    auto monster_iterator = monsters.begin();
    Sprite* monster;
    Size size;
    Rect testRect;
    
    Size heroSize = hero->getContentSize();
    Rect heroRect = Rect(hero->getPositionX(), hero->getPositionY(), heroSize.width, heroSize.height);
    for (monster_iterator; monster_iterator != monsters.end(); monster_iterator ++)
    {
        monster = *monster_iterator;
        size = monster->getContentSize();
        testRect.setRect(monster->getPositionX(), monster->getPositionY(), size.width, size.height);
        if(testRect.intersectsRect(heroRect))
        {
            SimpleAudioEngine::getInstance()->playEffect("hurt.wav");
            hero->setLive(false);
            unscheduleUpdate();
            gameOver();
        }
    }
}

void GameScene::gameOver()
{
    
}