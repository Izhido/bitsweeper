#ifndef BESTSCORESLINECLASS_H
#define BESTSCORESLINECLASS_H

#include "BestScoresLineLevelEnum.h"
#include <nds/ndstypes.h>

class BestScoresLineClass
{
public:
	BestScoresLineLevelEnum Level;

	int8 Seconds;

	int16 Minutes;

	BestScoresLineClass();

	int LineSize();

	void LoadFrom(char* Buffer);

	void SaveTo(char* Buffer);

	virtual ~BestScoresLineClass();

};

#endif
