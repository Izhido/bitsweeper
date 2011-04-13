#ifndef POLYSAVEMANAGERERRORSENUM_H
#define POLYSAVEMANAGERERRORSENUM_H

enum PolySaveManagerErrorsEnum
{
	PolySaveErrorNone = 0,
	PolySaveErrorNoCart = 1,
	PolySaveErrorUnrecognizedCart = 2,
	PolySaveErrorDamagedHeader = 3,
	PolySaveErrorDataDoesNotExist = 4,
	PolySaveErrorDataNotEnoughSpace = 5,
	PolySaveErrorDataInvalidChecksum = 6
};

#endif
