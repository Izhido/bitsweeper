#include "ShutDownStateClass.h"
#include "CommonDataClass.h"

ShutDownStateClass::ShutDownStateClass()
: StateClass()
{
}

bool ShutDownStateClass::Start(CommonDataClass* CommonData)
{
	CommonData->Finished = true;
	return false;
}

bool ShutDownStateClass::Run(CommonDataClass* CommonData)
{
	return false;
}

void ShutDownStateClass::Draw(CommonDataClass* CommonData)
{
}
