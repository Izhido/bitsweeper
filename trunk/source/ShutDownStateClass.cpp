#include "ShutDownStateClass.h"
#include "CommonDataClass.h"

ShutDownStateClass::ShutDownStateClass()
: StateClass()
{
}

void ShutDownStateClass::Start(CommonDataClass* CommonData)
{
	CommonData->Finished = true;
}

void ShutDownStateClass::Run(CommonDataClass* CommonData)
{
}

void ShutDownStateClass::Draw(CommonDataClass* CommonData)
{
}
