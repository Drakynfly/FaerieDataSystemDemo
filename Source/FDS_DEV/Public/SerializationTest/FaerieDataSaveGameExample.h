// Copyright Guy (Drakynfly) Lundvall. All Rights Reserved.

#pragma once

#include "GameFramework/SaveGame.h"
#include "InventoryDataStructs.h"
#include "FaerieDataSaveGameExample.generated.h"

class UFaerieItemContainerBase;

/**
 *
 */
UCLASS()
class FDS_DEV_API UFaerieDataSaveGameExample : public USaveGame
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "FaerieDataSaveGameExample")
	void Read(const UFaerieItemContainerBase* Container);
	
	UFUNCTION(BlueprintCallable, Category = "FaerieDataSaveGameExample")
	void Write(UFaerieItemContainerBase* Container);

protected:
	UPROPERTY()
	FFaerieContainerSaveData SaveData;
};