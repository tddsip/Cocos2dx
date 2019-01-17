#include "SpaceShip.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;
using namespace std;

SpaceShip::SpaceShip(Scene *mScene)
{
	mSprite = Sprite::create("SpaceShip1.png");
	this->setPos(100, 200);
	this->setSprite(mSprite);
	SpaceShip :: createEvent(mScene);
}

SpaceShip::~SpaceShip()
{

}

void SpaceShip::createEvent(Scene * mScene)
{
	auto listener = EventListenerTouchOneByOne::create();
	listener->onTouchBegan = CC_CALLBACK_2(SpaceShip::onTouchBegan, this);
	listener->onTouchMoved = CC_CALLBACK_2(SpaceShip::onTouchMoved, this);
	listener->onTouchEnded = CC_CALLBACK_2(SpaceShip::onTouchEnded, this);
	mScene->getEventDispatcher()->addEventListenerWithSceneGraphPriority(listener, mScene);
}

bool SpaceShip::onTouchBegan(Touch * mTouch, Event * mEvent)
{
	if (mSprite->getBoundingBox().containsPoint(
		mSprite->getParent()->convertToNodeSpace(mTouch->getLocation()))) {
		return true;
	}
	return false;
}

void SpaceShip::onTouchMoved(Touch * mTouch, Event * mEvent)
{
	visibleSize = Director::getInstance()->getVisibleSize();
	mSprite->setPosition(Vec2(mTouch->getLocation()));
	/*if (mTouch->getLocation().x <= visibleSize.width - mSprite->getContentSize().width / 2
		&& mTouch->getLocation().x >= mSprite->getContentSize().width / 2
		&& mTouch->getLocation().y <= visibleSize.height - mSprite->getContentSize().height / 2
		&& mTouch->getLocation().y >= mSprite->getContentSize().height / 2) {
		mSprite->setPosition(Vec2(mTouch->getLocation()));
	}*/
}

void SpaceShip::onTouchEnded(Touch * mTouch, Event * mEvent)
{	
}

