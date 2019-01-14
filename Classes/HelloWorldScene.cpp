/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org

 ****************************************************************************/

#include "HelloWorldScene.h"
#include "Play.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"

USING_NS_CC;

Scene* HelloWorld::createScene()
{
    return HelloWorld::create();
}

// Print useful error message instead of segfaulting when files are not there.
static void problemLoading(const char* filename)
{
    printf("Error while loading: %s\n", filename);
    printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}

// on "init" you need to initialize your instance
bool HelloWorld::init()
{
 
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	// play
	auto playItem = MenuItemFont::create("Play",
		CC_CALLBACK_1(HelloWorld::menuPlayCallback, this));
	playItem->setPosition(visibleSize.width / 2, visibleSize.height / 2 -50);
	// close
    auto closeItem = MenuItemImage::create(
                                           "CloseNormal.png",
                                           "CloseSelected.png",
                                           CC_CALLBACK_1(HelloWorld::menuCloseCallback, this));

    if (closeItem == nullptr ||
        closeItem->getContentSize().width <= 0 ||
        closeItem->getContentSize().height <= 0)
    {
        problemLoading("'CloseNormal.png' and 'CloseSelected.png'");
    }
    else
    {
        float x = origin.x + visibleSize.width - closeItem->getContentSize().width/2;
        float y = origin.y + closeItem->getContentSize().height/2;
        closeItem->setPosition(Vec2(x,y));
    }
	
    // create menu, it's an autorelease object
    auto menu = Menu::create(playItem,closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

	// backroug
	auto background = Sprite::create("background2.png");
	background->setPosition(visibleSize.width /2, visibleSize.height / 2);
	background->setContentSize(visibleSize);
	addChild(background);
	// label 
	auto label = Label::createWithTTF("What do you mean ?", "fonts/Marker Felt.ttf", 18);
	label->setPosition(visibleSize.width / 2, visibleSize.height / 2 + 100);
	addChild(label);

	// action run 
	auto ruright = MoveBy::create(0.3, Vec2(20, 0));
	auto runup = MoveBy::create(0.5, Vec2(0, 30));
	auto rundown = MoveBy::create(0.5, Vec2(0, -30));
	

   // Sprit king
    auto sprite = Sprite::create("Kingvalue.png");
	auto sequence = Sequence::create(ruright, runup, rundown, nullptr);
	sprite->runAction(RepeatForever::create(sequence));

    if (sprite == nullptr)
    {
		problemLoading("'Kingvalue.png'");
    }
    else
    {
        sprite->setPosition(Vec2(50, 50));
		sprite->setScale(0.2);
        this->addChild(sprite, 0);
    }
    return true;
	
}


void HelloWorld::menuCloseCallback(Ref* pSender)
{
    //Close the cocos2d-x game scene and quit the application
    Director::getInstance()->end();

    #if (CC_TARGET_PLATFORM == CC_PLATFORM_IOS)
    exit(0);
#endif

}
void HelloWorld::menuPlayCallback(Ref* pSender)
{
	auto gotoNext = CallFunc::create([]() {
		Director::getInstance()->replaceScene(Play::createScene());
	});
	auto sequence = Sequence::create( gotoNext, nullptr);
	runAction(sequence);
}
