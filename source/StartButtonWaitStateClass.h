#ifndef STARTBUTTONWAITSTATECLASS_H
#define STARTBUTTONWAITSTATECLASS_H

#include "StateClass.h"

#define START_BUTTON_WAIT_STATE 4 

class StartButtonWaitStateClass
: public StateClass
{
public:
	StartButtonWaitStateClass();

	void Start(class CommonDataClass* CommonData);

	void Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

};

#endif
