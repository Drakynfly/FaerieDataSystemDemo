// Copyright Guy (Drakynfly) Lundvall. All Rights Reserved.

#pragma once

#include "BPTimerStruct.generated.h"

USTRUCT(BlueprintType)
struct FBlueprintTimer
{
	GENERATED_BODY()

	UPROPERTY()
	FDateTime Time;
};

/**
 *
 */
UCLASS()
class FDS_DEV_API UBPTimerStruct : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable)
	static void Reset(UPARAM(ref) FBlueprintTimer& Timer);

	UFUNCTION(BlueprintPure)
	static double GetMilliseconds(FBlueprintTimer Timer);
};
