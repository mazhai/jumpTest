//
//  NumberTwoScene.h
//  jumpTest
//
//  Created by mazhai on 14-8-14.
//
//

#ifndef __jumpTest__NumberTwoScene__
#define __jumpTest__NumberTwoScene__

#include <iostream>
#include "cocos2d.h"

USING_NS_CC;
class NumberTwoScene:public Layer{
public:
    static cocos2d::Scene* createScene();
    virtual bool init();
    CREATE_FUNC(NumberTwoScene);
    void back(Ref *ref);
};
#endif /* defined(__jumpTest__NumberTwoScene__) */
