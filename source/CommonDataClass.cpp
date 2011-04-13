#include "CommonDataClass.h"
#include "StateMachineClass.h"
#include "ImageIncludes.h"
#include "RandomNumberGeneratorClass.h"
#include "BestScoresTableClass.h"

CommonDataClass::CommonDataClass()
: ToBottomScreen(false),
DrawAgain(true),
KeysHeld(0),
TouchX(0),
TouchY(0),
CellTouched(false),
ClearColorR(0),
ClearColorG(0),
ClearColorB(0),
LocationX(0),
LocationZ(0),
LegendX(0),
Level(0),
LastGameWon(false),
RandomNumberGenerator(0),
Board(0),
BoardWidth(0),
BoardHeight(0),
CellsBeingUncoveredList(0),
BoardCellXCoordinates(0),
BoardCellZCoordinates(0),
TickCount(0),
BestScoresTable(0),
FilesystemEnabled(false),
IsLeftHanded(false),
Finished(false)
{
	StateMachine = new StateMachineClass();
	POV = new m4x4;
	POV->m[0] = floattof32(1.0);
	POV->m[1] = floattof32(0.0);
	POV->m[2] = floattof32(0.0);
	POV->m[3] = floattof32(0.0);
	POV->m[4] = floattof32(0.0);
	POV->m[5] = floattof32(0.0);
	POV->m[6] = floattof32(1.0);
	POV->m[7] = floattof32(0.0);
	POV->m[8] = floattof32(0.0);
	POV->m[9] = floattof32(1.0);
	POV->m[10] = floattof32(0.0);
	POV->m[11] = floattof32(0.0);
	POV->m[12] = floattof32(0.0);
	POV->m[13] = floattof32(0.0);
	POV->m[14] = floattof32(0.0);
	POV->m[15] = floattof32(1.0);
	Textures = new int[33];
	Palettes = new int[33];
	glGenTextures(33, Textures);
	glBindTexture(0, Textures[LOGO_IMG]);
	glTexImage2D(0, 0, GL_RGB256, TEXTURE_SIZE_256, TEXTURE_SIZE_128, 0, TEXGEN_TEXCOORD, LogoBitmap);
	glColorTableEXT(0, 0, LogoPalLen, 0, 0, LogoPal);
	glBindTexture(0, Textures[START_BUTTON_IMG]);
	glTexImage2D(0, 0, GL_RGB256, TEXTURE_SIZE_128, TEXTURE_SIZE_64, 0, TEXGEN_TEXCOORD, StartBitmap);
	glColorTableEXT(0, 0, StartPalLen, 0, 0, StartPal);
	glBindTexture(0, Textures[LEGEND_IMG]);
	glTexImage2D(0, 0, GL_RGB256, TEXTURE_SIZE_512, TEXTURE_SIZE_16, 0, TEXGEN_TEXCOORD, LegendBitmap);
	glColorTableEXT(0, 0, LegendPalLen, 0, 0, LegendPal);
	glBindTexture(0, Textures[MENU_IMG]);
	glTexImage2D(0, 0, GL_RGB256, TEXTURE_SIZE_128, TEXTURE_SIZE_128, 0, TEXGEN_TEXCOORD, MenuBitmap);
	glColorTableEXT(0, 0, MenuPalLen, 0, 0, MenuPal);
	glBindTexture(0, Textures[SELECTED_ITEM_IMG]);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_16, TEXTURE_SIZE_16, 0, TEXGEN_TEXCOORD, SelectedItemBitmap);
	glBindTexture(0, Textures[UNSELECTED_ITEM_IMG]);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_16, TEXTURE_SIZE_16, 0, TEXGEN_TEXCOORD, UnselectedItemBitmap);
	glBindTexture(0, Textures[ONE_IMG]);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_16, TEXTURE_SIZE_16, 0, TEXGEN_TEXCOORD, OneBitmap);
	glBindTexture(0, Textures[ONE_IMG + 1]);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_16, TEXTURE_SIZE_16, 0, TEXGEN_TEXCOORD, TwoBitmap);
	glBindTexture(0, Textures[ONE_IMG + 2]);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_16, TEXTURE_SIZE_16, 0, TEXGEN_TEXCOORD, ThreeBitmap);
	glBindTexture(0, Textures[ONE_IMG + 3]);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_16, TEXTURE_SIZE_16, 0, TEXGEN_TEXCOORD, FourBitmap);
	glBindTexture(0, Textures[ONE_IMG + 4]);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_16, TEXTURE_SIZE_16, 0, TEXGEN_TEXCOORD, FiveBitmap);
	glBindTexture(0, Textures[ONE_IMG + 5]);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_16, TEXTURE_SIZE_16, 0, TEXGEN_TEXCOORD, SixBitmap);
	glBindTexture(0, Textures[ONE_IMG + 6]);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_16, TEXTURE_SIZE_16, 0, TEXGEN_TEXCOORD, SevenBitmap);
	glBindTexture(0, Textures[ONE_IMG + 7]);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_16, TEXTURE_SIZE_16, 0, TEXGEN_TEXCOORD, EightBitmap);
	glBindTexture(0, Textures[FLAG_IMG]);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_16, TEXTURE_SIZE_16, 0, TEXGEN_TEXCOORD, FlagBitmap);
	glBindTexture(0, Textures[QUESTION_IMG]);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_16, TEXTURE_SIZE_16, 0, TEXGEN_TEXCOORD, QuestionBitmap);
	glBindTexture(0, Textures[BOMB_IMG]);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_16, TEXTURE_SIZE_16, 0, TEXGEN_TEXCOORD, BombBitmap);
	glBindTexture(0, Textures[YOU_WIN_IMG]);
	glTexImage2D(0, 0, GL_RGB256, TEXTURE_SIZE_128, TEXTURE_SIZE_64, 0, TEXGEN_TEXCOORD, YouWinBitmap);
	glColorTableEXT(0, 0, YouWinPalLen, 0, 0, YouWinPal);
	glBindTexture(0, Textures[YOU_LOSE_IMG]);
	glTexImage2D(0, 0, GL_RGB256, TEXTURE_SIZE_128, TEXTURE_SIZE_64, 0, TEXGEN_TEXCOORD, YouLoseBitmap);
	glColorTableEXT(0, 0, YouLosePalLen, 0, 0, YouLosePal);
	glBindTexture(0, Textures[TIME_0_IMG]);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_8, TEXTURE_SIZE_8, 0, TEXGEN_TEXCOORD, Time0Bitmap);
	glBindTexture(0, Textures[TIME_0_IMG + 1]);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_8, TEXTURE_SIZE_8, 0, TEXGEN_TEXCOORD, Time1Bitmap);
	glBindTexture(0, Textures[TIME_0_IMG + 2]);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_8, TEXTURE_SIZE_8, 0, TEXGEN_TEXCOORD, Time2Bitmap);
	glBindTexture(0, Textures[TIME_0_IMG + 3]);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_8, TEXTURE_SIZE_8, 0, TEXGEN_TEXCOORD, Time3Bitmap);
	glBindTexture(0, Textures[TIME_0_IMG + 4]);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_8, TEXTURE_SIZE_8, 0, TEXGEN_TEXCOORD, Time4Bitmap);
	glBindTexture(0, Textures[TIME_0_IMG + 5]);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_8, TEXTURE_SIZE_8, 0, TEXGEN_TEXCOORD, Time5Bitmap);
	glBindTexture(0, Textures[TIME_0_IMG + 6]);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_8, TEXTURE_SIZE_8, 0, TEXGEN_TEXCOORD, Time6Bitmap);
	glBindTexture(0, Textures[TIME_0_IMG + 7]);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_8, TEXTURE_SIZE_8, 0, TEXGEN_TEXCOORD, Time7Bitmap);
	glBindTexture(0, Textures[TIME_0_IMG + 8]);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_8, TEXTURE_SIZE_8, 0, TEXGEN_TEXCOORD, Time8Bitmap);
	glBindTexture(0, Textures[TIME_0_IMG + 9]);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_8, TEXTURE_SIZE_8, 0, TEXGEN_TEXCOORD, Time9Bitmap);
	glBindTexture(0, Textures[TIME_COLON_IMG]);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_8, TEXTURE_SIZE_8, 0, TEXGEN_TEXCOORD, TimeColonBitmap);
	glBindTexture(0, Textures[BEST_SCORES_PLUS_EXPERT_PLUS_INSANE_IMG]);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_128, TEXTURE_SIZE_16, 0, TEXGEN_TEXCOORD, BestScoresPlusExpertPlusInsaneBitmap);
	glBindTexture(0, Textures[BEGINNER_PLUS_INTERMEDIATE_IMG]);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_128, TEXTURE_SIZE_16, 0, TEXGEN_TEXCOORD, BeginnerPlusIntermediateBitmap);
	glBindTexture(0, Textures[LOGO_SMALL_IMG]);
	glTexImage2D(0, 0, GL_RGB, TEXTURE_SIZE_64, TEXTURE_SIZE_32, 0, TEXGEN_TEXCOORD, LogoSmallBitmap);
	BestScoresTable = new BestScoresTableClass();
}

CommonDataClass::~CommonDataClass()
{
	delete BestScoresTable;
	delete RandomNumberGenerator;
	delete[] Palettes;
	delete[] Textures;
	delete POV;
	delete StateMachine;
}
