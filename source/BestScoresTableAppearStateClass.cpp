#include "BestScoresTableAppearStateClass.h"
#include "CommonDataClass.h"
#include "BestScoresTableClass.h"
#include "StateMachineClass.h"
#include "BestScoresTableWaitStateClass.h"
#include "BoardCellClass.h"
#include "OperationsClass.h"
#include <cstdio>
#include "PolySaveManagerClass.h"

BestScoresTableAppearStateClass::BestScoresTableAppearStateClass()
: StateClass()
{
}

bool BestScoresTableAppearStateClass::Start(CommonDataClass* CommonData)
{
	BestScoresTableClass* BestScoresTable;
	bool ReadSuccesful;
	FILE* fBestScores;
	int BufferSize;
	int JustRead;
	int ToRead;
	char* Buffer;
	PolySaveManagerClass PolySaveManager;
	PolySaveManagerErrorsEnum err;
	int i;
	int j;

	BestScoresTable = new BestScoresTableClass;
	ReadSuccesful = false;
	BufferSize = BestScoresTable->BufferSize();
	Buffer = new char[BufferSize];
	if(CommonData->FilesystemEnabled)
	{
		fBestScores = fopen("BITSWP.sco", "rb");
		if(fBestScores != 0)
		{
			JustRead = 0;
			ToRead = BufferSize;
			while(ToRead > 0)
			{
				JustRead = ((int)(fread(Buffer, 1, ToRead, fBestScores)));
				if(JustRead <= 0)
				{
					break;
				} else
				{
					ToRead = ToRead - JustRead;
				};
			};
			ReadSuccesful = (ToRead == 0);
			fclose(fBestScores);
		};
	} else
	{
		err = PolySaveManager.Read(((unsigned char*)("BITSWP")), Buffer, BufferSize);
		if(err == PolySaveErrorNone)
		{
			ReadSuccesful = true;
		};
	};
	if(ReadSuccesful)
	{
		BestScoresTable->LoadFrom(Buffer);
		delete CommonData->BestScoresTable;
		CommonData->BestScoresTable = BestScoresTable;
	} else
	{
		BestScoresTable = CommonData->BestScoresTable;
	};
	delete[] Buffer;
	if(CommonData->LastGameWon)
	{
		i = 0;
		while(i < 10)
		{
			if(BestScoresTable->Lines[i].Level == LevelNone)
			{
				break;
			} else if(BestScoresTable->Lines[i].Level < (CommonData->Level + 1))
			{
				break;
			} else if((BestScoresTable->Lines[i].Level == (CommonData->Level + 1))&&(BestScoresTable->Lines[i].Minutes > (CommonData->Minute100 * 100 + CommonData->Minute10 * 10 + CommonData->Minute1)))
			{
				break;
			} else if((BestScoresTable->Lines[i].Level == (CommonData->Level + 1))&&(BestScoresTable->Lines[i].Minutes == (CommonData->Minute100 * 100 + CommonData->Minute10 * 10 + CommonData->Minute1))&&(BestScoresTable->Lines[i].Seconds > (CommonData->Second10 * 10 + CommonData->Second1)))
			{
				break;
			} else
			{
				i++;
			};
		};
		if(i < 10)
		{
			for(j = 9; j > i; j--)
			{
				BestScoresTable->Lines[j].Level = BestScoresTable->Lines[j - 1].Level;
				BestScoresTable->Lines[j].Minutes = BestScoresTable->Lines[j - 1].Minutes;
				BestScoresTable->Lines[j].Seconds = BestScoresTable->Lines[j - 1].Seconds;
			};
			if(CommonData->Level == 0)
			{
				BestScoresTable->Lines[i].Level = LevelBeginner;
			} else if(CommonData->Level == 1)
			{
				BestScoresTable->Lines[i].Level = LevelIntermediate;
			} else if(CommonData->Level == 2)
			{
				BestScoresTable->Lines[i].Level = LevelExpert;
			} else if(CommonData->Level == 3)
			{
				BestScoresTable->Lines[i].Level = LevelInsane;
			};
			BestScoresTable->Lines[i].Minutes = (CommonData->Minute100 * 100 + CommonData->Minute10 * 10 + CommonData->Minute1);
			BestScoresTable->Lines[i].Seconds = (CommonData->Second10 * 10 + CommonData->Second1);
		};
		BufferSize = BestScoresTable->BufferSize();
		Buffer = new char[BufferSize];
		BestScoresTable->SaveTo(Buffer);
		if(CommonData->FilesystemEnabled)
		{
			fBestScores = fopen("BITSWP.sco", "wb");
			if(fBestScores != 0)
			{
				fwrite(Buffer, 1, BufferSize, fBestScores);
				fclose(fBestScores);
			};
		} else
		{
			PolySaveManager.Write(((unsigned char*)("BITSWP")), Buffer, BufferSize);
		};
		delete[] Buffer;
	};
	Count = 0;
	return true;
}

