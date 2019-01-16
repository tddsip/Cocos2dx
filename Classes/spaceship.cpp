#include "spaceship.h"
#include "SimpleAudioEngine.h"

USING_NS_CC;

Scene* SpaceShip::createScene()
{
    return SpaceShip::create();
}

bool SpaceShip::init()
{
    if ( !Scene::init() )
    {
        return false;
    }
    return true;
}