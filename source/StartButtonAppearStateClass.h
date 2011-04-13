#ifndef STARTBUTTONAPPEARSTATECLASS_H
#define STARTBUTTONAPPEARSTATECLASS_H

#include "StateClass.h"
#include "LinearEvaluatorClass.h"

#define START_BUTTON_APPEAR_STATE 13 

class StartButtonAppearStateClass
: public StateClass
{
public:
	StartButtonAppearStateClass();

	bool Start(class CommonDataClass* CommonData);

	bool Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	LinearEvaluatorClass Appearing;

};

#endif
