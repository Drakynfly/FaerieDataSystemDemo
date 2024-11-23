// Copyright Guy (Drakynfly) Lundvall. All Rights Reserved.


#include "BPTimerStruct.h"

void UBPTimerStruct::TriggerCPPBreakpoint()
{
	// put a breakpoint on this check, and call from blueprint to get a breakpoint in the BP VM.
	check(1);
}

void UBPTimerStruct::Reset(FBlueprintTimer& Timer)
{
	Timer.Time = FDateTime::Now();
}

double UBPTimerStruct::GetMilliseconds(const FBlueprintTimer Timer)
{
	auto&& Now = FDateTime::Now();
	return (Now - Timer.Time).GetTotalMilliseconds();
}