#include "MenuWaitStateClass.h"
#include "CommonDataClass.h"
#include <nds/arm9/input.h>
#include "StateMachineClass.h"
#include "MenuVanishStateClass.h"
#include "MenuDisappearStateClass.h"
#include "OperationsClass.h"

MenuWaitStateClass::MenuWaitStateClass()
: StateClass()
{
}

bool MenuWaitStateClass::Start(CommonDataClass* CommonData)
{
	LButtonPressed = false;
	RButtonPressed = false;
	if(CommonData->LastGameWon)
	{
		if(CommonData->Level < 3)
		{
			CommonData->Level = CommonData->Level + 1;
		};
		CommonData->LastGameWon = false;
	};
	return true;
}

bool MenuWaitStateClass::Run(CommonDataClass* CommonData)
{
	if(((CommonData->KeysHeld & KEY_A) != 0)||((CommonData->KeysHeld & KEY_Y) != 0))
	{
		CommonData->IsLeftHanded = false;
		CommonData->StateMachine->Switch(MENU_DISAPPEAR_STATE);
	} else if(((CommonData->KeysHeld & KEY_LEFT) != 0)||((CommonData->KeysHeld & KEY_RIGHT) != 0))
	{
		CommonData->IsLeftHanded = true;
		CommonData->StateMachine->Switch(MENU_DISAPPEAR_STATE);
	} else if(((CommonData->KeysHeld & KEY_B) != 0)||((CommonData->KeysHeld & KEY_X) != 0)||((CommonData->KeysHeld & KEY_UP) != 0)||((CommonData->KeysHeld & KEY_DOWN) != 0))
	{
		CommonData->StateMachine->Switch(MENU_VANISH_STATE);
	} else if((CommonData->TouchX >= 77) && (CommonData->TouchX < 180) && (CommonData->TouchY >= 39) && (CommonData->TouchY < 54))
	{
		CommonData->Level = 0;
	} else if((CommonData->TouchX >= 77) && (CommonData->TouchX < 180) && (CommonData->TouchY >= 54) && (CommonData->TouchY < 69))
	{
		CommonData->Level = 1;
	} else if((CommonData->TouchX >= 77) && (CommonData->TouchX < 180) && (CommonData->TouchY >= 69) && (CommonData->TouchY < 82))
	{
		CommonData->Level = 2;
	} else if((CommonData->TouchX >= 77) && (CommonData->TouchX < 180) && (CommonData->TouchY >= 82) && (CommonData->TouchY < 99))
	{
		CommonData->Level = 3;
	} else if((CommonData->TouchX >= 77) && (CommonData->TouchX < 180) && (CommonData->TouchY >= 102) && (CommonData->TouchY < 128))
	{
		CommonData->StateMachine->Switch(MENU_DISAPPEAR_STATE);
	} else if((CommonData->TouchX >= 73) && (CommonData->TouchX < 128) && (CommonData->TouchY >= 130) && (CommonData->TouchY < 159))
	{
		CommonData->IsLeftHanded = true;
	} else if((CommonData->TouchX >= 128) && (CommonData->TouchX < 183) && (CommonData->TouchY >= 130) && (CommonData->TouchY < 159))
	{
		CommonData->IsLeftHanded = false;
	};
	if((CommonData->KeysHeld & KEY_L) != 0)
	{
		if(!LButtonPressed)
		{
			if(CommonData->Level > 0)
			{
				CommonData->Level = CommonData->Level - 1;
			};
			LButtonPressed = true;
		};
	} else
	{
		LButtonPressed = false;
	};
	if((CommonData->KeysHeld & KEY_R) != 0)
	{
		if(!RButtonPressed)
		{
			if(CommonData->Level < 3)
			{
				CommonData->Level = CommonData->Level + 1;
			};
			RButtonPressed = true;
		};
	} else
	{
		RButtonPressed = false;
	};
	return true;
}

