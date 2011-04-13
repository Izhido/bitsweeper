#include "GameWonAppearStateClass.h"
#include "CommonDataClass.h"
#include <nds/arm9/input.h>
#include "StateMachineClass.h"
#include "GameWonVisibleWaitStateClass.h"
#include "BoardCellClass.h"
#include "OperationsClass.h"

GameWonAppearStateClass::GameWonAppearStateClass()
: StateClass()
{
}

bool GameWonAppearStateClass::Start(CommonDataClass* CommonData)
{
	Count = 0;
	return true;
}

bool GameWonAppearStateClass::Run(CommonDataClass* CommonData)
{
	Count++;
	if(Count >= 15)
	{
		CommonData->StateMachine->Switch(GAME_WON_VISIBLE_WAIT_STATE);
	};
	Operations::DoBoardScrolling(CommonData);
	Operations::UpdateBoardCellBorders(CommonData);
	return true;
}

void GameWonAppearStateClass::Draw(CommonDataClass* CommonData)
{
	int Top;
	int Bottom;

	Operations::DrawSmallUpperLeftLogo(CommonData);
	glBindTexture(0, CommonData->Textures[YOU_WIN_IMG]);
	glBegin(GL_QUADS);
	glTexCoord2t16(inttot16(0), inttot16(0));
	glVertex3f(-0.05 - (((15.0 - Count) * 0.2) / 15.0) + CommonData->LocationX, 0.001, -0.075 + CommonData->LocationZ);
	glTexCoord2t16(inttot16(0), inttot16(64));
	glVertex3f(-0.05 - (((15.0 - Count) * 0.2) / 15.0) + CommonData->LocationX, 0.001, -0.125 + CommonData->LocationZ);
	glTexCoord2t16(inttot16(128), inttot16(64));
	glVertex3f(0.05 - (((15.0 - Count) * 0.2) / 15.0) + CommonData->LocationX, 0.001, -0.125 + CommonData->LocationZ);
	glTexCoord2t16(inttot16(128), inttot16(0));
	glVertex3f(0.05 - (((15.0 - Count) * 0.2) / 15.0) + CommonData->LocationX, 0.001, -0.075 + CommonData->LocationZ);
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
