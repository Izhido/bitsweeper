#ifndef GAMELOSTDISAPPEARSTATECLASS_H
#define GAMELOSTDISAPPEARSTATECLASS_H

#include "StateClass.h"

#define GAME_LOST_DISAPPEAR_STATE 27

class GameLostDisappearStateClass
: public StateClass
{
public:
	GameLostDisappearStateClass();

	bool Start(class CommonDataClass* CommonData);

	bool Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	int Count;

};

#endif
