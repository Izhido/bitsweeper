#include "GameLostNotVisibleWaitStateClass.h"
#include "CommonDataClass.h"
#include <nds/arm9/input.h>
#include "StateMachineClass.h"
#include "GameLostAppearStateClass.h"
#include "BestScoresTableAppearStateClass.h"
#include "BoardCellClass.h"
#include "OperationsClass.h"

GameLostNotVisibleWaitStateClass::GameLostNotVisibleWaitStateClass()
: StateClass()
{
}

void GameLostNotVisibleWaitStateClass::Start(CommonDataClass* CommonData)
{
	Count = 0;
}

void GameLostNotVisibleWaitStateClass::Run(CommonDataClass* CommonData)
{
	Count++;
	if(Count >= 90)
	{
		CommonData->StateMachine->Switch(GAME_LOST_APPEAR_STATE);
	};
	if(((CommonData->IsLeftHanded)&&(((CommonData->KeysHeld & KEY_UP) != 0)||((CommonData->KeysHeld & KEY_DOWN) != 0)))||((!(CommonData->IsLeftHanded))&&(((CommonData->KeysHeld & KEY_B) != 0)||((CommonData->KeysHeld & KEY_X) != 0))))
	{
		CommonData->StateMachine->Switch(BEST_SCORES_TABLE_APPEAR_STATE);
	};
	Operations::DoBoardScrolling(CommonData);
	Operations::UpdateBoardCellBorders(CommonData);
}

void GameLostNotVisibleWaitStateClass::Draw(CommonDataClass* CommonData)
{
	int Top;
	int Bottom;

	Operations::DrawSmallUpperLeftLogo(CommonData);
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
