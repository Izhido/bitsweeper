#include "GameLostDisappearStateClass.h"
#include "CommonDataClass.h"
#include <nds/arm9/input.h>
#include "StateMachineClass.h"
#include "GameLostNotVisibleWaitStateClass.h"
#include "BoardCellClass.h"
#include "OperationsClass.h"

GameLostDisappearStateClass::GameLostDisappearStateClass()
: StateClass()
{
}

void GameLostDisappearStateClass::Start(CommonDataClass* CommonData)
{
	Count = 0;
}

void GameLostDisappearStateClass::Run(CommonDataClass* CommonData)
{
	Count++;
	if(Count >= 30)
	{
		CommonData->StateMachine->Switch(GAME_LOST_NOT_VISIBLE_WAIT_STATE);
	};
	Operations::DoBoardScrolling(CommonData);
	Operations::UpdateBoardCellBorders(CommonData);
}

void GameLostDisappearStateClass::Draw(CommonDataClass* CommonData)
{
	int Top;
	int Bottom;

	Operations::DrawSmallUpperLeftLogo(CommonData);
	glBindTexture(0, CommonData->Textures[YOU_LOSE_IMG]);
	glBegin(GL_QUADS);
	glTexCoord2t16(inttot16(0), inttot16(0));
	glVertex3f(-0.05 + ((Count * 0.2) / 30.0) + CommonData->LocationX, 0.001, -0.075 + CommonData->LocationZ);
	glTexCoord2t16(inttot16(0), inttot16(64));
	glVertex3f(-0.05 + ((Count * 0.2) / 30.0) + CommonData->LocationX, 0.001, -0.125 + CommonData->LocationZ);
	glTexCoord2t16(inttot16(128), inttot16(64));
	glVertex3f(0.05 + ((Count * 0.2) / 30.0) + CommonData->LocationX, 0.001, -0.125 + CommonData->LocationZ);
	glTexCoord2t16(inttot16(128), inttot16(0));
	glVertex3f(0.05 + ((Count * 0.2) / 30.0) + CommonData->LocationX, 0.001, -0.075 + CommonData->LocationZ);
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
