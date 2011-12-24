#ifndef BESTSCORESTABLEWAITSTATECLASS_H
#define BESTSCORESTABLEWAITSTATECLASS_H

#include "StateClass.h"

#define BEST_SCORES_TABLE_WAIT_STATE 36

class BestScoresTableWaitStateClass
: public StateClass
{
public:
	BestScoresTableWaitStateClass();

	void Start(class CommonDataClass* CommonData);

	void Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

};

#endif
