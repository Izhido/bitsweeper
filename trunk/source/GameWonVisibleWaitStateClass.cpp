#include "GameWonVisibleWaitStateClass.h"
#include "CommonDataClass.h"
#include <nds/arm9/input.h>
#include "StateMachineClass.h"
#include "GameWonDisappearStateClass.h"
#include "GameWonVanishStateClass.h"
#include "BoardCellClass.h"
#include "OperationsClass.h"

GameWonVisibleWaitStateClass::GameWonVisibleWaitStateClass()
: StateClass()
{
}

void GameWonVisibleWaitStateClass::Start(CommonDataClass* CommonData)
{
	Count = 0;
}

void GameWonVisibleWaitStateClass::Run(CommonDataClass* CommonData)
{
	Count++;
	if(Count >= 60)
	{
		CommonData->StateMachine->Switch(GAME_WON_DISAPPEAR_STATE);
	};
	if((CommonData->TouchX >= 64) && (CommonData->TouchX < 192) && (CommonData->TouchY >= 64) && (CommonData->TouchY < 128))
	{
		CommonData->StateMachine->Switch(GAME_WON_VANISH_STATE);
	};
	if(((CommonData->IsLeftHanded)&&(((CommonData->KeysHeld & KEY_LEFT) != 0)||((CommonData->KeysHeld & KEY_RIGHT) != 0)))||((!(CommonData->IsLeftHanded))&&(((CommonData->KeysHeld & KEY_A) != 0)||((CommonData->KeysHeld & KEY_Y) != 0))))
	{
		CommonData->StateMachine->Switch(GAME_WON_VANISH_STATE);
	};
	if(((CommonData->IsLeftHanded)&&(((CommonData->KeysHeld & KEY_UP) != 0)||((CommonData->KeysHeld & KEY_DOWN) != 0)))||((!(CommonData->IsLeftHanded))&&(((CommonData->KeysHeld & KEY_B) != 0)||((CommonData->KeysHeld & KEY_X) != 0))))
	{
		CommonData->StateMachine->Switch(GAME_WON_VANISH_STATE);
	};
	Operations::DoBoardScrolling(CommonData);
	Operations::UpdateBoardCellBorders(CommonData);
}

void GameWonVisibleWaitStateClass::Draw(CommonDataClass* CommonData)
{
	int Top;
	int Bottom;

	Operations::DrawSmallUpperLeftLogo(CommonData);
	glBindTexture(0, CommonData->Textures[YOU_WIN_IMG]);
	glBegin(GL_QUADS);
	glTexCoord2t16(inttot16(0), inttot16(0));
	glVertex3f(-0.05 + CommonData->LocationX, 0.001, -0.075 + CommonData->LocationZ);
	glTexCoord2t16(inttot16(0), inttot16(64));
	glVertex3f(-0.05 + CommonData->LocationX, 0.001, -0.125 + CommonData->LocationZ);
	glTexCoord2t16(inttot16(128), inttot16(64));
	glVertex3f(0.05 + CommonData->LocationX, 0.001, -0.125 + CommonData->LocationZ);
	glTexCoord2t16(inttot16(128), inttot16(0));
	glVertex3f(0.05 + CommonData->LocationX, 0.001, -0.075 + CommonData->LocationZ);
	glEnd();
	if(CommonData->ToBottomScreen)
	{
		Top = CommonData->LowerTopCell;
		Bottom = CommonData->LowerBottomCell;
	} else
	{
		Top = CommonData->UpperTopCell;
		Bottom = CommonData->UpperBottomCell;
	};
	glBindTexture(0, 0);
	Operations::DrawEmptyCells(CommonData, Top, Bottom);
	Operations::DrawNonEmptyCells(CommonData, Top, Bottom);
	Operations::DrawCellBorders(CommonData, Top, Bottom);
	Operations::DrawSmallUpperRightClock(CommonData);
}
