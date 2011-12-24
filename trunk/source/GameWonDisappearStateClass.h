#ifndef GAMEWONDISAPPEARSTATECLASS_H
#define GAMEWONDISAPPEARSTATECLASS_H

#include "StateClass.h"

#define GAME_WON_DISAPPEAR_STATE 32

class GameWonDisappearStateClass
: public StateClass
{
public:
	GameWonDisappearStateClass();

	void Start(class CommonDataClass* CommonData);

	void Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	int Count;

};

#endif
