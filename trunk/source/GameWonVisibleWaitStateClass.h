#ifndef GAMEWONVISIBLEWAITSTATECLASS_H
#define GAMEWONVISIBLEWAITSTATECLASS_H

#include "StateClass.h"

#define GAME_WON_VISIBLE_WAIT_STATE 31

class GameWonVisibleWaitStateClass
: public StateClass
{
public:
	GameWonVisibleWaitStateClass();

	bool Start(class CommonDataClass* CommonData);

	bool Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	int Count;

};

#endif
