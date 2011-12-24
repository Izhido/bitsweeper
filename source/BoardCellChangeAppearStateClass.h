#ifndef BOARDCELLCHANGEAPPEARSTATECLASS_H
#define BOARDCELLCHANGEAPPEARSTATECLASS_H

#include "StateClass.h"

#define BOARD_CELL_CHANGE_APPEAR_STATE 22

class BoardCellChangeAppearStateClass
: public StateClass
{
public:
	BoardCellChangeAppearStateClass();

	void Start(class CommonDataClass* CommonData);

	void Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	int Count;

};

#endif
