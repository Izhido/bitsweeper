#ifndef GAMELOSTNOTVISIBLEWAITSTATECLASS_H
#define GAMELOSTNOTVISIBLEWAITSTATECLASS_H

#include "StateClass.h"

#define GAME_LOST_NOT_VISIBLE_WAIT_STATE 28

class GameLostNotVisibleWaitStateClass
: public StateClass
{
public:
	GameLostNotVisibleWaitStateClass();

	bool Start(class CommonDataClass* CommonData);

	bool Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	int Count;

};

#endif
