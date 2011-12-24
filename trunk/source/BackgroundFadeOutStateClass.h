#ifndef BACKGROUNDFADEOUTSTATECLASS_H
#define BACKGROUNDFADEOUTSTATECLASS_H

#include "StateClass.h"
#include "LinearEvaluatorClass.h"

#define BACKGROUND_FADE_OUT_STATE 7 

class BackgroundFadeOutStateClass
: public StateClass
{
public:
	BackgroundFadeOutStateClass();

	void Start(class CommonDataClass* CommonData);

	void Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	LinearEvaluatorClass Fading;

};

#endif
