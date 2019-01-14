/****************************************************************************
Copyright (c) 2017-2018 Xiamen Yaji Software Co., Ltd.

http://www.cocos2d-x.org

****************************************************************************/

#include "Play.h"
#include "SimpleAudioEngine.h"
#include "ui/CocosGUI.h"
#include <vector>

USING_NS_CC;

Scene* Play::createScene()
{
	return Play::create();
}

static void problemLoading(const char* filename)
{
	printf("Error while loading: %s\n", filename);
	printf("Depending on how you compiled you might have to add 'Resources/' in front of filenames in HelloWorldScene.cpp\n");
}


bool Play::init()
{

	if (!Scene::init())
	{
		return false;
	}
	

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto background = Sprite::create("background4.png");
	background->setPosition(visibleSize.width / 2, visibleSize.height /2);
	background->setContentSize(visibleSize);
	addChild(background);

	// Animation
	auto dragon = SpriteFrameCache::getInstance();
	dragon->addSpriteFramesWithFile("dragon.plist");
	Vector<SpriteFrame*> plist;
	char name[50];
	for (int i = 1; i < 56; i++) {
		sprintf(name, "dragon (%d).png", i);
		plist.pushBack(dragon->getSpriteFrameByName(name));
	}
	auto dragon1 = Sprite::createWithSpriteFrameName("dragon (1).png");
	addChild(dragon1);
	dragon1->setPosition(Vec2(-10 , visibleSize.height / 2));
	auto animation = Animation::createWithSpriteFrames(plist, 1.0f / 8);
	dragon1->runAction(RepeatForever::create(Animate::create(animation)));
	auto runRight = MoveBy::create(5, Vec2(350, 100));
	dragon1->setScale(0.5);
	dragon1->runAction(runRight);

	return true;

}