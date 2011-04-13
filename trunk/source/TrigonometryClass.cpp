#include "TrigonometryClass.h"

TrigonometryClass::TrigonometryClass()
{
	Pi = 3.1415926535897932384626433832795028841971693993751058209749445923078164062862089986280348253421170679;
}

double TrigonometryClass::Sin(double Angle)
{
	bool Positive;
	double Degree;
	double Numerator;
	double Denominator;
	double Result;

	while(Angle < (-Pi))
	{
		Angle = Angle + Pi;
	};
	while(Angle > Pi)
	{
		Angle = Angle - Pi;
	};
	Positive = true;
	Degree = 1;
	Numerator = Angle;
	Denominator = 1;
	Result = Angle;
	while(Degree < 9)
	{
		Positive = !Positive;
		Degree = Degree + 1;
		Numerator = Numerator * Angle;
		Denominator = Denominator * Degree;
		Degree = Degree + 1;
		Numerator = Numerator * Angle;
		Denominator = Denominator * Degree;
		if(Positive)
		{
			Result = Result + (Numerator / Denominator);
		} else
		{
			Result = Result - (Numerator / Denominator);
		};
	};
	return Result;
}

double TrigonometryClass::Cos(double Angle)
{
	bool Positive;
	double Degree;
	double Numerator;
	double Denominator;
	double Result;

	while(Angle < (-Pi))
	{
		Angle = Angle + Pi;
	};
	while(Angle > Pi)
	{
		Angle = Angle - Pi;
	};
	Positive = true;
	Degree = 0;
	Numerator = 1;
	Denominator = 1;
	Result = 1;
	while(Degree < 10)
	{
		Positive = !Positive;
		Degree = Degree + 1;
		Numerator = Numerator * Angle;
		Denominator = Denominator * Degree;
		Degree = Degree + 1;
		Numerator = Numerator * Angle;
		Denominator = Denominator * Degree;
		if(Positive)
		{
			Result = Result + (Numerator / Denominator);
		} else
		{
			Result = Result - (Numerator / Denominator);
		};
	};
	return Result;
}

TrigonometryClass::~TrigonometryClass()
{
}
