#include "BoardCellClass.h"

BoardCellClass::BoardCellClass()
: X(0),
Z(0),
Explodes(false),
ExplodingCellsAround(0),
JustMarkedForUncover(false),
State(CellCovered)
{
}

BoardCellClass::~BoardCellClass()
{
}
