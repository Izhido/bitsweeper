#ifndef BOARDAPPEARSTATECLASS_H
#define BOARDAPPEARSTATECLASS_H

#include "StateClass.h"
#include "LinearEvaluatorClass.h"

#define BOARD_APPEAR_STATE 16 

class BoardAppearStateClass
: public StateClass
{
public:
	BoardAppearStateClass();

	bool Start(class CommonDataClass* CommonData);

	bool Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	LinearEvaluatorClass Appearing;

};

#endif
