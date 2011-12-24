#include "BackgroundFadeInStateClass.h"
#include "CommonDataClass.h"
#include "StateMachineClass.h"
#include "LogoZoomInStateClass.h"

BackgroundFadeInStateClass::BackgroundFadeInStateClass()
: StateClass()
{
}

void BackgroundFadeInStateClass::Start(CommonDataClass* CommonData)
{
	Fading.SetLength(3);
	Fading.Start[0] = 0;
	Fading.Start[1] = 0;
	Fading.Start[2] = 0;
	Fading.Finish[0] = 34.0 / 8.0;
	Fading.Finish[1] = 139.0 / 8.0;
	Fading.Finish[2] = 34.0 / 8.0;
	Fading.SetMax(10);
}

void BackgroundFadeInStateClass::Run(CommonDataClass* CommonData)
{
	Fading.Step();
	CommonData->ClearColorR = Fading.Value[0];
	CommonData->ClearColorG = Fading.Value[1];
	CommonData->ClearColorB = Fading.Value[2];
	if(Fading.Finished())
	{
		CommonData->StateMachine->Switch(LOGO_ZOOM_IN_STATE);
	};
}

void BackgroundFadeInStateClass::Draw(CommonDataClass* CommonData)
{
}
