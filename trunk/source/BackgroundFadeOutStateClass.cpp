#include "BackgroundFadeOutStateClass.h"
#include "CommonDataClass.h"
#include "StateMachineClass.h"
#include "ShutDownStateClass.h"

BackgroundFadeOutStateClass::BackgroundFadeOutStateClass()
: StateClass()
{
}

void BackgroundFadeOutStateClass::Start(CommonDataClass* CommonData)
{
	Fading.SetLength(3);
	Fading.Start[0] = 34.0 / 8.0;
	Fading.Start[1] = 139.0 / 8.0;
	Fading.Start[2] = 34.0 / 8.0;
	Fading.Finish[0] = 0;
	Fading.Finish[1] = 0;
	Fading.Finish[2] = 0;
	Fading.SetMax(10);
}

void BackgroundFadeOutStateClass::Run(CommonDataClass* CommonData)
{
	Fading.Step();
	CommonData->ClearColorR = Fading.Value[0];
	CommonData->ClearColorG = Fading.Value[1];
	CommonData->ClearColorB = Fading.Value[2];
	if(Fading.Finished())
	{
		CommonData->StateMachine->Switch(SHUT_DOWN_STATE);
	};
}

void BackgroundFadeOutStateClass::Draw(CommonDataClass* CommonData)
{
}
