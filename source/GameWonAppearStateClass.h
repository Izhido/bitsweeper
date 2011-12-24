#ifndef GAMEWONAPPEARSTATECLASS_H
#define GAMEWONAPPEARSTATECLASS_H

#include "StateClass.h"

#define GAME_WON_APPEAR_STATE 30

class GameWonAppearStateClass
: public StateClass
{
public:
	GameWonAppearStateClass();

	void Start(class CommonDataClass* CommonData);

	void Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	int Count;

};

#endif
