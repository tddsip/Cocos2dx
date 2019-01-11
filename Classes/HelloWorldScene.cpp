/****************************************************************************
 Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.
 
 http://www.cocos2d-x.org

 ****************************************************************************/

#include "HelloWorldScene.h"
#include "SimpleAudioEngine.h"

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
    //////////////////////////////
    // 1. super init first
    if ( !Scene::init() )
    {
        return false;
    }

    auto visibleSize = Director::getInstance()->getVisibleSize();
    Vec2 origin = Director::getInstance()->getVisibleOrigin();
	
	
    /////////////////////////////
    // 2. add a menu item with "X" image, which is clicked to quit the program
    //    you may modify it.

    // add a "close" icon to exit the progress. it's an autorelease object
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
    auto menu = Menu::create(closeItem, NULL);
    menu->setPosition(Vec2::ZERO);
    this->addChild(menu, 1);

    // 3. add your codes below...

    // add "HelloWorld" splash screen"
	auto background = Sprite::create("background2.png");
	background->setPosition(visibleSize.width /2, visibleSize.height / 2);
	background->setContentSize(visibleSize);
	addChild(background);
	// acstion run right
	auto ruright = MoveBy::create(4, Vec2(visibleSize.width /2 -50, 0));
	/*auto soldier = Sprite::create("image.png");
	soldier->setPosition(Vec2(visibleSize.width /2, visibleSize.height - 50));
	soldier->setScale(0.2);
	addChild(soldier);

	auto hulkR = Sprite::create("hulkR.png");
	hulkR->setPosition(Vec2(visibleSize.width /2 + 200, visibleSize.height - 50));
	hulkR->setScale(0.2);
	addChild(hulkR);*/

   // Sprit king
    auto sprite = Sprite::create("Kingvalue.png");
     sprite->runAction(ruright);
    if (sprite == nullptr)
    {
		problemLoading("'Kingvalue.png'");
    }
    else
    {
        // position the sprite on the center of the screen
        sprite->setPosition(Vec2(50, 50));
		sprite->setScale(0.2);

        // add the sprite as a child to this layer
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
