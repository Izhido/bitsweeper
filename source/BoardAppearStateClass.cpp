#include "BoardAppearStateClass.h"
#include "CommonDataClass.h"
#include <nds/timers.h>
#include <nds/system.h>
#include "StateMachineClass.h"
#include "BoardCellClass.h"
#include "RandomNumberGeneratorClass.h"
#include "LogoShrinkStateClass.h"
#include "OperationsClass.h"
#include <ctime>

BoardAppearStateClass::BoardAppearStateClass()
: StateClass()
{
}

void BoardAppearStateClass::Start(CommonDataClass* CommonData)
{
	int Exploding;
	int i;
	int j;
	int k;
	float p;

	delete CommonData->RandomNumberGenerator;
	CommonData->RandomNumberGenerator = new RandomNumberGeneratorClass(time(0));
	if(CommonData->Level == 0)
	{
		CommonData->BoardWidth = 9;
		CommonData->BoardHeight = 9;
		Exploding = 11;
	} else if(CommonData->Level == 1)
	{
		CommonData->BoardWidth = 16;
		CommonData->BoardHeight = 16;
		Exploding = 45;
	} else if(CommonData->Level == 2)
	{
		CommonData->BoardWidth = 30;
		CommonData->BoardHeight = 16;
		Exploding = 112;
	} else 
	{
		CommonData->BoardWidth = 50;
		CommonData->BoardHeight = 50;
		Exploding = 1000;
	};
	CommonData->BoardLength = CommonData->BoardWidth * CommonData->BoardHeight;
	CommonData->Board = new BoardCellClass[CommonData->BoardLength];
	k = 0;
	for(j = 0; j < CommonData->BoardHeight; j++)
	{
		for(i = 0; i < CommonData->BoardWidth; i++)
		{
			CommonData->Board[k].X = i;
			CommonData->Board[k].Z = j;
			k++;
		};
	};
	CommonData->CellsBeingUncoveredList = new int[CommonData->BoardLength];
	CommonData->CellsBeingUncoveredSize = 0;
	while(Exploding > 0)
	{
		do
		{
			i = ((int)(CommonData->RandomNumberGenerator->Next() * (CommonData->BoardLength - 1)));
		} while(CommonData->Board[i].Explodes);
		CommonData->Board[i].Explodes = true;
		j = i - CommonData->BoardWidth - 1;
		if((j >= 0)&&(j < CommonData->BoardLength)&&(CommonData->Board[i].X > 0)&&(CommonData->Board[i].Z > 0))
		{
			CommonData->Board[j].ExplodingCellsAround = CommonData->Board[j].ExplodingCellsAround + 1;
		};
		j++;
		if((j >= 0)&&(j < CommonData->BoardLength)&&(CommonData->Board[i].Z > 0))
		{
			CommonData->Board[j].ExplodingCellsAround = CommonData->Board[j].ExplodingCellsAround + 1;
		};
		j++;
		if((j >= 0)&&(j < CommonData->BoardLength)&&(CommonData->Board[i].X < (CommonData->BoardWidth - 1))&&(CommonData->Board[i].Z > 0))
		{
			CommonData->Board[j].ExplodingCellsAround = CommonData->Board[j].ExplodingCellsAround + 1;
		};
		j = j + CommonData->BoardWidth;
		if((j >= 0)&&(j < CommonData->BoardLength)&&(CommonData->Board[i].X < (CommonData->BoardWidth - 1)))
		{
			CommonData->Board[j].ExplodingCellsAround = CommonData->Board[j].ExplodingCellsAround + 1;
		};
		j = j - 2;
		if((j >= 0)&&(j < CommonData->BoardLength)&&(CommonData->Board[i].X > 0))
		{
			CommonData->Board[j].ExplodingCellsAround = CommonData->Board[j].ExplodingCellsAround + 1;
		};
		j = j + CommonData->BoardWidth;
		if((j >= 0)&&(j < CommonData->BoardLength)&&(CommonData->Board[i].X > 0)&&(CommonData->Board[i].Z < (CommonData->BoardHeight - 1)))
		{
			CommonData->Board[j].ExplodingCellsAround = CommonData->Board[j].ExplodingCellsAround + 1;
		};
		j++; 
		if((j >= 0)&&(j < CommonData->BoardLength)&&(CommonData->Board[i].Z < (CommonData->BoardHeight - 1)))
		{
			CommonData->Board[j].ExplodingCellsAround = CommonData->Board[j].ExplodingCellsAround + 1;
		};
		j++;
		if((j >= 0)&&(j < CommonData->BoardLength)&&(CommonData->Board[i].X < (CommonData->BoardWidth - 1))&&(CommonData->Board[i].Z < (CommonData->BoardHeight - 1)))
		{
			CommonData->Board[j].ExplodingCellsAround = CommonData->Board[j].ExplodingCellsAround + 1;
		};
		Exploding--;
	};
	CommonData->BoardCellXCoordinates = new v16[1 + CommonData->BoardWidth * 3];
	CommonData->BoardCellZCoordinates = new v16[1 + CommonData->BoardHeight * 3];
	p = -(CommonData->BoardWidth * 0.015 / 2.0);
	j = 0;
	for(i = 0; i < CommonData->BoardWidth; i++)
	{
		CommonData->BoardCellXCoordinates[j] = floattov16(p);
		j++;
		CommonData->BoardCellXCoordinates[j] = floattov16(p + 0.001);
		j++;
		CommonData->BoardCellXCoordinates[j] = floattov16(p + 0.014);
		j++;
		p = p + 0.015;
	};
	CommonData->BoardCellXCoordinates[j] = floattov16(p);
	p = (CommonData->BoardHeight * 0.015 / 2.0) - 0.1;
	j = 0;
	for(i = 0; i < CommonData->BoardHeight; i++)
	{
		CommonData->BoardCellZCoordinates[j] = floattov16(p);
		j++;
		CommonData->BoardCellZCoordinates[j] = floattov16(p - 0.001);
		j++;
		CommonData->BoardCellZCoordinates[j] = floattov16(p - 0.014);
		j++;
		p = p - 0.015;
	};
	CommonData->BoardCellZCoordinates[j] = floattov16(p);
	Operations::UpdateBoardCellBorders(CommonData);
	CommonData->TimeStarted = false;
	CommonData->Second1 = 0;
	CommonData->Second10 = 0;
	CommonData->Minute1 = 0;
	CommonData->Minute10 = 0;
	CommonData->Minute100 = 0;
	CommonData->LimitTimeReached = false;
	Appearing.SetLength(15);
	for(i = 0; i < 15; i += 3)
	{
		Appearing.Start[i] = 34.0 / 255.0;
		Appearing.Start[i + 1] = 139.0 / 255.0;
		Appearing.Start[i + 2] = 34.0 / 255.0;
	};
	Appearing.Finish[0] = 210.0 / 255.0;
	Appearing.Finish[1] = 180.0 / 255.0;
	Appearing.Finish[2] = 140.0 / 255.0;
	Appearing.Finish[3] = 255.0 / 255.0;
	Appearing.Finish[4] = 225.0 / 255.0;
	Appearing.Finish[5] = 175.0 / 255.0;
	Appearing.Finish[6] = 240.0 / 255.0;
	Appearing.Finish[7] = 205.0 / 255.0;
	Appearing.Finish[8] = 160.0 / 255.0;
	Appearing.Finish[9] = 168.0 / 255.0;
	Appearing.Finish[10] = 144.0 / 255.0;
	Appearing.Finish[11] = 112.0 / 255.0;
	Appearing.Finish[12] = 184.0 / 255.0;
	Appearing.Finish[13] = 156.0 / 255.0;
	Appearing.Finish[14] = 122.0 / 255.0;
	Appearing.SetMax(10);
}

