#ifndef BOARDWAITSTATECLASS_H
#define BOARDWAITSTATECLASS_H

#include "StateClass.h"

#define BOARD_WAIT_STATE 18

class BoardWaitStateClass
: public StateClass
{
public:
	BoardWaitStateClass();

	void Start(class CommonDataClass* CommonData);

	void Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

};

#endif
