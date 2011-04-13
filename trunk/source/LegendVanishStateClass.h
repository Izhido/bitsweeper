#ifndef LEGENDVANISHSTATECLASS_H
#define LEGENDVANISHSTATECLASS_H

#include "StateClass.h"

#define LEGEND_VANISH_STATE 5 

class LegendVanishStateClass
: public StateClass
{
public:
	LegendVanishStateClass();

	bool Start(class CommonDataClass* CommonData);

	bool Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	int Count;

};

#endif
