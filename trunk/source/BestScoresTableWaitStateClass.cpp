#include "BestScoresTableWaitStateClass.h"
#include "CommonDataClass.h"
#include <nds/arm9/input.h>
#include "StateMachineClass.h"
#include "BestScoresTableDisappearStateClass.h"
#include "BoardCellClass.h"
#include "BestScoresTableClass.h"
#include "OperationsClass.h"

BestScoresTableWaitStateClass::BestScoresTableWaitStateClass()
: StateClass()
{
}

bool BestScoresTableWaitStateClass::Start(CommonDataClass* CommonData)
{
	return true;
}

bool BestScoresTableWaitStateClass::Run(CommonDataClass* CommonData)
{
	if((CommonData->TouchX >= 64) && (CommonData->TouchX < 192) && (CommonData->TouchY >= 64) && (CommonData->TouchY < 128))
	{
		CommonData->StateMachine->Switch(BEST_SCORES_TABLE_DISAPPEAR_STATE);
	};
	if(((CommonData->IsLeftHanded)&&(((CommonData->KeysHeld & KEY_LEFT) != 0)||((CommonData->KeysHeld & KEY_RIGHT) != 0)))||((!(CommonData->IsLeftHanded))&&(((CommonData->KeysHeld & KEY_A) != 0)||((CommonData->KeysHeld & KEY_Y) != 0))))
	{
		CommonData->StateMachine->Switch(BEST_SCORES_TABLE_DISAPPEAR_STATE);
	};
	if(((CommonData->IsLeftHanded)&&(((CommonData->KeysHeld & KEY_UP) != 0)||((CommonData->KeysHeld & KEY_DOWN) != 0)))||((!(CommonData->IsLeftHanded))&&(((CommonData->KeysHeld & KEY_B) != 0)||((CommonData->KeysHeld & KEY_X) != 0))))
	{
		CommonData->StateMachine->Switch(BEST_SCORES_TABLE_DISAPPEAR_STATE);
	};
	if((((CommonData->IsLeftHanded)&&((CommonData->KeysHeld & KEY_Y) != 0))||((!(CommonData->IsLeftHanded))&&((CommonData->KeysHeld & KEY_LEFT) != 0)))&&(CommonData->HorizontalScrollCount > -10))
	{
		CommonData->HorizontalScrollCount = CommonData->HorizontalScrollCount - 2;
	};
	if((((CommonData->IsLeftHanded)&&((CommonData->KeysHeld & KEY_A) != 0))||((!(CommonData->IsLeftHanded))&&((CommonData->KeysHeld & KEY_RIGHT) != 0)))&&(CommonData->HorizontalScrollCount < 10))
	{
		CommonData->HorizontalScrollCount = CommonData->HorizontalScrollCount + 2;
	};
	if(CommonData->HorizontalScrollCount > 0)
	{
		CommonData->HorizontalScrollCount--;
	} else if(CommonData->HorizontalScrollCount < 0)
	{
		CommonData->HorizontalScrollCount++;
	};
	if((((CommonData->IsLeftHanded)&&((CommonData->KeysHeld & KEY_B) != 0))||((!(CommonData->IsLeftHanded))&&((CommonData->KeysHeld & KEY_DOWN) != 0)))&&(CommonData->VerticalScrollCount > -10))
	{
		CommonData->VerticalScrollCount = CommonData->VerticalScrollCount - 2;
	};
	if((((CommonData->IsLeftHanded)&&((CommonData->KeysHeld & KEY_X) != 0))||((!(CommonData->IsLeftHanded))&&((CommonData->KeysHeld & KEY_UP) != 0)))&&(CommonData->VerticalScrollCount < 10))
	{
		CommonData->VerticalScrollCount = CommonData->VerticalScrollCount + 2;
	};
	if(CommonData->VerticalScrollCount > 0)
	{
		CommonData->VerticalScrollCount--;
	} else if(CommonData->VerticalScrollCount < 0)
	{
		CommonData->VerticalScrollCount++;
	};
	Operations::UpdateBoardLocation(CommonData);
	Operations::UpdateBoardCellBorders(CommonData);
	return true;
}