bool BestScoresTableAppearStateClass::Run(CommonDataClass* CommonData)
{
	Count++;
	if(Count >= 10)
	{
		CommonData->TimeStarted = true;
		CommonData->StateMachine->Switch(BEST_SCORES_TABLE_WAIT_STATE);
	};
	Operations::UpdateBoardLocation(CommonData);
	Operations::UpdateBoardCellBorders(CommonData);
	return true;
}

void BestScoresTableAppearStateClass::Draw(CommonDataClass* CommonData)
{
	int Top;
	int Bottom;
	float TimeHeight;

	Operations::DrawSmallUpperLeftLogo(CommonData);
	glBindTexture(0, 0);
	glColor3f(0, 0, 0);
	glBegin(GL_QUADS);
	glVertex3f(-0.073 + CommonData->LocationX, 0.0, -0.172 + CommonData->LocationZ - (((10.0 - Count) * 0.15) / 10.0));
	glVertex3f(0.072 + CommonData->LocationX, 0.0, -0.172 + CommonData->LocationZ - (((10.0 - Count) * 0.15) / 10.0));
	glVertex3f(0.072 + CommonData->LocationX, 0.0, -0.028 + CommonData->LocationZ - (((10.0 - Count) * 0.15) / 10.0));
	glVertex3f(-0.073 + CommonData->LocationX, 0.0, -0.028 + CommonData->LocationZ - (((10.0 - Count) * 0.15) / 10.0));
	glEnd();
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glVertex3f(-0.072 + CommonData->LocationX, 0.0003, -0.171 + CommonData->LocationZ - (((10.0 - Count) * 0.15) / 10.0));
	glVertex3f(0.071 + CommonData->LocationX, 0.0003, -0.171 + CommonData->LocationZ - (((10.0 - Count) * 0.15) / 10.0));
	glVertex3f(0.071 + CommonData->LocationX, 0.0003, -0.029 + CommonData->LocationZ - (((10.0 - Count) * 0.15) / 10.0));
	glVertex3f(-0.072 + CommonData->LocationX, 0.0003, -0.029 + CommonData->LocationZ - (((10.0 - Count) * 0.15) / 10.0));
	glEnd();
	glColor3f(0.51, 0.51, 0.51);
	glBegin(GL_QUADS);
	glVertex3f(-0.07 + CommonData->LocationX, 0.0006, -0.17 + CommonData->LocationZ - (((10.0 - Count) * 0.15) / 10.0));
	glVertex3f(0.07 + CommonData->LocationX, 0.0006, -0.17 + CommonData->LocationZ - (((10.0 - Count) * 0.15) / 10.0));
	glVertex3f(0.07 + CommonData->LocationX, 0.0006, -0.03 + CommonData->LocationZ - (((10.0 - Count) * 0.15) / 10.0));
	glVertex3f(-0.07 + CommonData->LocationX, 0.0006, -0.03 + CommonData->LocationZ - (((10.0 - Count) * 0.15) / 10.0));
	glEnd();
	glColor3f(1, 1, 1);
	glBegin(GL_QUADS);
	glBindTexture(0, CommonData->Textures[BEST_SCORES_PLUS_EXPERT_PLUS_INSANE_IMG]);
	glTexCoord2t16(inttot16(0), inttot16(0));
	glVertex3f(-0.031 + CommonData->LocationX, 0.001, -0.033 + CommonData->LocationZ - (((10.0 - Count) * 0.15) / 10.0));
	glTexCoord2t16(inttot16(0), inttot16(16));
	glVertex3f(-0.031 + CommonData->LocationX, 0.001, -0.045 + CommonData->LocationZ - (((10.0 - Count) * 0.15) / 10.0));
	glTexCoord2t16(inttot16(84), inttot16(16));
	glVertex3f(0.031 + CommonData->LocationX, 0.001, -0.045 + CommonData->LocationZ - (((10.0 - Count) * 0.15) / 10.0));
	glTexCoord2t16(inttot16(84), inttot16(0));
	glVertex3f(0.031 + CommonData->LocationX, 0.001, -0.033 + CommonData->LocationZ - (((10.0 - Count) * 0.15) / 10.0));
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
	if(CommonData->TimeStarted)
	{
		TimeHeight = 0;
	} else
	{
		TimeHeight = ((10.0 - Count) * 0.03) / 10.0;
	};
	Operations::DrawSmallUpperRightClock(CommonData, TimeHeight);
}
