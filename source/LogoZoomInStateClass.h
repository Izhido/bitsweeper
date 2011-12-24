#ifndef LOGOZOOMINSTATECLASS_H
#define LOGOZOOMINSTATECLASS_H

#include "StateClass.h"

#define LOGO_ZOOM_IN_STATE 1 

class LogoZoomInStateClass
: public StateClass
{
public:
	LogoZoomInStateClass();

	void Start(class CommonDataClass* CommonData);

	void Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	int Count;

	float Factor;

};

#endif
