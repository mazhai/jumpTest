//
//  NumberTwoScene.cpp
//  jumpTest
//
//  Created by mazhai on 14-8-14.
//
//

#include "NumberTwoScene.h"
cocos2d::Scene* NumberTwoScene::createScene(){
    auto scene = Scene::create();
    auto layer = NumberTwoScene::create();
    scene -> addChild(layer);
    return scene;
}
bool NumberTwoScene::init(){
    if (!Layer::init()) {
        return false;
    }
    auto bg = Sprite::create("HelloWorld.png");
    bg -> cocos2d::Node::setPosition(Vec2(Director::getInstance()->getVisibleSize().width/2, Director::getInstance()->getVisibleSize().height/2));
    this -> addChild(bg);
    
    auto label_ = Label::createWithBMFont("fonts/boundsTestFont.fnt", "fanhui");
    MenuItemLabel *menuItemLabel_ = MenuItemLabel::create(label_, CC_CALLBACK_1(NumberTwoScene::back, this));
    auto menu = Menu::create(menuItemLabel_, NULL);
    this -> addChild(menu);
    return true;
}

void NumberTwoScene::back(Ref *ref){
    Director::getInstance()->popScene();
}


