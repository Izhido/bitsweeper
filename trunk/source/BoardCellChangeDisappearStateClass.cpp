#include "BoardCellChangeDisappearStateClass.h"
#include "CommonDataClass.h"
#include "StateMachineClass.h"
#include "BoardCellClass.h"
#include "BoardWaitStateClass.h"
#include "BoardCellChangeAppearStateClass.h"
#include "OperationsClass.h"

BoardCellChangeDisappearStateClass::BoardCellChangeDisappearStateClass()
: StateClass()
{
}

void BoardCellChangeDisappearStateClass::Start(CommonDataClass* CommonData)
{
	Count = 0;
}

void BoardCellChangeDisappearStateClass::Run(CommonDataClass* CommonData)
{
	Count++;
	if(Count >= 5)
	{
		if(CommonData->Board[CommonData->CellBeingChanged].State == CellUnknown)
		{
			CommonData->Board[CommonData->CellBeingChanged].State = CommonData->CellBeingChangedNewState;
			if(!(CommonData->TimeStarted))
			{
				CommonData->TimeStarted = true;
				CommonData->InitialTickCount = CommonData->TickCount; 
			};
			CommonData->StateMachine->Switch(BOARD_WAIT_STATE);
		} else
		{
			CommonData->StateMachine->Switch(BOARD_CELL_CHANGE_APPEAR_STATE);
		};
	};
}

void BoardCellChangeDisappearStateClass::Draw(CommonDataClass* CommonData)
{
	int i;
	int j;
	int k;
	int x;
	int z;
	int c;
	int t;
	int Top;
	int Bottom;
	float TimeHeight;

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
	glColor3f(210.0 / 255.0, 180.0 / 255.0, 140.0 / 255.0);
	k = Top * CommonData->BoardWidth + CommonData->LeftCell;
	z = Top * 3;
	for(j = Top; j < Bottom; j++)
	{
		x = CommonData->LeftCell * 3;
		glBegin(GL_QUADS);
		for(i = CommonData->LeftCell; i < CommonData->RightCell; i++)
		{
			if(Operations::IsEmptyCell(CommonData, k))
			{
				glVertex3v16(CommonData->BoardCellXCoordinates[x + 1], 0, CommonData->BoardCellZCoordinates[z + 1]);
				glVertex3v16(CommonData->BoardCellXCoordinates[x + 1], 0, CommonData->BoardCellZCoordinates[z + 2]);
				glVertex3v16(CommonData->BoardCellXCoordinates[x + 2], 0, CommonData->BoardCellZCoordinates[z + 2]);
				glVertex3v16(CommonData->BoardCellXCoordinates[x + 2], 0, CommonData->BoardCellZCoordinates[z + 1]);
			};
			if(k == CommonData->CellBeingChanged)
			{
				glVertex3v16(CommonData->BoardCellXCoordinates[x + 1], 0, CommonData->BoardCellZCoordinates[z + 1]);
				glVertex3v16(CommonData->BoardCellXCoordinates[x + 1], 0, CommonData->BoardCellZCoordinates[z + 1] + (Count * (CommonData->BoardCellZCoordinates[z + 2] - CommonData->BoardCellZCoordinates[z + 1]) / 10));
				glVertex3v16(CommonData->BoardCellXCoordinates[x + 2], 0, CommonData->BoardCellZCoordinates[z + 1] + (Count * (CommonData->BoardCellZCoordinates[z + 2] - CommonData->BoardCellZCoordinates[z + 1]) / 10));
				glVertex3v16(CommonData->BoardCellXCoordinates[x + 2], 0, CommonData->BoardCellZCoordinates[z + 1]);

			};
			k++;
			x = x + 3;
		};
		glEnd();
		k = k + CommonData->BoardWidth - CommonData->RightCell + CommonData->LeftCell;
		z = z + 3;
	};
	glColor3f(1, 1, 1);
	k = Top * CommonData->BoardWidth + CommonData->LeftCell;
	z = Top * 3;
	for(j = Top; j < Bottom; j++)
	{
		x = CommonData->LeftCell * 3;
		for(i = CommonData->LeftCell; i < CommonData->RightCell; i++)
		{
			t = -1;
			if(CommonData->Board[k].State == CellUncovered)
			{
				if(CommonData->Board[k].Explodes)
				{
					t = BOMB_IMG;
				} else 
				{
					c = CommonData->Board[k].ExplodingCellsAround;
					if(c > 0)
					{
						t = ONE_IMG + c - 1; 
					};
				};
			} else if(CommonData->Board[k].State == CellFlagged)
			{
				t = FLAG_IMG;
			} else if(CommonData->Board[k].State == CellUnknown)
			{
				t = QUESTION_IMG;
			};
			if(t >= 0)
			{
				glBindTexture(0, CommonData->Textures[t]);
				glBegin(GL_QUADS);
				if(k == CommonData->CellBeingChanged)
				{
					glTexCoord2t16(inttot16(0), inttot16(0));
					glVertex3v16(CommonData->BoardCellXCoordinates[x + 1], 0, CommonData->BoardCellZCoordinates[z + 1] + (Count * (CommonData->BoardCellZCoordinates[z + 2] - CommonData->BoardCellZCoordinates[z + 1]) / 10));
					glTexCoord2t16(inttot16(0), inttot16(16));
					glVertex3v16(CommonData->BoardCellXCoordinates[x + 1], 0, CommonData->BoardCellZCoordinates[z + 2]);
					glTexCoord2t16(inttot16(16), inttot16(16));
					glVertex3v16(CommonData->BoardCellXCoordinates[x + 2], 0, CommonData->BoardCellZCoordinates[z + 2]);
					glTexCoord2t16(inttot16(16), inttot16(0));
					glVertex3v16(CommonData->BoardCellXCoordinates[x + 2], 0, CommonData->BoardCellZCoordinates[z + 1] + (Count * (CommonData->BoardCellZCoordinates[z + 2] - CommonData->BoardCellZCoordinates[z + 1]) / 10));
				} else
				{
					glTexCoord2t16(inttot16(0), inttot16(0));
					glVertex3v16(CommonData->BoardCellXCoordinates[x + 1], 0, CommonData->BoardCellZCoordinates[z + 1]);
					glTexCoord2t16(inttot16(0), inttot16(16));
					glVertex3v16(CommonData->BoardCellXCoordinates[x + 1], 0, CommonData->BoardCellZCoordinates[z + 2]);
					glTexCoord2t16(inttot16(16), inttot16(16));
					glVertex3v16(CommonData->BoardCellXCoordinates[x + 2], 0, CommonData->BoardCellZCoordinates[z + 2]);
					glTexCoord2t16(inttot16(16), inttot16(0));
					glVertex3v16(CommonData->BoardCellXCoordinates[x + 2], 0, CommonData->BoardCellZCoordinates[z + 1]);
				};
				glEnd();
			};
			k++;
			x = x + 3;
		};
		k = k + CommonData->BoardWidth - CommonData->RightCell + CommonData->LeftCell;
		z = z + 3;
	};
	Operations::DrawCellBorders(CommonData, Top, Bottom);
	if(CommonData->TimeStarted)
	{
		TimeHeight = 0;
	} else
	{
		TimeHeight = ((5.0 - Count) * 0.03) / 5.0;
	};
	Operations::DrawSmallUpperRightClock(CommonData, TimeHeight);
}
