#ifndef MENUDISAPPEARSTATECLASS_H
#define MENUDISAPPEARSTATECLASS_H

#include "StateClass.h"
#include "LinearEvaluatorClass.h"

#define MENU_DISAPPEAR_STATE 15 

class MenuDisappearStateClass
: public StateClass
{
public:
	MenuDisappearStateClass();

	void Start(class CommonDataClass* CommonData);

	void Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	LinearEvaluatorClass Disappearing;

};

#endif
