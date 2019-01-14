#ifndef __Play__
#define __Play__

#include "cocos2d.h"

class Play : public cocos2d::Scene
{
public:
	static cocos2d::Scene* createScene();

	virtual bool init();
	CREATE_FUNC(Play);
};

#endif // __Play__