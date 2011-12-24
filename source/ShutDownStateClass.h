#ifndef SHUTDOWNSTATECLASS_H
#define SHUTDOWNSTATECLASS_H

#include "StateClass.h"

#define SHUT_DOWN_STATE 8 

class ShutDownStateClass
: public StateClass
{
public:
	ShutDownStateClass();

	void Start(class CommonDataClass* CommonData);

	void Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

};

#endif
