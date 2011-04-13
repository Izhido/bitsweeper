#ifndef STARTBUTTONZOOMINSTATECLASS_H
#define STARTBUTTONZOOMINSTATECLASS_H

#include "StateClass.h"
#include "LinearEvaluatorClass.h"

#define START_BUTTON_ZOOM_IN_STATE 2 

class StartButtonZoomInStateClass
: public StateClass
{
public:
	StartButtonZoomInStateClass();

	bool Start(class CommonDataClass* CommonData);

	bool Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	LinearEvaluatorClass Zooming;

};

#endif
