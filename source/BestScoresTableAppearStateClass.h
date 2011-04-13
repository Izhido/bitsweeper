#ifndef BESTSCORESTABLEAPPEARSTATECLASS_H
#define BESTSCORESTABLEAPPEARSTATECLASS_H

#include "StateClass.h"

#define BEST_SCORES_TABLE_APPEAR_STATE 35

class BestScoresTableAppearStateClass
: public StateClass
{
public:
	BestScoresTableAppearStateClass();

	bool Start(class CommonDataClass* CommonData);

	bool Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	int Count;

};

#endif
