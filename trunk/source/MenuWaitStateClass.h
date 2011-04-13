#ifndef MENUWAITSTATECLASS_H
#define MENUWAITSTATECLASS_H

#include "StateClass.h"

#define MENU_WAIT_STATE 14 

class MenuWaitStateClass
: public StateClass
{
public:
	MenuWaitStateClass();

	bool Start(class CommonDataClass* CommonData);

	bool Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	bool LButtonPressed;

	bool RButtonPressed;

};

#endif
