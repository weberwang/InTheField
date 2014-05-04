//
//  WelcomeScene.h
//  InTheField
//
//  Created by Minko on 14-4-26.
//
//

#ifndef __InTheField__WelcomeScene__
#define __InTheField__WelcomeScene__

#include <cocos2d.h>

USING_NS_CC;

class WelcomeScene: public Layer
{
public:
    static Scene* createScene();
    CREATE_FUNC(WelcomeScene);
    
private:
    bool init();
    void onEnter();
    void loadImage(Texture2D* texture);
    void showTip();
private:
    int loadedCount;
    Label* processLbl;
};

#endif /* defined(__InTheField__WelcomeScene__) */
