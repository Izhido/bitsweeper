#include "BestScoresLineClass.h"

BestScoresLineClass::BestScoresLineClass()
: Level(LevelNone),
Seconds(0),
Minutes(0)
{
}

int BestScoresLineClass::LineSize()
{
	return sizeof(Level) + sizeof(Seconds) + sizeof(Minutes);
}

void BestScoresLineClass::LoadFrom(char* Buffer)
{
	char* b;

	b = Buffer;
	Level = *((BestScoresLineLevelEnum*)b);
	b = b + sizeof(Level);
	Seconds = *((int8*)b);
	b = b + sizeof(Seconds);
	Minutes = *((int16*)b);
}

void BestScoresLineClass::SaveTo(char* Buffer)
{
	char* b;

	b = Buffer;
	*((BestScoresLineLevelEnum*)b) = Level;
	b = b + sizeof(Level);
	*((int8*)b) = Seconds;
	b = b + sizeof(Seconds);
	*((int16*)b) = Minutes;
}

BestScoresLineClass::~BestScoresLineClass()
{
}
