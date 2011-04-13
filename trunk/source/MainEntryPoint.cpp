#include "CommonDataClass.h"
#include "StateMachineClass.h"
#include <nds.h>
#include <fat.h>

static CommonDataClass* CommonData;

void DoVBlank()
{
	CommonData->TickCount++;
}

int main(int argc, char* argv[])
{
	int x;
	int y;
	int i;
	uint32 CurrentKeysHeld;
	touchPosition CurrentTouchPosition;

	videoSetMode(MODE_0_3D);
	videoSetModeSub(MODE_5_2D);
	vramSetBankA(VRAM_A_TEXTURE);
	vramSetBankB(VRAM_B_TEXTURE);
	vramSetBankE(VRAM_E_TEX_PALETTE);
	glInit();
	oamInit(&oamSub, SpriteMapping_Bmp_2D_256, false);
	i = 0; 
	for(y = 0; y < 3; y++)
	{
		for(x = 0; x < 4; x++)
		{
			oamSub.oamMemory[i].attribute[0] = ATTR0_BMP | ATTR0_SQUARE | (64 * y);
			oamSub.oamMemory[i].attribute[1] = ATTR1_SIZE_64 | (64 * x);
			oamSub.oamMemory[i].attribute[2] = ATTR2_ALPHA(1) | (8 * 32 * y) | (8 * x);
			i++;
		};
	};
	swiWaitForVBlank();
	oamUpdate(&oamSub);
	bgInitSub(3, BgType_Bmp16, BgSize_B16_256x256, 0, 0);
	glViewport(0, 0, 255, 191);
	glEnable(GL_TEXTURE_2D | GL_ANTIALIAS);
	glClearDepth(GL_MAX_DEPTH);
	glClearPolyID(63);
	CommonData = new CommonDataClass();
	irqInit();
	irqSet(IRQ_VBLANK, &DoVBlank);
	CommonData->FilesystemEnabled = fatInitDefault();
	while(!(CommonData->Finished)) 
	{
		while(REG_DISPCAPCNT & DCAP_ENABLE);
		CommonData->ToBottomScreen = !(CommonData->ToBottomScreen);
		if(CommonData->ToBottomScreen)
		{
			lcdMainOnTop();
			vramSetBankD(VRAM_D_LCD);
			vramSetBankC(VRAM_C_SUB_BG);
			REG_DISPCAPCNT = DCAP_BANK(3) | DCAP_ENABLE | DCAP_SIZE(3);
		}
		else
		{
			lcdMainOnBottom();
			vramSetBankC(VRAM_C_LCD);
			vramSetBankD(VRAM_D_SUB_SPRITE);
			REG_DISPCAPCNT = DCAP_BANK(2) | DCAP_ENABLE | DCAP_SIZE(3);
			scanKeys();
			CurrentKeysHeld = keysHeld();
			touchRead(&CurrentTouchPosition);
			if((CommonData->KeysHeld != CurrentKeysHeld) 
			|| (CommonData->TouchX != CurrentTouchPosition.rawx) 
			|| (CommonData->TouchY != CurrentTouchPosition.rawy))
			{
				CommonData->DrawAgain = true;
			};
			CommonData->KeysHeld = CurrentKeysHeld;
			CommonData->TouchX = CurrentTouchPosition.px;
			CommonData->TouchY = CurrentTouchPosition.py;
			if(CommonData->DrawAgain)
			{
				CommonData->DrawAgain = CommonData->StateMachine->Run(CommonData);
			};
		}
		glMatrixMode(GL_PROJECTION);
		glLoadIdentity();
		gluPerspective(72, 256.0 / 192.0, 0.01, 2.01);
		glMatrixMode(GL_MODELVIEW);
		glLoadMatrix4x4(CommonData->POV);
		if(CommonData->ToBottomScreen)
		{
			glTranslate3f32(floattof32(-(CommonData->LocationX)),
							floattof32(-0.11),
							floattof32(-(CommonData->LocationZ) + 0.1));
		} else
		{
			glTranslate3f32(floattof32(-(CommonData->LocationX)),
							floattof32(-0.11),
							floattof32(-(CommonData->LocationZ) - 0.1));
		};
		glMatrixMode(GL_TEXTURE);
		glLoadIdentity();
		glClearColor(CommonData->ClearColorR, CommonData->ClearColorG, CommonData->ClearColorB, 31);
		glPolyFmt(POLY_ALPHA(31) | POLY_CULL_BACK);
		glColor3b(255, 255, 255);
		CommonData->StateMachine->Draw(CommonData);
		glFlush(0);
	};
	return 0;
}
