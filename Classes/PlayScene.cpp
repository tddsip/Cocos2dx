

#include "PlayScene.h"
#include "SimpleAudioEngine.h"
#include "Rock.h"
#include <vector>
USING_NS_CC;

Scene* Play::createScene()
{
    return Play::create();
}


bool Play::init()
{
  
    if ( !Scene::init() )
    {
        return false;
    }

   
    return true;
}


