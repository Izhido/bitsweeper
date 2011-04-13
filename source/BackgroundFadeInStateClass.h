#ifndef BACKGROUNDFADEINSTATECLASS_H
#define BACKGROUNDFADEINSTATECLASS_H

#include "StateClass.h"
#include "LinearEvaluatorClass.h"

#define BACKGROUND_FADE_IN_STATE 0 

class BackgroundFadeInStateClass
: public StateClass
{
public:
	BackgroundFadeInStateClass();

	bool Start(class CommonDataClass* CommonData);

	bool Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	LinearEvaluatorClass Fading;

};

#endif
