#ifndef GAMEWONNOTVISIBLEWAITSTATECLASS_H
#define GAMEWONNOTVISIBLEWAITSTATECLASS_H

#include "StateClass.h"

#define GAME_WON_NOT_VISIBLE_WAIT_STATE 33

class GameWonNotVisibleWaitStateClass
: public StateClass
{
public:
	GameWonNotVisibleWaitStateClass();

	bool Start(class CommonDataClass* CommonData);

	bool Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	int Count;

};

#endif
