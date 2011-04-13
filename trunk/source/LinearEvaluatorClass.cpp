#include "LinearEvaluatorClass.h"

LinearEvaluatorClass::LinearEvaluatorClass()
: Start(0),
Finish(0),
Value(0),
Length(0),
Max(0),
Increment(0)
{
}

void LinearEvaluatorClass::SetLength(int NewLength)
{
	delete[] Increment;
	delete[] Value;
	delete[] Finish;
	delete[] Start;
	Start = new double[NewLength];
	Finish = new double[NewLength];
	Value = new double[NewLength];
	Increment = new double[NewLength];
	Length = NewLength;
}

void LinearEvaluatorClass::SetMax(int NewMax)
{
	int i;

	Max = NewMax;
	Count = 0;
	for(i = 0; i < Length; i++)
	{
		if(Max > 0)
		{
			Increment[i] = (Finish[i] - Start[i]) / NewMax;
		} else
		{
			Increment[i] = 0;
		};
		Value[i] = Start[i];
	};
}

void LinearEvaluatorClass::Step()
{
	int i;

	if(Count < Max)
	{
		Count++;
		if(Count < Max)
		{
			for(i = 0; i < Length; i++)
			{
				Value[i] = Value[i] + Increment[i];
			};
		} else if(Count == Max)
		{
			for(i = 0; i < Length; i++)
			{
				Value[i] = Finish[i];
			};
		};
	};
}

bool LinearEvaluatorClass::Finished()
{
	return (Count >= Max);
}

LinearEvaluatorClass::~LinearEvaluatorClass()
{
	delete[] Increment;
	delete[] Value;
	delete[] Finish;
	delete[] Start;
}
