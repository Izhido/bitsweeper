#include "StateMachineClass.h"
#include "StateIncludes.h"

StateMachineClass::StateMachineClass()
: Current(SHUT_DOWN_STATE),
Requested(BACKGROUND_FADE_IN_STATE)
{
	List = new StateClass*[38];
	List[BACKGROUND_FADE_IN_STATE] = new BackgroundFadeInStateClass();
	List[LOGO_ZOOM_IN_STATE] = new LogoZoomInStateClass();
	List[START_BUTTON_ZOOM_IN_STATE] = new StartButtonZoomInStateClass();
	List[LEGEND_APPEAR_STATE] = new LegendAppearStateClass();
	List[START_BUTTON_WAIT_STATE] = new StartButtonWaitStateClass();
	List[LEGEND_VANISH_STATE] = new LegendVanishStateClass();
	List[LOGO_AND_START_BUTTON_VANISH_STATE] = new LogoAndStartButtonVanishStateClass();
	List[BACKGROUND_FADE_OUT_STATE] = new BackgroundFadeOutStateClass();
	List[SHUT_DOWN_STATE] = new ShutDownStateClass();
	List[LEGEND_DISAPPEAR_STATE] = new LegendDisappearStateClass();
	List[START_BUTTON_VANISH_STATE] = new StartButtonVanishStateClass();
	List[MENU_APPEAR_STATE] = new MenuAppearStateClass();
	List[MENU_VANISH_STATE] = new MenuVanishStateClass();
	List[START_BUTTON_APPEAR_STATE] = new StartButtonAppearStateClass();
	List[MENU_WAIT_STATE] = new MenuWaitStateClass();
	List[MENU_DISAPPEAR_STATE] = new MenuDisappearStateClass();
	List[BOARD_APPEAR_STATE] = new BoardAppearStateClass();
	List[LOGO_SHRINK_STATE] = new LogoShrinkStateClass();
	List[BOARD_WAIT_STATE] = new BoardWaitStateClass();
	List[LOGO_ENLARGE_STATE] = new LogoEnlargeStateClass();
	List[BOARD_DISAPPEAR_STATE] = new BoardDisappearStateClass();
	List[BOARD_CELL_CHANGE_DISAPPEAR_STATE] = new BoardCellChangeDisappearStateClass();
	List[BOARD_CELL_CHANGE_APPEAR_STATE] = new BoardCellChangeAppearStateClass();
	List[BOARD_CELL_UNCOVER_STATE] = new BoardCellUncoverStateClass();
	List[BOARD_CELL_EXPLODE_STATE] = new BoardCellExplodeStateClass();
	List[GAME_LOST_APPEAR_STATE] = new GameLostAppearStateClass();
	List[GAME_LOST_VISIBLE_WAIT_STATE] = new GameLostVisibleWaitStateClass();
	List[GAME_LOST_DISAPPEAR_STATE] = new GameLostDisappearStateClass();
	List[GAME_LOST_NOT_VISIBLE_WAIT_STATE] = new GameLostNotVisibleWaitStateClass();
	List[GAME_LOST_VANISH_STATE] = new GameLostVanishStateClass();
	List[GAME_WON_APPEAR_STATE] = new GameWonAppearStateClass();
	List[GAME_WON_VISIBLE_WAIT_STATE] = new GameWonVisibleWaitStateClass();
	List[GAME_WON_DISAPPEAR_STATE] = new GameWonDisappearStateClass();
	List[GAME_WON_NOT_VISIBLE_WAIT_STATE] = new GameWonNotVisibleWaitStateClass();
	List[GAME_WON_VANISH_STATE] = new GameWonVanishStateClass();
	List[BEST_SCORES_TABLE_APPEAR_STATE] = new BestScoresTableAppearStateClass();
	List[BEST_SCORES_TABLE_WAIT_STATE] = new BestScoresTableWaitStateClass();
	List[BEST_SCORES_TABLE_DISAPPEAR_STATE] = new BestScoresTableDisappearStateClass();
}

bool StateMachineClass::Run(CommonDataClass* CommonData)
{
	if(Current != Requested)
	{
		Current = Requested;
		return List[Current]->Start(CommonData);
	} else
	{
		return List[Current]->Run(CommonData);
	};
}

void StateMachineClass::Draw(CommonDataClass* CommonData)
{
	List[Current]->Draw(CommonData);
}

void StateMachineClass::Switch(int NewState)
{
	Requested = NewState;
}

StateMachineClass::~StateMachineClass()
{
	delete[] List;
}
