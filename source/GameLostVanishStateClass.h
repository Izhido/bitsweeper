#ifndef GAMELOSTVANISHSTATECLASS_H
#define GAMELOSTVANISHSTATECLASS_H

#include "StateClass.h"

#define GAME_LOST_VANISH_STATE 29

class GameLostVanishStateClass
: public StateClass
{
public:
	GameLostVanishStateClass();

	bool Start(class CommonDataClass* CommonData);

	bool Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	int Count;

};

#endif
