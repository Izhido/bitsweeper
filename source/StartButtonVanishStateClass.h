#ifndef STARTBUTTONVANISHSTATECLASS_H
#define STARTBUTTONVANISHSTATECLASS_H

#include "StateClass.h"
#include "LinearEvaluatorClass.h"

#define START_BUTTON_VANISH_STATE 10

class StartButtonVanishStateClass
: public StateClass
{
public:
	StartButtonVanishStateClass();

	bool Start(class CommonDataClass* CommonData);

	bool Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	LinearEvaluatorClass Vanishing;

};

#endif
