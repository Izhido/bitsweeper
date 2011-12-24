#ifndef GAMELOSTDISAPPEARSTATECLASS_H
#define GAMELOSTDISAPPEARSTATECLASS_H

#include "StateClass.h"

#define GAME_LOST_DISAPPEAR_STATE 27

class GameLostDisappearStateClass
: public StateClass
{
public:
	GameLostDisappearStateClass();

	void Start(class CommonDataClass* CommonData);

	void Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	int Count;

};

#endif
