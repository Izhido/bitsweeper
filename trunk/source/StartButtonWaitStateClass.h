#ifndef STARTBUTTONWAITSTATECLASS_H
#define STARTBUTTONWAITSTATECLASS_H

#include "StateClass.h"

#define START_BUTTON_WAIT_STATE 4 

class StartButtonWaitStateClass
: public StateClass
{
public:
	StartButtonWaitStateClass();

	bool Start(class CommonDataClass* CommonData);

	bool Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

};

#endif
