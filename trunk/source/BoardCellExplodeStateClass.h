#ifndef BOARDCELLEXPLODESTATECLASS_H
#define BOARDCELLEXPLODESTATECLASS_H

#include "StateClass.h"
#include <nds/arm9/videoGL.h>

#define BOARD_CELL_EXPLODE_STATE 24

class BoardCellExplodeStateClass
: public StateClass
{
public:
	BoardCellExplodeStateClass();

	void Start(class CommonDataClass* CommonData);

	void Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	int Count;

	v16 XDisplacement;

	v16 ZDisplacement;

};

#endif