void BestScoresTableWaitStateClass::Draw(CommonDataClass* CommonData)
{
	int ElapsedSeconds;
	int ElapsedMinutes;
	int Second1;
	int Second10;
	int Minute1;
	int Minute10;
	int Minute100;
	int i;
	int Top;
	int Bottom;

	Operations::DrawSmallUpperLeftLogo(CommonData);
	glBindTexture(0, 0);
	glColor3f(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex3f(-0.073 + CommonData->LocationX, 0.0, -0.172 + CommonData->LocationZ);
	glVertex3f(0.072 + CommonData->LocationX, 0.0, -0.172 + CommonData->LocationZ);
	glVertex3f(0.072 + CommonData->LocationX, 0.0, -0.028 + CommonData->LocationZ);
	glVertex3f(-0.073 + CommonData->LocationX, 0.0, -0.028 + CommonData->LocationZ);
	glEnd();
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex3f(-0.072 + CommonData->LocationX, 0.0003, -0.171 + CommonData->LocationZ);
	glVertex3f(0.071 + CommonData->LocationX, 0.0003, -0.171 + CommonData->LocationZ);
	glVertex3f(0.071 + CommonData->LocationX, 0.0003, -0.029 + CommonData->LocationZ);
	glVertex3f(-0.072 + CommonData->LocationX, 0.0003, -0.029 + CommonData->LocationZ);
	glEnd();
	glColor3f(0.51, 0.51, 0.51);
	glBegin(GL_QUADS);
	glVertex3f(-0.07 + CommonData->LocationX, 0.0006, -0.17 + CommonData->LocationZ);
	glVertex3f(0.07 + CommonData->LocationX, 0.0006, -0.17 + CommonData->LocationZ);
	glVertex3f(0.07 + CommonData->LocationX, 0.0006, -0.03 + CommonData->LocationZ);
	glVertex3f(-0.07 + CommonData->LocationX, 0.0006, -0.03 + CommonData->LocationZ);
	glEnd();
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glBindTexture(0, CommonData->Textures[BEST_SCORES_PLUS_EXPERT_PLUS_INSANE_IMG]);
	glTexCoord2t16(inttot16(0), inttot16(0));
	glVertex3f(-0.031 + CommonData->LocationX, 0.001, -0.033 + CommonData->LocationZ);
	glTexCoord2t16(inttot16(0), inttot16(16));
	glVertex3f(-0.031 + CommonData->LocationX, 0.001, -0.045 + CommonData->LocationZ);
	glTexCoord2t16(inttot16(84), inttot16(16));
	glVertex3f(0.031 + CommonData->LocationX, 0.001, -0.045 + CommonData->LocationZ);
	glTexCoord2t16(inttot16(84), inttot16(0));
	glVertex3f(0.031 + CommonData->LocationX, 0.001, -0.033 + CommonData->LocationZ);
	glEnd();
	for(i = 0; i < 10; i++)
	{
		if(CommonData->BestScoresTable->Lines[i].Level != LevelNone)
		{
			if(CommonData->BestScoresTable->Lines[i].Level == LevelBeginner)
			{
				glBindTexture(0, CommonData->Textures[BEGINNER_PLUS_INTERMEDIATE_IMG]);
				glBegin(GL_QUADS);
				glTexCoord2t16(inttot16(0), inttot16(0));
				glVertex3f(-0.067 + CommonData->LocationX, 0.001, -0.046 - (i * 0.0124) + CommonData->LocationZ);
				glTexCoord2t16(inttot16(0), inttot16(16));
				glVertex3f(-0.067 + CommonData->LocationX, 0.001, -0.0584 - (i * 0.0124) + CommonData->LocationZ);
				glTexCoord2t16(inttot16(54), inttot16(16));
				glVertex3f(-0.0249 + CommonData->LocationX, 0.001, -0.0584 - (i * 0.0124) + CommonData->LocationZ);
				glTexCoord2t16(inttot16(54), inttot16(0));
				glVertex3f(-0.0249 + CommonData->LocationX, 0.001, -0.046 - (i * 0.0124) + CommonData->LocationZ);
				glEnd();
			} else if(CommonData->BestScoresTable->Lines[i].Level == LevelIntermediate)
			{
				glBindTexture(0, CommonData->Textures[BEGINNER_PLUS_INTERMEDIATE_IMG]);
				glBegin(GL_QUADS);
				glTexCoord2t16(inttot16(54), inttot16(0));
				glVertex3f(-0.065 + CommonData->LocationX, 0.001, -0.046 - (i * 0.0124) + CommonData->LocationZ);
				glTexCoord2t16(inttot16(54), inttot16(16));
				glVertex3f(-0.065 + CommonData->LocationX, 0.001, -0.0584 - (i * 0.0124) + CommonData->LocationZ);
				glTexCoord2t16(inttot16(128), inttot16(16));
				glVertex3f(-0.0054 + CommonData->LocationX, 0.001, -0.0584 - (i * 0.0124) + CommonData->LocationZ);
				glTexCoord2t16(inttot16(128), inttot16(0));
				glVertex3f(-0.0054 + CommonData->LocationX, 0.001, -0.046 - (i * 0.0124) + CommonData->LocationZ);
				glEnd();
			} else if(CommonData->BestScoresTable->Lines[i].Level == LevelExpert)
			{
				glBindTexture(0, CommonData->Textures[BEST_SCORES_PLUS_EXPERT_PLUS_INSANE_IMG]);
				glBegin(GL_QUADS);
				glTexCoord2t16(inttot16(84), inttot16(0));
				glVertex3f(-0.067 + CommonData->LocationX, 0.001, -0.049 - (i * 0.0124) + CommonData->LocationZ);
				glTexCoord2t16(inttot16(84), inttot16(9));
				glVertex3f(-0.067 + CommonData->LocationX, 0.001, -0.055 - (i * 0.0124) + CommonData->LocationZ);
				glTexCoord2t16(inttot16(128), inttot16(9));
				glVertex3f(-0.0305 + CommonData->LocationX, 0.001, -0.055 - (i * 0.0124) + CommonData->LocationZ);
				glTexCoord2t16(inttot16(128), inttot16(0));
				glVertex3f(-0.0305 + CommonData->LocationX, 0.001, -0.049 - (i * 0.0124) + CommonData->LocationZ);
				glEnd();
			} else if(CommonData->BestScoresTable->Lines[i].Level == LevelInsane)
			{
				glBindTexture(0, CommonData->Textures[BEST_SCORES_PLUS_EXPERT_PLUS_INSANE_IMG]);
				glBegin(GL_QUADS);
				glTexCoord2t16(inttot16(84), inttot16(8));
				glVertex3f(-0.065 + CommonData->LocationX, 0.001, -0.049 - (i * 0.0124) + CommonData->LocationZ);
				glTexCoord2t16(inttot16(84), inttot16(17));
				glVertex3f(-0.065 + CommonData->LocationX, 0.001, -0.055 - (i * 0.0124) + CommonData->LocationZ);
				glTexCoord2t16(inttot16(128), inttot16(17));
				glVertex3f(-0.029 + CommonData->LocationX, 0.001, -0.055 - (i * 0.0124) + CommonData->LocationZ);
				glTexCoord2t16(inttot16(128), inttot16(8));
				glVertex3f(-0.029 + CommonData->LocationX, 0.001, -0.049 - (i * 0.0124) + CommonData->LocationZ);
				glEnd();
			};
			ElapsedSeconds = CommonData->BestScoresTable->Lines[i].Seconds;
			Second1 = ElapsedSeconds % 10;
			Second10 = ElapsedSeconds / 10;
			ElapsedMinutes = CommonData->BestScoresTable->Lines[i].Minutes;
			Minute1 = ElapsedMinutes % 10;
			ElapsedMinutes = ElapsedMinutes / 10;
			Minute10 = ElapsedMinutes % 10;
			Minute100 = ElapsedMinutes / 10;
			glBindTexture(0, CommonData->Textures[TIME_0_IMG + Second1]);
			glBegin(GL_QUADS);
			glTexCoord2t16(inttot16(0), inttot16(0));
			glVertex3f(0.062 + CommonData->LocationX, 0.001, -0.05 - (i * 0.0124) + CommonData->LocationZ);
			glTexCoord2t16(inttot16(0), inttot16(9));
			glVertex3f(0.062 + CommonData->LocationX, 0.001, -0.056 - (i * 0.0124) + CommonData->LocationZ);
			glTexCoord2t16(inttot16(8), inttot16(9));
			glVertex3f(0.068 + CommonData->LocationX, 0.001, -0.056 - (i * 0.0124) + CommonData->LocationZ);
			glTexCoord2t16(inttot16(8), inttot16(0));
			glVertex3f(0.068 + CommonData->LocationX, 0.001, -0.05 - (i * 0.0124) + CommonData->LocationZ);
			glEnd();
			glBindTexture(0, CommonData->Textures[TIME_0_IMG + Second10]);
			glBegin(GL_QUADS);
			glTexCoord2t16(inttot16(0), inttot16(0));
			glVertex3f(0.056 + CommonData->LocationX, 0.001, -0.05 - (i * 0.0124) + CommonData->LocationZ);
			glTexCoord2t16(inttot16(0), inttot16(9));
			glVertex3f(0.056 + CommonData->LocationX, 0.001, -0.056 - (i * 0.0124) + CommonData->LocationZ);
			glTexCoord2t16(inttot16(8), inttot16(9));
			glVertex3f(0.062 + CommonData->LocationX, 0.001, -0.056 - (i * 0.0124) + CommonData->LocationZ);
			glTexCoord2t16(inttot16(8), inttot16(0));
			glVertex3f(0.062 + CommonData->LocationX, 0.001, -0.05 - (i * 0.0124) + CommonData->LocationZ);
			glEnd();
			glBindTexture(0, CommonData->Textures[TIME_COLON_IMG]);
			glBegin(GL_QUADS);
			glTexCoord2t16(inttot16(0), inttot16(0));
			glVertex3f(0.05 + CommonData->LocationX, 0.001, -0.05 - (i * 0.0124) + CommonData->LocationZ);
			glTexCoord2t16(inttot16(0), inttot16(9));
			glVertex3f(0.05 + CommonData->LocationX, 0.001, -0.056 - (i * 0.0124) + CommonData->LocationZ);
			glTexCoord2t16(inttot16(8), inttot16(9));
			glVertex3f(0.056 + CommonData->LocationX, 0.001, -0.056 - (i * 0.0124) + CommonData->LocationZ);
			glTexCoord2t16(inttot16(8), inttot16(0));
			glVertex3f(0.056 + CommonData->LocationX, 0.001, -0.05 - (i * 0.0124) + CommonData->LocationZ);
			glEnd();
			glBindTexture(0, CommonData->Textures[TIME_0_IMG + Minute1]);
			glBegin(GL_QUADS);
			glTexCoord2t16(inttot16(0), inttot16(0));
			glVertex3f(0.044 + CommonData->LocationX, 0.001, -0.05 - (i * 0.0124) + CommonData->LocationZ);
			glTexCoord2t16(inttot16(0), inttot16(9));
			glVertex3f(0.044 + CommonData->LocationX, 0.001, -0.056 - (i * 0.0124) + CommonData->LocationZ);
			glTexCoord2t16(inttot16(8), inttot16(9));
			glVertex3f(0.05 + CommonData->LocationX, 0.001, -0.056 - (i * 0.0124) + CommonData->LocationZ);
			glTexCoord2t16(inttot16(8), inttot16(0));
			glVertex3f(0.05 + CommonData->LocationX, 0.001, -0.05 - (i * 0.0124) + CommonData->LocationZ);
			glEnd();
			glBindTexture(0, CommonData->Textures[TIME_0_IMG + Minute10]);
			glBegin(GL_QUADS);
			glTexCoord2t16(inttot16(0), inttot16(0));
			glVertex3f(0.038 + CommonData->LocationX, 0.001, -0.05 - (i * 0.0124) + CommonData->LocationZ);
			glTexCoord2t16(inttot16(0), inttot16(9));
			glVertex3f(0.038 + CommonData->LocationX, 0.001, -0.056 - (i * 0.0124) + CommonData->LocationZ);
			glTexCoord2t16(inttot16(8), inttot16(9));
			glVertex3f(0.044 + CommonData->LocationX, 0.001, -0.056 - (i * 0.0124) + CommonData->LocationZ);
			glTexCoord2t16(inttot16(8), inttot16(0));
			glVertex3f(0.044 + CommonData->LocationX, 0.001, -0.05 - (i * 0.0124) + CommonData->LocationZ);
			glEnd();
			glBindTexture(0, CommonData->Textures[TIME_0_IMG + Minute100]);
			glBegin(GL_QUADS);
			glTexCoord2t16(inttot16(0), inttot16(0));
			glVertex3f(0.032 + CommonData->LocationX, 0.001, -0.05 - (i * 0.0124) + CommonData->LocationZ);
			glTexCoord2t16(inttot16(0), inttot16(9));
			glVertex3f(0.032 + CommonData->LocationX, 0.001, -0.056 - (i * 0.0124) + CommonData->LocationZ);
			glTexCoord2t16(inttot16(8), inttot16(9));
			glVertex3f(0.038 + CommonData->LocationX, 0.001, -0.056 - (i * 0.0124) + CommonData->LocationZ);
			glTexCoord2t16(inttot16(8), inttot16(0));
			glVertex3f(0.038 + CommonData->LocationX, 0.001, -0.05 - (i * 0.0124) + CommonData->LocationZ);
			glEnd();
		};
	};
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
