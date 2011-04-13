#ifndef GAMELOSTAPPEARSTATECLASS_H
#define GAMELOSTAPPEARSTATECLASS_H

#include "StateClass.h"

#define GAME_LOST_APPEAR_STATE 25

class GameLostAppearStateClass
: public StateClass
{
public:
	GameLostAppearStateClass();

	bool Start(class CommonDataClass* CommonData);

	bool Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	int Count;

};

#endif
