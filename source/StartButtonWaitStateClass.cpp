#include "StartButtonWaitStateClass.h"
#include "CommonDataClass.h"
#include <nds/arm9/input.h>
#include "StateMachineClass.h"
#include "LegendDisappearStateClass.h"
#include "LegendVanishStateClass.h"
#include "OperationsClass.h"

StartButtonWaitStateClass::StartButtonWaitStateClass()
: StateClass()
{
}

void StartButtonWaitStateClass::Start(CommonDataClass* CommonData)
{
}

void StartButtonWaitStateClass::Run(CommonDataClass* CommonData)
{
	if(((CommonData->KeysHeld & KEY_A) != 0)||((CommonData->KeysHeld & KEY_Y) != 0))
	{
		CommonData->IsLeftHanded = false;
		CommonData->StateMachine->Switch(LEGEND_DISAPPEAR_STATE);
	} else if(((CommonData->KeysHeld & KEY_LEFT) != 0)||((CommonData->KeysHeld & KEY_RIGHT) != 0))
	{
		CommonData->IsLeftHanded = true;
		CommonData->StateMachine->Switch(LEGEND_DISAPPEAR_STATE);
	} else if((CommonData->KeysHeld & KEY_START) != 0)
	{
		CommonData->StateMachine->Switch(LEGEND_DISAPPEAR_STATE);
	} else if(((CommonData->KeysHeld & KEY_B) != 0)||((CommonData->KeysHeld & KEY_X) != 0)||((CommonData->KeysHeld & KEY_UP) != 0)||((CommonData->KeysHeld & KEY_DOWN) != 0))
	{
		CommonData->StateMachine->Switch(LEGEND_VANISH_STATE);
	} else if((CommonData->TouchX >= 64) && (CommonData->TouchX < 192) && (CommonData->TouchY >= 64) && (CommonData->TouchY < 128))
	{
		CommonData->StateMachine->Switch(LEGEND_DISAPPEAR_STATE);
	};
	CommonData->LegendX = CommonData->LegendX + 0.001;
	if(CommonData->LegendX >= 0.8)
	{
		CommonData->LegendX = CommonData->LegendX - 0.4;
	};
}

void StartButtonWaitStateClass::Draw(CommonDataClass* CommonData)
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
	glVertex3f(0.1 - CommonData->LegendX, 0.0, 0.038);
	glTexCoord2t16(inttot16(0), inttot16(16));
	glVertex3f(0.1 - CommonData->LegendX, 0.0, 0.025);
	glTexCoord2t16(inttot16(512), inttot16(16));
	glVertex3f(0.5 - CommonData->LegendX, 0.0, 0.025);
	glTexCoord2t16(inttot16(512), inttot16(0));
	glVertex3f(0.5 - CommonData->LegendX, 0.0, 0.038);
	glTexCoord2t16(inttot16(0), inttot16(0));
	glVertex3f(0.5 - CommonData->LegendX, 0.0, 0.038);
	glTexCoord2t16(inttot16(0), inttot16(16));
	glVertex3f(0.5 - CommonData->LegendX, 0.0, 0.025);
	glTexCoord2t16(inttot16(512), inttot16(16));
	glVertex3f(0.9 - CommonData->LegendX, 0.0, 0.025);
	glTexCoord2t16(inttot16(512), inttot16(0));
	glVertex3f(0.9 - CommonData->LegendX, 0.0, 0.038);
	glEnd();
}
