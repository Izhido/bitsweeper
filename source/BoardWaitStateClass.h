#ifndef BOARDWAITSTATECLASS_H
#define BOARDWAITSTATECLASS_H

#include "StateClass.h"

#define BOARD_WAIT_STATE 18

class BoardWaitStateClass
: public StateClass
{
public:
	BoardWaitStateClass();

	bool Start(class CommonDataClass* CommonData);

	bool Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

};

#endif
