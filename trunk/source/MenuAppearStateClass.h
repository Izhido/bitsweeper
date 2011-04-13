#ifndef MENUAPPEARSTATECLASS_H
#define MENUAPPEARSTATECLASS_H

#include "StateClass.h"
#include "LinearEvaluatorClass.h"

#define MENU_APPEAR_STATE 11 

class MenuAppearStateClass
: public StateClass
{
public:
	MenuAppearStateClass();

	bool Start(class CommonDataClass* CommonData);

	bool Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	LinearEvaluatorClass Appearing;

};

#endif
