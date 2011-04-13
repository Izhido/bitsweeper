#ifndef POLYSAVEMANAGERCLASS_H
#define POLYSAVEMANAGERCLASS_H

#include "PolySaveManagerErrorsEnum.h"

class PolySaveManagerClass
{
public:
	PolySaveManagerClass();

	PolySaveManagerErrorsEnum Read(unsigned char* ApplicationID, void* Data, int Size);

	PolySaveManagerErrorsEnum Write(unsigned char* ApplicationID, void* Data, int Size);

	virtual ~PolySaveManagerClass();

};

#endif
