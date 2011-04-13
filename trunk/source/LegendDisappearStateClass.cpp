#include "LegendDisappearStateClass.h"
#include "CommonDataClass.h"
#include "StateMachineClass.h"
#include "StartButtonVanishStateClass.h"
#include "OperationsClass.h"

LegendDisappearStateClass::LegendDisappearStateClass()
: StateClass()
{
}

bool LegendDisappearStateClass::Start(CommonDataClass* CommonData)
{
	Count = 0;
	return true;
}

bool LegendDisappearStateClass::Run(CommonDataClass* CommonData)
{
	Count++;
	if(Count >= 4)
	{
		CommonData->StateMachine->Switch(START_BUTTON_VANISH_STATE);
	};
	return true;
}

void LegendDisappearStateClass::Draw(CommonDataClass* CommonData)
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
