#ifndef BOARDCELLCHANGEDISAPPEARSTATECLASS_H
#define BOARDCELLCHANGEDISAPPEARSTATECLASS_H

#include "StateClass.h"

#define BOARD_CELL_CHANGE_DISAPPEAR_STATE 21

class BoardCellChangeDisappearStateClass
: public StateClass
{
public:
	BoardCellChangeDisappearStateClass();

	void Start(class CommonDataClass* CommonData);

	void Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	int Count;

};

#endif
