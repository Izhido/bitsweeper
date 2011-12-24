#ifndef BESTSCORESTABLEAPPEARSTATECLASS_H
#define BESTSCORESTABLEAPPEARSTATECLASS_H

#include "StateClass.h"

#define BEST_SCORES_TABLE_APPEAR_STATE 35

class BestScoresTableAppearStateClass
: public StateClass
{
public:
	BestScoresTableAppearStateClass();

	void Start(class CommonDataClass* CommonData);

	void Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	int Count;

};

#endif
