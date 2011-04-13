#include "ArithmeticsClass.h"

ArithmeticsClass::ArithmeticsClass()
{
}

double ArithmeticsClass::SquareRoot(double Operand)
{
	int Iterations;
	double Guess;
	double Result;

	Guess = Operand / 2;
	Iterations = 16;
	while(Iterations > 0)
	{
		Result = Operand / Guess;
		if(Guess == Result)
		{
			Iterations = 0;
		} else
		{
			Guess = (Guess + Result) / 2;
			Iterations = Iterations - 1;
		};
	};
	return Result;
}

int ArithmeticsClass::Floor(double Value)
{
	int Result;

	Result = (int)Value;
	if((Value < 0)&&((double)Result != Value))
	{
		Result = Result - 1;
	};
	return Result;
}

ArithmeticsClass::~ArithmeticsClass()
{
}
