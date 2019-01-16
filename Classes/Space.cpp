#include "space.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;


Space::Space()
{

}

Space::~Space()
{
}

void Space::setPos(float X, float Y)
{
	this->mSprite->setPosition(X, Y);
}

Sprite * Space::getSprite()
{
	return this->mSprite;
}

void Space::setSprite(Sprite * sprite)
{
	this->mSprite = sprite;
}

void Space::setIsAlive(bool mIsAlive)
{
	this->mIsAlive = mIsAlive;
}

bool Space::getIsAlive()
{
	return mIsAlive;
}
