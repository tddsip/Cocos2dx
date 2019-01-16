#include "rock.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Rock::Rock()
{
	auto sprite = Sprite::create("rock.png");
	this->setIsAlive(true);
	this->setSprite(sprite);
	int mRand = random(0, 400);
	this->setPos(mRand, 300);
}

Rock::~Rock()
{
}

void Rock::run()
{
	float x = this->getSprite()->getPosition().x;
	float y = this->getSprite()->getPosition().y;
	this->setPos(x, y - 5);
}
