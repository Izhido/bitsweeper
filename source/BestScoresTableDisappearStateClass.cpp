#include "BestScoresTableDisappearStateClass.h"
#include "CommonDataClass.h"
#include "StateMachineClass.h"
#include "BoardDisappearStateClass.h"
#include "BoardCellClass.h"
#include "OperationsClass.h"

BestScoresTableDisappearStateClass::BestScoresTableDisappearStateClass()
: StateClass()
{
}

void BestScoresTableDisappearStateClass::Start(CommonDataClass* CommonData)
{
	Count = 0;
}

void BestScoresTableDisappearStateClass::Run(CommonDataClass* CommonData)
{
	Count++;
	if(Count >= 10)
	{
		CommonData->StateMachine->Switch(BOARD_DISAPPEAR_STATE);
	};
	Operations::UpdateBoardLocation(CommonData);
	Operations::UpdateBoardCellBorders(CommonData);
}

void BestScoresTableDisappearStateClass::Draw(CommonDataClass* CommonData)
{
	int Top;
	int Bottom;

	Operations::DrawSmallUpperLeftLogo(CommonData);
	glBindTexture(0, 0);
	glColor3f(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex3f(-0.073 + CommonData->LocationX, 0.0, -0.172 + CommonData->LocationZ - ((Count * 0.15) / 10.0));
	glVertex3f(0.072 + CommonData->LocationX, 0.0, -0.172 + CommonData->LocationZ - ((Count * 0.15) / 10.0));
	glVertex3f(0.072 + CommonData->LocationX, 0.0, -0.028 + CommonData->LocationZ - ((Count * 0.15) / 10.0));
	glVertex3f(-0.073 + CommonData->LocationX, 0.0, -0.028 + CommonData->LocationZ - ((Count * 0.15) / 10.0));
	glEnd();
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex3f(-0.072 + CommonData->LocationX, 0.0003, -0.171 + CommonData->LocationZ - ((Count * 0.15) / 10.0));
	glVertex3f(0.071 + CommonData->LocationX, 0.0003, -0.171 + CommonData->LocationZ - ((Count * 0.15) / 10.0));
	glVertex3f(0.071 + CommonData->LocationX, 0.0003, -0.029 + CommonData->LocationZ - ((Count * 0.15) / 10.0));
	glVertex3f(-0.072 + CommonData->LocationX, 0.0003, -0.029 + CommonData->LocationZ - ((Count * 0.15) / 10.0));
	glEnd();
	glColor3f(0.51, 0.51, 0.51);
	glBegin(GL_QUADS);
	glVertex3f(-0.07 + CommonData->LocationX, 0.0006, -0.17 + CommonData->LocationZ - ((Count * 0.15) / 10.0));
	glVertex3f(0.07 + CommonData->LocationX, 0.0006, -0.17 + CommonData->LocationZ - ((Count * 0.15) / 10.0));
	glVertex3f(0.07 + CommonData->LocationX, 0.0006, -0.03 + CommonData->LocationZ - ((Count * 0.15) / 10.0));
	glVertex3f(-0.07 + CommonData->LocationX, 0.0006, -0.03 + CommonData->LocationZ - ((Count * 0.15) / 10.0));
	glEnd();
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glBindTexture(0, CommonData->Textures[BEST_SCORES_PLUS_EXPERT_PLUS_INSANE_IMG]);
	glTexCoord2t16(inttot16(0), inttot16(0));
	glVertex3f(-0.031 + CommonData->LocationX, 0.001, -0.033 + CommonData->LocationZ - ((Count * 0.15) / 10.0));
	glTexCoord2t16(inttot16(0), inttot16(16));
	glVertex3f(-0.031 + CommonData->LocationX, 0.001, -0.045 + CommonData->LocationZ - ((Count * 0.15) / 10.0));
	glTexCoord2t16(inttot16(84), inttot16(16));
	glVertex3f(0.031 + CommonData->LocationX, 0.001, -0.045 + CommonData->LocationZ - ((Count * 0.15) / 10.0));
	glTexCoord2t16(inttot16(84), inttot16(0));
	glVertex3f(0.031 + CommonData->LocationX, 0.001, -0.033 + CommonData->LocationZ - ((Count * 0.15) / 10.0));
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
