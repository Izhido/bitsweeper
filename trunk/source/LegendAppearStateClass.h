#ifndef LEGENDAPPEARSTATECLASS_H
#define LEGENDAPPEARSTATECLASS_H

#include "StateClass.h"

#define LEGEND_APPEAR_STATE 3 

class LegendAppearStateClass
: public StateClass
{
public:
	LegendAppearStateClass();

	bool Start(class CommonDataClass* CommonData);

	bool Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	int Count;

};

#endif
