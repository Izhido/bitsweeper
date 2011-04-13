#ifndef GAMEWONAPPEARSTATECLASS_H
#define GAMEWONAPPEARSTATECLASS_H

#include "StateClass.h"

#define GAME_WON_APPEAR_STATE 30

class GameWonAppearStateClass
: public StateClass
{
public:
	GameWonAppearStateClass();

	bool Start(class CommonDataClass* CommonData);

	bool Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	int Count;

};

#endif
