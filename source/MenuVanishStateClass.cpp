#include "MenuVanishStateClass.h"
#include "CommonDataClass.h"
#include "StateMachineClass.h"
#include "StartButtonAppearStateClass.h"
#include "OperationsClass.h"

MenuVanishStateClass::MenuVanishStateClass()
: StateClass()
{
}

void MenuVanishStateClass::Start(CommonDataClass* CommonData)
{
	Vanishing.SetLength(2);
	Vanishing.Start[0] = -0.05;
	Vanishing.Start[1] = 0.05;
	Vanishing.Finish[0] = 0;
	Vanishing.Finish[1] = 0;
	Vanishing.SetMax(10);
}

void MenuVanishStateClass::Run(CommonDataClass* CommonData)
{
	Vanishing.Step();
	if(Vanishing.Finished())
	{
		CommonData->StateMachine->Switch(START_BUTTON_APPEAR_STATE);
	};
}

void MenuVanishStateClass::Draw(CommonDataClass* CommonData)
{
	Operations::DrawLargeCenteredLogo(CommonData);
	glBindTexture(0, CommonData->Textures[MENU_IMG]);
	glBegin(GL_QUADS);
	glTexCoord2t16(inttot16(0), inttot16(0));
	glVertex3f(Vanishing.Value[0], 0.0, -0.05);
	glTexCoord2t16(inttot16(0), inttot16(128));
	glVertex3f(Vanishing.Value[0], 0.0, -0.15);
	glTexCoord2t16(inttot16(128), inttot16(128));
	glVertex3f(Vanishing.Value[1], 0.0, -0.15);
	glTexCoord2t16(inttot16(128), inttot16(0));
	glVertex3f(Vanishing.Value[1], 0.0, -0.05);
	glEnd();
}
