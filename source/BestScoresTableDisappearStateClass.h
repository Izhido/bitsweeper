#ifndef BESTSCORESTABLEDISAPPEARSTATECLASS_H
#define BESTSCORESTABLEDISAPPEARSTATECLASS_H

#include "StateClass.h"

#define BEST_SCORES_TABLE_DISAPPEAR_STATE 37

class BestScoresTableDisappearStateClass
: public StateClass
{
public:
	BestScoresTableDisappearStateClass();

	void Start(class CommonDataClass* CommonData);

	void Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	int Count;

};

#endif
