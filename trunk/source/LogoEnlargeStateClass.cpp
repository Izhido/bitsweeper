#include "LogoEnlargeStateClass.h"
#include "CommonDataClass.h"
#include "OperationsClass.h"
#include "StateMachineClass.h"
#include "MenuAppearStateClass.h"

LogoEnlargeStateClass::LogoEnlargeStateClass()
: StateClass()
{
}

bool LogoEnlargeStateClass::Start(CommonDataClass* CommonData)
{
	Enlarging.SetLength(4);
	Enlarging.Start[0] = 0;
	Enlarging.Start[1] = 0;
	Enlarging.Start[2] = 0;
	Enlarging.Start[3] = 0;
	Enlarging.Finish[0] = 0.015;
	Enlarging.Finish[1] = 0.13;
	Enlarging.Finish[2] = 0.0225;
	Enlarging.Finish[3] = 0.08;
	Enlarging.SetMax(10);
	return true;
}

bool LogoEnlargeStateClass::Run(CommonDataClass* CommonData)
{
	Enlarging.Step();
	if(Enlarging.Finished())
	{
		CommonData->StateMachine->Switch(MENU_APPEAR_STATE);
	};
	return true;
}

void LogoEnlargeStateClass::Draw(CommonDataClass* CommonData)
{
	glBindTexture(0, CommonData->Textures[LOGO_IMG]);
	glBegin(GL_QUADS);
	glTexCoord2t16(inttot16(32), inttot16(16));
	glVertex3f(-0.09 + Enlarging.Value[0], 0.0, 0.16 - Enlarging.Value[2]);
	glTexCoord2t16(inttot16(32), inttot16(113));
	glVertex3f(-0.09 + Enlarging.Value[0], 0.0, 0.1425 - Enlarging.Value[3]);
	glTexCoord2t16(inttot16(225), inttot16(113));
	glVertex3f(-0.055 + Enlarging.Value[1], 0.0, 0.1425 - Enlarging.Value[3]);
	glTexCoord2t16(inttot16(225), inttot16(16));
	glVertex3f(-0.055 + Enlarging.Value[1], 0.0, 0.16 - Enlarging.Value[2]);
	glEnd();
}
