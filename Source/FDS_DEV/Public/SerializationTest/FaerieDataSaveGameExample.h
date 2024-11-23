// Copyright Guy (Drakynfly) Lundvall. All Rights Reserved.

#pragma once

#include "GameFramework/SaveGame.h"
#include "InventoryDataStructs.h"
#include "FaerieDataSaveGameExample.generated.h"

class UFaerieEquipmentManager;
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

	UFUNCTION(BlueprintCallable, Category = "FaerieDataSaveGameExample")
	void ReadEquipment(const UFaerieEquipmentManager* Equipment);

	UFUNCTION(BlueprintCallable, Category = "FaerieDataSaveGameExample")
	void WriteEquipment(UFaerieEquipmentManager* Equipment);

protected:
	UPROPERTY()
	FFaerieContainerSaveData SaveData;
};