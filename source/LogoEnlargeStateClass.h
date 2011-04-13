#ifndef LOGOENLARGESTATECLASS_H
#define LOGOENLARGESTATECLASS_H

#include "StateClass.h"
#include "LinearEvaluatorClass.h"

#define LOGO_ENLARGE_STATE 19

class LogoEnlargeStateClass
: public StateClass
{
public:
	LogoEnlargeStateClass();

	bool Start(class CommonDataClass* CommonData);

	bool Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	LinearEvaluatorClass Enlarging;

};

#endif
