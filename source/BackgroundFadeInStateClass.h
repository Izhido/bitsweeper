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

	void Start(class CommonDataClass* CommonData);

	void Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	LinearEvaluatorClass Fading;

};

#endif
