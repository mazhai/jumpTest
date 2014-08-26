//
//  NumberOneScene.h
//  jumpTest
//
//  Created by mazhai on 14-8-14.
//
//

#ifndef __jumpTest__NumberOneScene__
#define __jumpTest__NumberOneScene__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;

using namespace std;
class NumberOneScene:public Layer{
private:
    bool flag = true;
    int i = 0;
    
    Vector<SpriteFrame*> spriteFrames_;
public:
    // there's no 'id' in cpp, so we recommend returning the class instance pointer
    static cocos2d::Scene* createScene();
    
    // Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
    virtual bool init();
    Menu *menu;
    
    
    void changePic(Ref* ref);
    CREATE_FUNC(NumberOneScene);
    void menuCloseCallback(cocos2d::Ref* pSender);
    void onImageClick(Ref* ref);
    void menuCloseCallback1(Ref* ref);
};

#endif /* defined(__jumpTest__NumberOneScene__) */
