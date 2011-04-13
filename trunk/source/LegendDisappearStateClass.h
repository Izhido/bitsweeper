#ifndef LEGENDDISAPPEARSTATECLASS_H
#define LEGENDDISAPPEARSTATECLASS_H

#include "StateClass.h"

#define LEGEND_DISAPPEAR_STATE 9 

class LegendDisappearStateClass
: public StateClass
{
public:
	LegendDisappearStateClass();

	bool Start(class CommonDataClass* CommonData);

	bool Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	int Count;

};

#endif
