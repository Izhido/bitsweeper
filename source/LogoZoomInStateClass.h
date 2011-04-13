#ifndef LOGOZOOMINSTATECLASS_H
#define LOGOZOOMINSTATECLASS_H

#include "StateClass.h"

#define LOGO_ZOOM_IN_STATE 1 

class LogoZoomInStateClass
: public StateClass
{
public:
	LogoZoomInStateClass();

	bool Start(class CommonDataClass* CommonData);

	bool Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	int Count;

	float Factor;

};

#endif
