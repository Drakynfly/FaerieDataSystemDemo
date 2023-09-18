// Copyright Guy (Drakynfly) Lundvall. All Rights Reserved.


#include "BPTimerStruct.h"

void UBPTimerStruct::Reset(FBlueprintTimer& Timer)
{
	Timer.Time = FDateTime::Now();
}

double UBPTimerStruct::GetMilliseconds(const FBlueprintTimer Timer)
{
	auto&& Now = FDateTime::Now();
	return (Now - Timer.Time).GetTotalMilliseconds();
}


