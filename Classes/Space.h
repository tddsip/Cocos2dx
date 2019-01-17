
#ifndef __Space_H__
#define __Space_H__

#include "cocos2d.h"
using namespace std;
using namespace cocos2d;

class Space 
{
public:
	Space();
	virtual ~Space();
	void setPos(float X, float Y);
	Sprite* getSprite();
	void setSprite(Sprite * sprite);
	void setIsAlive(bool mIsAlive);
	bool getIsAlive();
protected:
	Sprite * mSprite;
	bool mIsAlive;
};
#endif // __Space_H__