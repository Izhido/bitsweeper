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

	void Start(class CommonDataClass* CommonData);

	void Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	LinearEvaluatorClass Appearing;

};

#endif
