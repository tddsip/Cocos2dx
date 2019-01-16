#include "space.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;


Space::Space()
{

}

Space::~Space()
{
}

void Space::setPos(int X, int Y)
{
	this->mPosX = X;
	this->mPosY = Y;
	this->mSprite->setPosition(Vec2(mPosX, mPosY));
}

Sprite * Space::getSprite()
{
	return this->mSprite;
}

void Space::setSprite(Sprite * sprite)
{
	this->mSprite = sprite;
}
