#ifndef GAMEWONDISAPPEARSTATECLASS_H
#define GAMEWONDISAPPEARSTATECLASS_H

#include "StateClass.h"

#define GAME_WON_DISAPPEAR_STATE 32

class GameWonDisappearStateClass
: public StateClass
{
public:
	GameWonDisappearStateClass();

	bool Start(class CommonDataClass* CommonData);

	bool Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	int Count;

};

#endif
