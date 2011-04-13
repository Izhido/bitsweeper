#ifndef BESTSCORESTABLEWAITSTATECLASS_H
#define BESTSCORESTABLEWAITSTATECLASS_H

#include "StateClass.h"

#define BEST_SCORES_TABLE_WAIT_STATE 36

class BestScoresTableWaitStateClass
: public StateClass
{
public:
	BestScoresTableWaitStateClass();

	bool Start(class CommonDataClass* CommonData);

	bool Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

};

#endif
