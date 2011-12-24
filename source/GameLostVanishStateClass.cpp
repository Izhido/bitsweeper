#include "GameLostVanishStateClass.h"
#include "CommonDataClass.h"
#include "StateMachineClass.h"
#include "BestScoresTableAppearStateClass.h"
#include "BoardCellClass.h"
#include "OperationsClass.h"

GameLostVanishStateClass::GameLostVanishStateClass()
: StateClass()
{
}

void GameLostVanishStateClass::Start(CommonDataClass* CommonData)
{
	Count = 0;
}

void GameLostVanishStateClass::Run(CommonDataClass* CommonData)
{
	Count++;
	if(Count >= 10)
	{
		CommonData->StateMachine->Switch(BEST_SCORES_TABLE_APPEAR_STATE);
	};
	Operations::UpdateBoardLocation(CommonData);
	Operations::UpdateBoardCellBorders(CommonData);
}

void GameLostVanishStateClass::Draw(CommonDataClass* CommonData)
{
	int Top;
	int Bottom;

	Operations::DrawSmallUpperLeftLogo(CommonData);
	glBindTexture(0, CommonData->Textures[YOU_LOSE_IMG]);
	glBegin(GL_QUADS);
	glTexCoord2t16(inttot16(0), inttot16(0));
	glVertex3f(-0.05 + CommonData->LocationX, 0.001, -0.075 - ((Count * 0.1) / 10.0) + CommonData->LocationZ);
	glTexCoord2t16(inttot16(0), inttot16(64));
	glVertex3f(-0.05 + CommonData->LocationX, 0.001, -0.125 - ((Count * 0.1) / 10.0) + CommonData->LocationZ);
	glTexCoord2t16(inttot16(128), inttot16(64));
	glVertex3f(0.05 + CommonData->LocationX, 0.001, -0.125 - ((Count * 0.1) / 10.0) + CommonData->LocationZ);
	glTexCoord2t16(inttot16(128), inttot16(0));
	glVertex3f(0.05 + CommonData->LocationX, 0.001, -0.075 - ((Count * 0.1) / 10.0) + CommonData->LocationZ);
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
