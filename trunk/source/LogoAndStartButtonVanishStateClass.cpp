#include "LogoAndStartButtonVanishStateClass.h"
#include "CommonDataClass.h"
#include "OperationsClass.h"
#include "StateMachineClass.h"
#include "BackgroundFadeOutStateClass.h"

LogoAndStartButtonVanishStateClass::LogoAndStartButtonVanishStateClass()
: StateClass()
{
}

void LogoAndStartButtonVanishStateClass::Start(CommonDataClass* CommonData)
{
	Vanishing.SetLength(1);
	Vanishing.Start[0] = 0;
	Vanishing.Finish[0] = 0.1;
	Vanishing.SetMax(10);
}

void LogoAndStartButtonVanishStateClass::Run(CommonDataClass* CommonData)
{
	Vanishing.Step();
	if(Vanishing.Finished())
	{
		CommonData->StateMachine->Switch(BACKGROUND_FADE_OUT_STATE);
	};
}

void LogoAndStartButtonVanishStateClass::Draw(CommonDataClass* CommonData)
{
	glBindTexture(0, CommonData->Textures[LOGO_IMG]);
	glBegin(GL_QUADS);
	glTexCoord2t16(inttot16(32), inttot16(16));
	glVertex3f(-0.075, 0.0, 0.1375 + Vanishing.Value[0]);
	glTexCoord2t16(inttot16(32), inttot16(113));
	glVertex3f(-0.075, 0.0, 0.0625 + Vanishing.Value[0]);
	glTexCoord2t16(inttot16(225), inttot16(113));
	glVertex3f(0.075, 0.0, 0.0625 + Vanishing.Value[0]);
	glTexCoord2t16(inttot16(225), inttot16(16));
	glVertex3f(0.075, 0.0, 0.1375 + Vanishing.Value[0]);
	glEnd();
	glBindTexture(0, CommonData->Textures[START_BUTTON_IMG]);
	glBegin(GL_QUADS);
	glTexCoord2t16(inttot16(0), inttot16(0));
	glVertex3f(-0.05, 0.0, -0.075 - Vanishing.Value[0]);
	glTexCoord2t16(inttot16(0), inttot16(64));
	glVertex3f(-0.05, 0.0, -0.125 - Vanishing.Value[0]);
	glTexCoord2t16(inttot16(128), inttot16(64));
	glVertex3f(0.05, 0.0, -0.125 - Vanishing.Value[0]);
	glTexCoord2t16(inttot16(128), inttot16(0));
	glVertex3f(0.05, 0.0, -0.075 - Vanishing.Value[0]);
	glEnd();
}
