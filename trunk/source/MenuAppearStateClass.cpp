#include "MenuAppearStateClass.h"
#include "CommonDataClass.h"
#include "StateMachineClass.h"
#include "MenuWaitStateClass.h"
#include "OperationsClass.h"

MenuAppearStateClass::MenuAppearStateClass()
: StateClass()
{
}

void MenuAppearStateClass::Start(CommonDataClass* CommonData)
{
	Appearing.SetLength(2);
	Appearing.Start[0] = 0;
	Appearing.Start[1] = 0;
	Appearing.Finish[0] = -0.05;
	Appearing.Finish[1] = 0.05;
	Appearing.SetMax(10);
}

void MenuAppearStateClass::Run(CommonDataClass* CommonData)
{
	Appearing.Step();
	if(Appearing.Finished())
	{
		CommonData->StateMachine->Switch(MENU_WAIT_STATE);
	};
}

void MenuAppearStateClass::Draw(CommonDataClass* CommonData)
{
	Operations::DrawLargeCenteredLogo(CommonData);
	glBindTexture(0, CommonData->Textures[MENU_IMG]);
	glBegin(GL_QUADS);
	glTexCoord2t16(inttot16(0), inttot16(0));
	glVertex3f(Appearing.Value[0], 0.0, -0.05);
	glTexCoord2t16(inttot16(0), inttot16(128));
	glVertex3f(Appearing.Value[0], 0.0, -0.15);
	glTexCoord2t16(inttot16(128), inttot16(128));
	glVertex3f(Appearing.Value[1], 0.0, -0.15);
	glTexCoord2t16(inttot16(128), inttot16(0));
	glVertex3f(Appearing.Value[1], 0.0, -0.05);
	glEnd();
}
