
#ifndef __ROCK_H__
#define __ROCK_H__

#include "cocos2d.h"
#include "Space.h"
using namespace std;
using namespace cocos2d;

class Rock : public Space
{
public:
	Rock();
	~Rock();
	void run();
};

#endif // __ROCK_H__