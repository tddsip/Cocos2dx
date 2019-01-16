
#ifndef __Spaceship_H__
#define __Spaceship_H__

#include "cocos2d.h"

class SpaceShip : public cocos2d::Scene
{
public:
    static cocos2d::Scene* createScene();

    virtual bool init();
    
    CREATE_FUNC(SpaceShip);
};

#endif // __Spaceship_H__