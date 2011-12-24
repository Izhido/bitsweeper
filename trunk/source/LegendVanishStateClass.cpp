#include "LegendVanishStateClass.h"
#include "CommonDataClass.h"
#include "StateMachineClass.h"
#include "LogoAndStartButtonVanishStateClass.h"
#include "OperationsClass.h"

LegendVanishStateClass::LegendVanishStateClass()
: StateClass()
{
}

void LegendVanishStateClass::Start(CommonDataClass* CommonData)
{
	Count = 0;
}

void LegendVanishStateClass::Run(CommonDataClass* CommonData)
{
	Count++;
	if(Count >= 4)
	{
		CommonData->StateMachine->Switch(LOGO_AND_START_BUTTON_VANISH_STATE);
	};
}

void LegendVanishStateClass::Draw(CommonDataClass* CommonData)
{
	Operations::DrawLargeCenteredLogo(CommonData);
	glBindTexture(0, CommonData->Textures[START_BUTTON_IMG]);
	glBegin(GL_QUADS);
	glTexCoord2t16(inttot16(0), inttot16(0));
	glVertex3f(-0.05, 0.0, -0.075);
	glTexCoord2t16(inttot16(0), inttot16(64));
	glVertex3f(-0.05, 0.0, -0.125);
	glTexCoord2t16(inttot16(128), inttot16(64));
	glVertex3f(0.05, 0.0, -0.125);
	glTexCoord2t16(inttot16(128), inttot16(0));
	glVertex3f(0.05, 0.0, -0.075);
	glEnd();
	glBindTexture(0, CommonData->Textures[LEGEND_IMG]);
	glBegin(GL_QUADS);
	glTexCoord2t16(inttot16(0), inttot16(0));
	glVertex3f(0.1 - CommonData->LegendX, 0.0, 0.038 - (Count * 0.013 / 4.0));
	glTexCoord2t16(inttot16(0), inttot16(16));
	glVertex3f(0.1 - CommonData->LegendX, 0.0, 0.025 - (Count * 0.013 / 4.0));
	glTexCoord2t16(inttot16(512), inttot16(16));
	glVertex3f(0.5 - CommonData->LegendX, 0.0, 0.025 - (Count * 0.013 / 4.0));
	glTexCoord2t16(inttot16(512), inttot16(0));
	glVertex3f(0.5 - CommonData->LegendX, 0.0, 0.038 - (Count * 0.013 / 4.0));
	glTexCoord2t16(inttot16(0), inttot16(0));
	glVertex3f(0.5 - CommonData->LegendX, 0.0, 0.038 - (Count * 0.013 / 4.0));
	glTexCoord2t16(inttot16(0), inttot16(16));
	glVertex3f(0.5 - CommonData->LegendX, 0.0, 0.025 - (Count * 0.013 / 4.0));
	glTexCoord2t16(inttot16(512), inttot16(16));
	glVertex3f(0.9 - CommonData->LegendX, 0.0, 0.025 - (Count * 0.013 / 4.0));
	glTexCoord2t16(inttot16(512), inttot16(0));
	glVertex3f(0.9 - CommonData->LegendX, 0.0, 0.038 - (Count * 0.013 / 4.0));
	glEnd();
}
