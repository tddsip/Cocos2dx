

#include "PlayScene.h"
#include "SimpleAudioEngine.h"
#include "Rock.h"
#include "spaceship.h"
#include <vector>

USING_NS_CC;
using namespace std;

Scene* Play::createScene()
{
    return Play::create();
}

vector<Rock*> mLRock;
//Rock *mrock = new Rock;

bool Play::init()
{
  
    if ( !Scene::init() )
    {
        return false;
    }

	auto visibleSize = Director::getInstance()->getVisibleSize();
	Vec2 origin = Director::getInstance()->getVisibleOrigin();

	auto backgroud = Sprite::create("background2.png");
	backgroud->setContentSize(visibleSize);
	backgroud->setPosition(visibleSize.width / 2, visibleSize.height / 2);
	addChild(backgroud);

	for (int i = 0; i < 10; i++)
	{
		Rock * mRock = new Rock;
		mLRock.push_back(mRock);
		this->addChild(mRock->getSprite());
	}
	mLRock[0]->setIsAlive(true);
	scheduleUpdate();

	// spaceship
	SpaceShip * mSpaceShip = new SpaceShip(this);
	mSpaceShip->getSprite()->setScale(0.5);
	this->addChild(mSpaceShip->getSprite());

	return true;
}

void Play::update(float td)
{
	for (int i = 0; i < 9;i++)
	{
		if (mLRock[i]->getIsAlive())
		{
			mLRock[i]->run();
		}
		if (mLRock[i]->getSprite()->getPosition().y == 480)
		{
			mLRock[i+1]->setIsAlive(true);
		}
		if (mLRock[9]->getIsAlive() == true)
		{
			mLRock[0]->setIsAlive(true);
			mLRock[9]->setIsAlive(false);
		}
	}
	

}




