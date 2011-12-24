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

	void Start(class CommonDataClass* CommonData);

	void Run(class CommonDataClass* CommonData);

	void Draw(CommonDataClass* CommonData);

private:
	LinearEvaluatorClass Zooming;

};

#endif
