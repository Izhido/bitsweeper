#include "MenuDisappearStateClass.h"
#include "CommonDataClass.h"
#include "StateMachineClass.h"
#include "BoardAppearStateClass.h"
#include "OperationsClass.h"

MenuDisappearStateClass::MenuDisappearStateClass()
: StateClass()
{
}

void MenuDisappearStateClass::Start(CommonDataClass* CommonData)
{
	Disappearing.SetLength(4);
	Disappearing.Start[0] = -0.05;
	Disappearing.Start[1] = 0.05;
	Disappearing.Start[2] = -0.15;
	Disappearing.Start[3] = -0.05;
	Disappearing.Finish[0] = 0;
	Disappearing.Finish[1] = 0;
	Disappearing.Finish[2] = -0.25;
	Disappearing.Finish[3] = -0.15;
	Disappearing.SetMax(10);
}

void MenuDisappearStateClass::Run(CommonDataClass* CommonData)
{
	Disappearing.Step();
	if(Disappearing.Finished())
	{
		CommonData->StateMachine->Switch(BOARD_APPEAR_STATE);
	};
}

void MenuDisappearStateClass::Draw(CommonDataClass* CommonData)
{
	Operations::DrawLargeCenteredLogo(CommonData);
	glBindTexture(0, CommonData->Textures[MENU_IMG]);
	glBegin(GL_QUADS);
	glTexCoord2t16(inttot16(0), inttot16(0));
	glVertex3f(Disappearing.Value[0], 0.0, Disappearing.Value[3]);
	glTexCoord2t16(inttot16(0), inttot16(128));
	glVertex3f(Disappearing.Value[0], 0.0, Disappearing.Value[2]);
	glTexCoord2t16(inttot16(128), inttot16(128));
	glVertex3f(Disappearing.Value[1], 0.0, Disappearing.Value[2]);
	glTexCoord2t16(inttot16(128), inttot16(0));
	glVertex3f(Disappearing.Value[1], 0.0, Disappearing.Value[3]);
	glEnd();
}
