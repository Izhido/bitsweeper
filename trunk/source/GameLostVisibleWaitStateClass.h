#ifndef GAMELOSTVISIBLEWAITSTATECLASS_H
#define GAMELOSTVISIBLEWAITSTATECLASS_H

#include "StateClass.h"

#define GAME_LOST_VISIBLE_WAIT_STATE 26

class GameLostVisibleWaitStateClass
: public StateClass
{
public:
	GameLostVisibleWaitStateClass();

	void Start(class CommonDataClass* CommonData);

	void Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	int Count;

};

#endif
