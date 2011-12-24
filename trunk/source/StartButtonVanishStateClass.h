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

	void Start(class CommonDataClass* CommonData);

	void Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	LinearEvaluatorClass Vanishing;

};

#endif
