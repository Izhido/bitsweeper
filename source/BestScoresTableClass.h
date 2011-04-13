#ifndef BESTSCORESTABLECLASS_H
#define BESTSCORESTABLECLASS_H

#include "BestScoresLineClass.h"

class BestScoresTableClass
{
public:
	BestScoresLineClass* Lines;

	BestScoresTableClass();

	int BufferSize();

	void LoadFrom(char* Buffer);

	void SaveTo(char* Buffer);

	virtual ~BestScoresTableClass();

};

#endif
