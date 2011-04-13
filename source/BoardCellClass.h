#ifndef BOARDCELLCLASS_H
#define BOARDCELLCLASS_H

#include "BoardCellStateEnum.h"

class BoardCellClass
{
public:
	int X;

	int Z;

	bool Explodes;

	int ExplodingCellsAround;

	bool JustMarkedForUncover;

	BoardCellStateEnum State;

	BoardCellClass();

	virtual ~BoardCellClass();

};

#endif
