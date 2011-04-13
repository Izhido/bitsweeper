#ifndef LINEAREVALUATORCLASS_H
#define LINEAREVALUATORCLASS_H

class LinearEvaluatorClass
{
public:
	double* Start;

	double* Finish;

	double* Value;

	LinearEvaluatorClass();

	void SetLength(int NewLength);

	void SetMax(int NewMax);

	void Step();

	bool Finished();

	virtual ~LinearEvaluatorClass();

private:
	int Length;

	int Max;

	int Count;

	double* Increment;

};

#endif
