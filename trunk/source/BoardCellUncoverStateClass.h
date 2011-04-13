#ifndef BOARDCELLUNCOVERSTATECLASS_H
#define BOARDCELLUNCOVERSTATECLASS_H

#include "StateClass.h"
#include "LinearEvaluatorClass.h"

#define BOARD_CELL_UNCOVER_STATE 23

class BoardCellUncoverStateClass
: public StateClass
{
public:
	BoardCellUncoverStateClass();

	bool Start(class CommonDataClass* CommonData);

	bool Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	LinearEvaluatorClass Uncovering;

};

#endif
