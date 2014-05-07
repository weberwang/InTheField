//
//  MKActionController.h
//  InTheField
//
//  Created by Minko on 14-5-4.
//
//

#ifndef __InTheField__MKActionController__
#define __InTheField__MKActionController__

#include <cocos2d.h>
#include "Hero.h"
USING_NS_CC;

class MKActionController
{
public:
    static void registControl(void* view, Hero* node);
    static Hero* player;
};

#endif /* defined(__InTheField__MKActionController__) */
