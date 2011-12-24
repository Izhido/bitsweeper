#include "StartButtonZoomInStateClass.h"
#include "CommonDataClass.h"
#include "StateMachineClass.h"
#include "LegendAppearStateClass.h"
#include "OperationsClass.h"

StartButtonZoomInStateClass::StartButtonZoomInStateClass()
: StateClass()
{
}

void StartButtonZoomInStateClass::Start(CommonDataClass* CommonData)
{
	Zooming.SetLength(4);
	Zooming.Start[0] = 0;
	Zooming.Start[1] = 0;
	Zooming.Start[2] = -0.1;
	Zooming.Start[3] = -0.1;
	Zooming.Finish[0] = -0.05;
	Zooming.Finish[1] = 0.05;
	Zooming.Finish[2] = -0.125;
	Zooming.Finish[3] = -0.075;
	Zooming.SetMax(10);
}

void StartButtonZoomInStateClass::Run(CommonDataClass* CommonData)
{
	Zooming.Step();
	if(Zooming.Finished())
	{
		CommonData->StateMachine->Switch(LEGEND_APPEAR_STATE);
	};
}

void StartButtonZoomInStateClass::Draw(CommonDataClass* CommonData)
{
	Operations::DrawLargeCenteredLogo(CommonData);
	glBindTexture(0, CommonData->Textures[START_BUTTON_IMG]);
	glBegin(GL_QUADS);
	glTexCoord2t16(inttot16(0), inttot16(0));
	glVertex3f(Zooming.Value[0], 0.0, Zooming.Value[3]);
	glTexCoord2t16(inttot16(0), inttot16(64));
	glVertex3f(Zooming.Value[0], 0.0, Zooming.Value[2]);
	glTexCoord2t16(inttot16(128), inttot16(64));
	glVertex3f(Zooming.Value[1], 0.0, Zooming.Value[2]);
	glTexCoord2t16(inttot16(128), inttot16(0));
	glVertex3f(Zooming.Value[1], 0.0, Zooming.Value[3]);
	glEnd();
}
