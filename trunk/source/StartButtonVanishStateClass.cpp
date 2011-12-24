#include "StartButtonVanishStateClass.h"
#include "CommonDataClass.h"
#include "StateMachineClass.h"
#include "MenuAppearStateClass.h"
#include "OperationsClass.h"

StartButtonVanishStateClass::StartButtonVanishStateClass()
: StateClass()
{
}

void StartButtonVanishStateClass::Start(CommonDataClass* CommonData)
{
	Vanishing.SetLength(2);
	Vanishing.Start[0] = -0.05;
	Vanishing.Start[1] = 0.05;
	Vanishing.Finish[0] = 0;
	Vanishing.Finish[1] = 0;
	Vanishing.SetMax(10);
}

void StartButtonVanishStateClass::Run(CommonDataClass* CommonData)
{
	Vanishing.Step();
	if(Vanishing.Finished())
	{
		CommonData->StateMachine->Switch(MENU_APPEAR_STATE);
	};
}

void StartButtonVanishStateClass::Draw(CommonDataClass* CommonData)
{
	Operations::DrawLargeCenteredLogo(CommonData);
	glBindTexture(0, CommonData->Textures[START_BUTTON_IMG]);
	glBegin(GL_QUADS);
	glTexCoord2t16(inttot16(0), inttot16(0));
	glVertex3f(Vanishing.Value[0], 0.0, -0.075);
	glTexCoord2t16(inttot16(0), inttot16(64));
	glVertex3f(Vanishing.Value[0], 0.0, -0.125);
	glTexCoord2t16(inttot16(128), inttot16(64));
	glVertex3f(Vanishing.Value[1], 0.0, -0.125);
	glTexCoord2t16(inttot16(128), inttot16(0));
	glVertex3f(Vanishing.Value[1], 0.0, -0.075);
	glEnd();
}
