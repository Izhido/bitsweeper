#ifndef BOARDDISAPPEARSTATECLASS_H
#define BOARDDISAPPEARSTATECLASS_H

#include "StateClass.h"
#include "LinearEvaluatorClass.h"

#define BOARD_DISAPPEAR_STATE 20

class BoardDisappearStateClass
: public StateClass
{
public:
	BoardDisappearStateClass();

	void Start(class CommonDataClass* CommonData);

	void Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	LinearEvaluatorClass Disappearing;

};

#endif
