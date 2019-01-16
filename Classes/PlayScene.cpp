

#include "PlayScene.h"
#include "SimpleAudioEngine.h"
#include "Rock.h"
#include <vector>

USING_NS_CC;
using namespace std;

Scene* Play::createScene()
{
    return Play::create();
}

vector<Rock*> mLRock;
//Rock *mrock = new Rock;

bool Play::init()
{
  
    if ( !Scene::init() )
    {
        return false;
    }
	
	for (int i = 0; i < 11; i++)
	{
		Rock * mRock = new Rock;
		mLRock.push_back(mRock);
		this->addChild(mRock->getSprite());
	}

	scheduleUpdate();
	return true;
}

int i = 0;
int rd = random(0, 10);
void Play::update(float td)
{

	mLRock[rd]->run();
	
		
}




