#ifndef OPERATIONSCLASS_H
#define OPERATIONSCLASS_H

class OperationsClass
{
public:
	static void DoBoardScrolling(class CommonDataClass* CommonData);

	static void UpdateBoardLocation(CommonDataClass* CommonData);

	static void UpdateBoardCellBorders(CommonDataClass* CommonData);

	static void DrawSmallUpperLeftLogo(CommonDataClass* CommonData);

	static void DrawLargeCenteredLogo(CommonDataClass* CommonData);

	static void DrawOneCell(CommonDataClass* CommonData, int t, int x, int z);

	static void DrawEmptyCells(CommonDataClass* CommonData, int Top, int Bottom);

	static void DrawNonEmptyCells(CommonDataClass* CommonData, int Top, int Bottom);

	static void DrawCellBorders(CommonDataClass* CommonData, int Top, int Bottom);

	static void DrawSmallUpperRightClock(CommonDataClass* CommonData, float TimeHeight = 0);

	static bool IsEmptyCell(CommonDataClass* CommonData, int k);

};

typedef OperationsClass Operations;

#endif