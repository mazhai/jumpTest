//
//  NumberOneScene.cpp
//  jumpTest
//
//  Created by mazhai on 14-8-14.
//
//

#include "NumberOneScene.h"
#include "NumberTwoScene.h"

// there's no 'id' in cpp, so we recommend returning the class instance pointer
cocos2d::Scene* NumberOneScene::createScene(){
    
    auto scene_ = Scene::create();
    auto layer_ = NumberOneScene::create();
    
    scene_->addChild(layer_);
    
    return scene_;
    
}

// Here's a difference. Method 'init' in cocos2d-x returns bool, instead of returning 'id' in cocos2d-iphone
bool NumberOneScene::init(){
    if(!Layer::init())
        return false;
    
//    auto onclick = MenuItemImage::create("CloseNormal.png","CloseSelected.png",
//                                         CC_CALLBACK_1(NumberOneScene::menuCloseCallback,this));
//    auto ment = Menu::create(onclick, NULL);
//    ment -> setPosition(Vec2(getContentSize().width/2, getContentSize().height/2));
//    this -> addChild(ment);
//
    
//    Sprite *sp = Sprite::create("CloseNormal.png");
//    sp -> setPosition(900,600);
//    this -> addChild(sp);
//    
//    
//    MenuItemFont * itemFont = MenuItemFont::create("lanou",CC_CALLBACK_1(NumberOneScene::menuCloseCallback, this));
//    MenuItemFont * itemFont2 = MenuItemFont::create("lanou",CC_CALLBACK_1(NumberOneScene::menuCloseCallback, this));
//    itemFont -> setColor(Color3B::GREEN);
//    itemFont2 -> setColor(Color3B::GREEN);
//
//    
//    MenuItemImage *itemImage1 = MenuItemImage::create("btn-a-0.png", "btn-b-0.png",CC_CALLBACK_1(NumberOneScene::onImageClick, this));
//    
//    
//    auto itemOn1 = MenuItemImage::create("btn-a-0.png", "btn-a-0.png");
//    auto itemOn2 = MenuItemImage::create("btn-b-0.png", "btn-b-0.png");
//    auto itemT = MenuItemToggle::createWithCallback(CC_CALLBACK_1(NumberOneScene::onImageClick, this), itemOn1,itemOn2,NULL);
//    
//    
//    menu = Menu::create(itemImage1,itemT,NULL);
//    
//    menu -> alignItemsHorizontallyWithPadding(50);
//    this -> addChild(menu);
    
    for(int i = 1 ; i <= 3 ; i++){
        char c[10];
        sprintf(c, "%d.jpg",i);
        string str = c;
        
        
        Texture2D *tex = Director::getInstance() -> getTextureCache()->addImage(str);

        SpriteFrame *spriteFrame_ =SpriteFrame::createWithTexture(tex,Rect(0,0,tex->getContentSize().width,tex->getContentSize().height));
        SpriteFrameCache::getInstance()-> addSpriteFrame(spriteFrame_, "snow");
        spriteFrames_.pushBack(spriteFrame_);
    }
    auto  bg1 = Sprite::create("bg05a.jpg");
    bg1 -> setPosition(getContentSize().width/2, getContentSize().height/2);
    bg1 -> setTag(9000);
    this -> addChild(bg1);
    
    MenuItemFont *button = MenuItemFont::create("切换背景",CC_CALLBACK_1(NumberOneScene::menuCloseCallback1, this));
    MenuItemFont *jump = MenuItemFont::create("跳转",CC_CALLBACK_1(NumberOneScene::menuCloseCallback, this));
    menu = Menu::create(button,jump,NULL);
    menu->setPosition(Vect(menu ->getPositionX(),menu ->getPositionY() +120));
    menu->alignItemsHorizontallyWithPadding(10);
    this -> addChild(menu);
    
    return true;
    
}




void NumberOneScene::menuCloseCallback1(Ref* ref){
    
    MenuItemFont *l = MenuItemFont::create("白天",CC_CALLBACK_1(NumberOneScene::changePic, this));
    l->setName("1.jpg");
    MenuItemFont *l2 = MenuItemFont::create("黑天",CC_CALLBACK_1(NumberOneScene::changePic, this));
    l2->setName("2.jpg");
    MenuItemFont *l3 = MenuItemFont::create("换景",CC_CALLBACK_1(NumberOneScene::changePic, this));
    l3->setName("3.jpg");
    Menu *menu2 = Menu::create(l,l2,l3,NULL);
    menu2->alignItemsVerticallyWithPadding(50);
    addChild(menu2);
    
//    MenuItemToggle *menuItemToggle = dynamic_cast<MenuItemToggle*>(ref);
//    auto a = menuItemToggle -> getSelectedItem();
//    
//    
//    
//    Sprite *bg = (Sprite*)getChildByTag(9000);
//    bg->setSpriteFrame(spriteFrames_.at(i));
//    i++;
//    if(i >= 3){
//        i = 0;
//    }
}

void NumberOneScene::changePic(Ref* ref){
    MenuItemFont *mif = dynamic_cast<MenuItemFont*>(ref);
    if(NULL != mif){
        Sprite  *bg1 = (Sprite*)getChildByTag(9000);
        bg1 -> setTexture(mif -> getName());
    }
}

void NumberOneScene::onImageClick(Ref* ref){
//    MenuItemToggle *tog = (MenuItemToggle*)ref;
//    MenuItemFont *menuItem = (MenuItemFont*)tog->getSelectedItem();
//    Label *lable = (Label*)menuItem ->getLabel();
//    cout<< lable->getString() <<endl;
    if(flag){
        Label *l = Label::createWithBMFont("fonts/bitmapFontChinese.fnt", "lanou");
        Label *l2 = Label::createWithBMFont("fonts/bitmapFontChinese.fnt", "start");
        Label *l3 = Label::createWithBMFont("fonts/bitmapFontChinese.fnt", "end");
        MenuItemLabel *item1 = MenuItemLabel::create(l,CC_CALLBACK_1(NumberOneScene::menuCloseCallback, this));
        MenuItemLabel *item2 = MenuItemLabel::create(l2,CC_CALLBACK_1(NumberOneScene::menuCloseCallback, this));
        MenuItemLabel *item3 = MenuItemLabel::create(l3,CC_CALLBACK_1(NumberOneScene::menuCloseCallback, this));
        Menu *menu2 = Menu::create(item1,item2,item3,NULL);
        menu2 -> alignItemsVerticallyWithPadding(50);
        menu2 -> setPosition(menu ->getPositionX() - 50,menu ->getPositionY() - menu2 ->getContentSize().height/4);
        this -> addChild(menu2);
        menu2 -> setTag(9990);
        flag = false;
    } else {
        removeChildByTag(9990);
        flag = true;
    }

    
}

void NumberOneScene::menuCloseCallback(Ref* pSender){
    
    auto numberTwoScene = NumberTwoScene::createScene();
    Director::getInstance() -> pushScene(numberTwoScene);
    
}