void BoardAppearStateClass::Run(CommonDataClass* CommonData)
{
	Appearing.Step();
	if(Appearing.Finished())
	{
		CommonData->StateMachine->Switch(LOGO_SHRINK_STATE);
	};
}

void BoardAppearStateClass::Draw(CommonDataClass* CommonData)
{
	int i;
	int j;
	int x;
	int z;
	int Top;
	int Bottom;

	Operations::DrawLargeCenteredLogo(CommonData);
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
	glColor3f(Appearing.Value[0], Appearing.Value[1], Appearing.Value[2]);
	z = Top * 3;
	for(j = Top; j < Bottom; j++)
	{
		x = CommonData->LeftCell * 3;
		glBegin(GL_QUADS);
		for(i = CommonData->LeftCell; i < CommonData->RightCell; i++)
		{
			glVertex3v16(CommonData->BoardCellXCoordinates[x + 1], 0, CommonData->BoardCellZCoordinates[z + 1]);
			glVertex3v16(CommonData->BoardCellXCoordinates[x + 1], 0, CommonData->BoardCellZCoordinates[z + 2]);
			glVertex3v16(CommonData->BoardCellXCoordinates[x + 2], 0, CommonData->BoardCellZCoordinates[z + 2]);
			glVertex3v16(CommonData->BoardCellXCoordinates[x + 2], 0, CommonData->BoardCellZCoordinates[z + 1]);
			x = x + 3;
		};
		glEnd();
		z = z + 3;
	};
	glColor3f(Appearing.Value[3], Appearing.Value[4], Appearing.Value[5]);
	z = Top * 3;
	for(j = Top; j < Bottom; j++)
	{
		x = CommonData->LeftCell * 3;
		glBegin(GL_QUADS);
		for(i = CommonData->LeftCell; i < CommonData->RightCell; i++)
		{
			glVertex3v16(CommonData->BoardCellXCoordinates[x], 0, CommonData->BoardCellZCoordinates[z]);
			glVertex3v16(CommonData->BoardCellXCoordinates[x + 1], 0, CommonData->BoardCellZCoordinates[z + 1]);
			glVertex3v16(CommonData->BoardCellXCoordinates[x + 2], 0, CommonData->BoardCellZCoordinates[z + 1]);
			glVertex3v16(CommonData->BoardCellXCoordinates[x + 3], 0, CommonData->BoardCellZCoordinates[z]);
			x = x + 3;
		};
		glEnd();
		z = z + 3;
	};
	glColor3f(Appearing.Value[6], Appearing.Value[7], Appearing.Value[8]);
	z = Top * 3;
	for(j = Top; j < Bottom; j++)
	{
		x = CommonData->LeftCell * 3;
		glBegin(GL_QUADS);
		for(i = CommonData->LeftCell; i < CommonData->RightCell; i++)
		{
			glVertex3v16(CommonData->BoardCellXCoordinates[x], 0, CommonData->BoardCellZCoordinates[z]);
			glVertex3v16(CommonData->BoardCellXCoordinates[x], 0, CommonData->BoardCellZCoordinates[z + 3]);
			glVertex3v16(CommonData->BoardCellXCoordinates[x + 1], 0, CommonData->BoardCellZCoordinates[z + 2]);
			glVertex3v16(CommonData->BoardCellXCoordinates[x + 1], 0, CommonData->BoardCellZCoordinates[z + 1]);
			x = x + 3;
		};
		glEnd();
		z = z + 3;
	};
	glColor3f(Appearing.Value[9], Appearing.Value[10], Appearing.Value[11]);
	z = Top * 3;
	for(j = Top; j < Bottom; j++)
	{
		x = CommonData->LeftCell * 3;
		glBegin(GL_QUADS);
		for(i = CommonData->LeftCell; i < CommonData->RightCell; i++)
		{
			glVertex3v16(CommonData->BoardCellXCoordinates[x + 1], 0, CommonData->BoardCellZCoordinates[z + 2]);
			glVertex3v16(CommonData->BoardCellXCoordinates[x], 0, CommonData->BoardCellZCoordinates[z + 3]);
			glVertex3v16(CommonData->BoardCellXCoordinates[x + 3], 0, CommonData->BoardCellZCoordinates[z + 3]);
			glVertex3v16(CommonData->BoardCellXCoordinates[x + 2], 0, CommonData->BoardCellZCoordinates[z + 2]);
			x = x + 3;
		};
		glEnd();
		z = z + 3;
	};
	glColor3f(Appearing.Value[12], Appearing.Value[13], Appearing.Value[14]);
	z = Top * 3;
	for(j = Top; j < Bottom; j++)
	{
		x = CommonData->LeftCell * 3;
		glBegin(GL_QUADS);
		for(i = CommonData->LeftCell; i < CommonData->RightCell; i++)
		{
			glVertex3v16(CommonData->BoardCellXCoordinates[x + 2], 0, CommonData->BoardCellZCoordinates[z + 1]);
			glVertex3v16(CommonData->BoardCellXCoordinates[x + 2], 0, CommonData->BoardCellZCoordinates[z + 2]);
			glVertex3v16(CommonData->BoardCellXCoordinates[x + 3], 0, CommonData->BoardCellZCoordinates[z + 3]);
			glVertex3v16(CommonData->BoardCellXCoordinates[x + 3], 0, CommonData->BoardCellZCoordinates[z]);
			x = x + 3;
		};
		glEnd();
		z = z + 3;
	};
}
