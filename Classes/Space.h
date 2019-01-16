
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
	void setPos(int X, int Y);
	Sprite* getSprite();
	void setSprite(Sprite * sprite);
private:
	Sprite * mSprite;  
	int mPosX, mPosY;
};

#endif // __Space_H__