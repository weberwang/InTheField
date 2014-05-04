//
//  WelcomeScene.cpp
//  InTheField
//
//  Created by Minko on 14-4-26.
//
//
#include "WelcomeScene.h"
#include "GameScene.h"
#include <SimpleAudioEngine.h>

using namespace CocosDenshion;

const float RESOURCE_COUNT = 4.0f;
Scene* WelcomeScene::createScene()
{
    auto scene = Scene::create();
    auto layer = WelcomeScene::create();
    scene->addChild(layer);
    return scene;
}

bool WelcomeScene::init()
{
    if(!Layer::init())
    {
        return false;
    }
    //加载背景

    Director::getInstance()->getTextureCache()->addImage("Intro.png");
    auto intro = Director::getInstance()->getTextureCache()->getTextureForKey("Intro.png");
    auto bg = Sprite::createWithTexture(intro);
//    bg->setAnchorPoint(Point::ZERO);
    bg->setScale(win_size.height/bg->getContentSize().height);
    bg->setPosition(win_size.width/2, win_size.height/2);
    addChild(bg);
    //加载进度
    processLbl = Label::createWithTTF("%0 loading hard...", "Marker Felt.ttf", 25);
    processLbl->setPosition(win_size.width/2, win_size.height/2);
    addChild(processLbl);
    
    //异步加载所有的资源
    Director::getInstance()->getTextureCache()->addImageAsync("Background.png", CC_CALLBACK_1(WelcomeScene::loadImage, this));
    Director::getInstance()->getTextureCache()->addImageAsync("Ground.png", CC_CALLBACK_1(WelcomeScene::loadImage, this));
    Director::getInstance()->getTextureCache()->addImageAsync("Light.png", CC_CALLBACK_1(WelcomeScene::loadImage, this));
    Director::getInstance()->getTextureCache()->addImageAsync("Main.png", CC_CALLBACK_1(WelcomeScene::loadImage, this));
    return true;
}

void WelcomeScene::onEnter()
{
    Layer::onEnter();
    auto blue = LayerColor::create(Color4B(16, 102, 190, 255));
    addChild(blue, -100);
}

void WelcomeScene::loadImage(cocos2d::Texture2D *texture)
{
    loadedCount ++;
    //加载完成提示可以游戏
    if(loadedCount == RESOURCE_COUNT)
    {
        showTip();
        return;
    }
    auto num = loadedCount/RESOURCE_COUNT * 100;
    std::string process;
    std::stringstream str;
    str<<num;
    str>>process;
    
    process += "  loading hard ...";
    processLbl->setString(process);
}

void WelcomeScene::showTip()
{
    processLbl->setString("Tap and select player");
    auto blink = Blink::create(1.5, 1);
    auto forever = RepeatForever::create(blink);
    processLbl->runAction(forever);
    auto touchListener = EventListenerTouchOneByOne::create();
    touchListener->setSwallowTouches(true);
    touchListener->onTouchBegan = [&](Touch* touch, Event* e)
    {
        TOUCH_INTO_NODE(touch, processLbl);
    };
    touchListener->onTouchEnded = [&](Touch* touch, Event* e)
    {
        SimpleAudioEngine::getInstance()->playEffect("select.wav");
        processLbl->stopAllActions();
        this->removeChild(processLbl);
        auto nextScene = GameScene::createScene();
        nextScene = TransitionFlipX::create(0.3, nextScene);
        Director::getInstance()->replaceScene(nextScene);
    };
    getEventDispatcher()->addEventListenerWithSceneGraphPriority(touchListener, processLbl);
}