void MenuWaitStateClass::Draw(CommonDataClass* CommonData)
{
	Operations::DrawLargeCenteredLogo(CommonData);
	glBindTexture(0, CommonData->Textures[MENU_IMG]);
	glBegin(GL_QUADS);
	glTexCoord2t16(inttot16(0), inttot16(0));
	glVertex3f(-0.05, 0.0, -0.05);
	glTexCoord2t16(inttot16(0), inttot16(128));
	glVertex3f(-0.05, 0.0, -0.15);
	glTexCoord2t16(inttot16(128), inttot16(128));
	glVertex3f(0.0525, 0.0, -0.15);
	glTexCoord2t16(inttot16(128), inttot16(0));
	glVertex3f(0.0525, 0.0, -0.05);
	glEnd();
	if(CommonData->Level == 0)
	{
		glBindTexture(0, CommonData->Textures[SELECTED_ITEM_IMG]);
	} else
	{
		glBindTexture(0, CommonData->Textures[UNSELECTED_ITEM_IMG]);
	};
	glBegin(GL_QUADS);
	glTexCoord2t16(inttot16(0), inttot16(0));
	glVertex3f(-0.04, 0.001, -0.0555);
	glTexCoord2t16(inttot16(0), inttot16(16));
	glVertex3f(-0.04, 0.001, -0.0675);
	glTexCoord2t16(inttot16(16), inttot16(16));
	glVertex3f(-0.0275, 0.001, -0.0675);
	glTexCoord2t16(inttot16(16), inttot16(0));
	glVertex3f(-0.0275, 0.001, -0.0555);
	glEnd();
	if(CommonData->Level == 1)
	{
		glBindTexture(0, CommonData->Textures[SELECTED_ITEM_IMG]);
	} else
	{
		glBindTexture(0, CommonData->Textures[UNSELECTED_ITEM_IMG]);
	};
	glBegin(GL_QUADS);
	glTexCoord2t16(inttot16(0), inttot16(0));
	glVertex3f(-0.04, 0.001, -0.0675);
	glTexCoord2t16(inttot16(0), inttot16(16));
	glVertex3f(-0.04, 0.001, -0.0795);
	glTexCoord2t16(inttot16(16), inttot16(16));
	glVertex3f(-0.0275, 0.001, -0.0795);
	glTexCoord2t16(inttot16(16), inttot16(0));
	glVertex3f(-0.0275, 0.001, -0.0675);
	glEnd();
	if(CommonData->Level == 2)
	{
		glBindTexture(0, CommonData->Textures[SELECTED_ITEM_IMG]);
	} else
	{
		glBindTexture(0, CommonData->Textures[UNSELECTED_ITEM_IMG]);
	};
	glBegin(GL_QUADS);
	glTexCoord2t16(inttot16(0), inttot16(0));
	glVertex3f(-0.04, 0.001, -0.0795);
	glTexCoord2t16(inttot16(0), inttot16(16));
	glVertex3f(-0.04, 0.001, -0.0915);
	glTexCoord2t16(inttot16(16), inttot16(16));
	glVertex3f(-0.0275, 0.001, -0.0915);
	glTexCoord2t16(inttot16(16), inttot16(0));
	glVertex3f(-0.0275, 0.001, -0.0795);
	glEnd();
	if(CommonData->Level == 3)
	{
		glBindTexture(0, CommonData->Textures[SELECTED_ITEM_IMG]);
	} else
	{
		glBindTexture(0, CommonData->Textures[UNSELECTED_ITEM_IMG]);
	};
	glBegin(GL_QUADS);
	glTexCoord2t16(inttot16(0), inttot16(0));
	glVertex3f(-0.04, 0.001, -0.0915);
	glTexCoord2t16(inttot16(0), inttot16(16));
	glVertex3f(-0.04, 0.001, -0.1035);
	glTexCoord2t16(inttot16(16), inttot16(16));
	glVertex3f(-0.0275, 0.001, -0.1035);
	glTexCoord2t16(inttot16(16), inttot16(0));
	glVertex3f(-0.0275, 0.001, -0.0915);
	glEnd();
	if(CommonData->IsLeftHanded)
	{
		glBindTexture(0, CommonData->Textures[SELECTED_ITEM_IMG]);
	} else
	{
		glBindTexture(0, CommonData->Textures[UNSELECTED_ITEM_IMG]);
	};
	glBegin(GL_QUADS);
	glTexCoord2t16(inttot16(0), inttot16(0));
	glVertex3f(-0.0425, 0.001, -0.13);
	glTexCoord2t16(inttot16(0), inttot16(16));
	glVertex3f(-0.0425, 0.001, -0.1425);
	glTexCoord2t16(inttot16(16), inttot16(16));
	glVertex3f(-0.03, 0.001, -0.1425);
	glTexCoord2t16(inttot16(16), inttot16(0));
	glVertex3f(-0.03, 0.001, -0.13);
	glEnd();
	if(CommonData->IsLeftHanded)
	{
		glBindTexture(0, CommonData->Textures[UNSELECTED_ITEM_IMG]);
	} else
	{
		glBindTexture(0, CommonData->Textures[SELECTED_ITEM_IMG]);
	};
	glBegin(GL_QUADS);
	glTexCoord2t16(inttot16(0), inttot16(0));
	glVertex3f(0.035, 0.001, -0.13);
	glTexCoord2t16(inttot16(0), inttot16(16));
	glVertex3f(0.035, 0.001, -0.1425);
	glTexCoord2t16(inttot16(16), inttot16(16));
	glVertex3f(0.0475, 0.001, -0.1425);
	glTexCoord2t16(inttot16(16), inttot16(0));
	glVertex3f(0.0475, 0.001, -0.13);
	glEnd();
}
