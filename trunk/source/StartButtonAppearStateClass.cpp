#include "StartButtonAppearStateClass.h"
#include "CommonDataClass.h"
#include "StateMachineClass.h"
#include "LegendAppearStateClass.h"
#include "OperationsClass.h"

StartButtonAppearStateClass::StartButtonAppearStateClass()
: StateClass()
{
}

void StartButtonAppearStateClass::Start(CommonDataClass* CommonData)
{
	Appearing.SetLength(2);
	Appearing.Start[0] = 0;
	Appearing.Start[1] = 0;
	Appearing.Finish[0] = -0.05;
	Appearing.Finish[1] = 0.05;
	Appearing.SetMax(10);
}

void StartButtonAppearStateClass::Run(CommonDataClass* CommonData)
{
	Appearing.Step();
	if(Appearing.Finished())
	{
		CommonData->StateMachine->Switch(LEGEND_APPEAR_STATE);
	};
}

void StartButtonAppearStateClass::Draw(CommonDataClass* CommonData)
{
	Operations::DrawLargeCenteredLogo(CommonData);
	glBindTexture(0, CommonData->Textures[START_BUTTON_IMG]);
	glBegin(GL_QUADS);
	glTexCoord2t16(inttot16(0), inttot16(0));
	glVertex3f(Appearing.Value[0], 0.0, -0.075);
	glTexCoord2t16(inttot16(0), inttot16(64));
	glVertex3f(Appearing.Value[0], 0.0, -0.125);
	glTexCoord2t16(inttot16(128), inttot16(64));
	glVertex3f(Appearing.Value[1], 0.0, -0.125);
	glTexCoord2t16(inttot16(128), inttot16(0));
	glVertex3f(Appearing.Value[1], 0.0, -0.075);
	glEnd();
}
