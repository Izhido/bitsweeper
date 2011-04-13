#include "LogoShrinkStateClass.h"
#include "CommonDataClass.h"
#include "OperationsClass.h"
#include "StateMachineClass.h"
#include "BoardWaitStateClass.h"

LogoShrinkStateClass::LogoShrinkStateClass()
: StateClass()
{
}

bool LogoShrinkStateClass::Start(CommonDataClass* CommonData)
{
	Shrinking.SetLength(4);
	Shrinking.Start[0] = 0;
	Shrinking.Start[1] = 0;
	Shrinking.Start[2] = 0;
	Shrinking.Start[3] = 0;
	Shrinking.Finish[0] = 0.015;
	Shrinking.Finish[1] = 0.13;
	Shrinking.Finish[2] = 0.0225;
	Shrinking.Finish[3] = 0.08;
	Shrinking.SetMax(10);
	return true;
}

bool LogoShrinkStateClass::Run(CommonDataClass* CommonData)
{
	Shrinking.Step();
	if(Shrinking.Finished())
	{
		CommonData->StateMachine->Switch(BOARD_WAIT_STATE);
	};
	return true;
}

void LogoShrinkStateClass::Draw(CommonDataClass* CommonData)
{
	int i;
	int j;
	int x;
	int z;
	int Top;
	int Bottom;

	glBindTexture(0, CommonData->Textures[LOGO_IMG]);
	glBegin(GL_QUADS);
	glTexCoord2t16(inttot16(32), inttot16(16));
	glVertex3f(-0.075 - Shrinking.Value[0], 0.0, 0.1375 + Shrinking.Value[2]);
	glTexCoord2t16(inttot16(32), inttot16(113));
	glVertex3f(-0.075 - Shrinking.Value[0], 0.0, 0.0625 + Shrinking.Value[3]);
	glTexCoord2t16(inttot16(225), inttot16(113));
	glVertex3f(0.075 - Shrinking.Value[1], 0.0, 0.0625 + Shrinking.Value[3]);
	glTexCoord2t16(inttot16(225), inttot16(16));
	glVertex3f(0.075 - Shrinking.Value[1], 0.0, 0.1375 + Shrinking.Value[2]);
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
	glColor3f(210.0 / 255.0, 180.0 / 255.0, 140.0 / 255.0);
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
	glColor3f(255.0 / 255.0, 225.0 / 255.0, 175.0 / 255.0);
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
	glColor3f(240.0 / 255.0, 205.0 / 255.0, 160.0 / 255.0);
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
	glColor3f(168.0 / 255.0, 144.0 / 255.0, 112.0 / 255.0);
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
	glColor3f(184.0 / 255.0, 156.0 / 255.0, 122.0 / 255.0);
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
