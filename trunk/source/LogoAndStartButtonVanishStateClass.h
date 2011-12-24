#ifndef LOGOANDSTARTBUTTONVANISHSTATECLASS_H
#define LOGOANDSTARTBUTTONVANISHSTATECLASS_H

#include "StateClass.h"
#include "LinearEvaluatorClass.h"

#define LOGO_AND_START_BUTTON_VANISH_STATE 6 

class LogoAndStartButtonVanishStateClass
: public StateClass
{
public:
	LogoAndStartButtonVanishStateClass();

	void Start(class CommonDataClass* CommonData);

	void Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	LinearEvaluatorClass Vanishing;

};

#endif
