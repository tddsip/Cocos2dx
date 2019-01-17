
#ifndef __SpaceShip_H__
#define __SpaceShip_H__

#include "cocos2d.h"
#include "space.h"
using namespace std;
using namespace cocos2d;

class SpaceShip : public Space
{
public:
	SpaceShip(Scene*);
	~SpaceShip();
	void createEvent(Scene*);
	bool onTouchBegan(Touch* touch, Event *event);
	void onTouchMoved(Touch* touch, Event *event);
	void onTouchEnded(Touch* touch, Event *event);
private:
	Size visibleSize;
};

#endif // __SpaceShip_H__