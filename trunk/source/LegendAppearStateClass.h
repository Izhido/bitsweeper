#ifndef LEGENDAPPEARSTATECLASS_H
#define LEGENDAPPEARSTATECLASS_H

#include "StateClass.h"

#define LEGEND_APPEAR_STATE 3 

class LegendAppearStateClass
: public StateClass
{
public:
	LegendAppearStateClass();

	void Start(class CommonDataClass* CommonData);

	void Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	int Count;

};

#endif
