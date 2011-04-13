#ifndef GAMEWONVANISHSTATECLASS_H
#define GAMEWONVANISHSTATECLASS_H

#include "StateClass.h"

#define GAME_WON_VANISH_STATE 34

class GameWonVanishStateClass
: public StateClass
{
public:
	GameWonVanishStateClass();

	bool Start(class CommonDataClass* CommonData);

	bool Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	int Count;

};

#endif
