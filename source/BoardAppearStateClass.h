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

	void Start(class CommonDataClass* CommonData);

	void Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	LinearEvaluatorClass Appearing;

};

#endif
