#ifndef LOGOSHRINKSTATECLASS_H
#define LOGOSHRINKSTATECLASS_H

#include "StateClass.h"
#include "LinearEvaluatorClass.h"

#define LOGO_SHRINK_STATE 17

class LogoShrinkStateClass
: public StateClass
{
public:
	LogoShrinkStateClass();

	void Start(class CommonDataClass* CommonData);

	void Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	LinearEvaluatorClass Shrinking;

};

#endif
