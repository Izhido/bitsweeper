#include "RandomNumberGeneratorClass.h"

const int RandomNumberGeneratorClass::n = 624;

const int RandomNumberGeneratorClass::m = 397;

unsigned long RandomNumberGeneratorClass::state[n] = {0x0UL};

int RandomNumberGeneratorClass::p = 0;

bool RandomNumberGeneratorClass::init = false;

RandomNumberGeneratorClass::RandomNumberGeneratorClass(double Seed)
{
	int i;

	if(!init)
	{
		if(Seed < 0)
		{
			Seed = -Seed;
		};
		while(Seed > 4294967295.0)
		{
			Seed = Seed / 10;
		};
		state[0] = (unsigned long)Seed;
		for (i = 1; i < n; i++)
		{
			state[i] = (1812433253UL * (state[i - 1] ^ (state[i - 1] >> 30)) + i) & 0xFFFFFFFFUL;
		};
		p = n;
		init = true;
	};
}

double RandomNumberGeneratorClass::Next()
{
	int i;
	unsigned long x;

	if(p == n)
	{
		for(i = 0; i < (n - m); i++)
		{
			state[i] = state[i + m] ^ twiddle(state[i], state[i + 1]);
		};
		for (i = n - m; i < (n - 1); i++)
		{
			state[i] = state[i + m - n] ^ twiddle(state[i], state[i + 1]);
		};
		state[n - 1] = state[m - 1] ^ twiddle(state[n - 1], state[0]);
		p = 0;
	};
	x = state[p++];
	x ^= (x >> 11);
	x ^= (x << 7) & 0x9D2C5680UL;
	x ^= (x << 15) & 0xEFC60000UL;
	return ((double)(x ^ (x >> 18))) / 4294967296.0;
}

unsigned long RandomNumberGeneratorClass::twiddle(unsigned long u, unsigned long v)
{
	return (((u & 0x80000000UL) | (v & 0x7FFFFFFFUL)) >> 1) ^ ((v & 1UL) ? 0x9908B0DFUL : 0x0UL);
}

RandomNumberGeneratorClass::~RandomNumberGeneratorClass()
{
}
