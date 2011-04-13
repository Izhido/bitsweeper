#ifndef RANDOMNUMBERGENERATORCLASS_H
#define RANDOMNUMBERGENERATORCLASS_H

class RandomNumberGeneratorClass
{
public:
	RandomNumberGeneratorClass(double Seed);

	double Next();

	~RandomNumberGeneratorClass();

private:
	static const int n;

	static const int m;

	static unsigned long state[]; 

	static int p;

	static bool init;

	unsigned long twiddle(unsigned long u, unsigned long v);

};

#endif
