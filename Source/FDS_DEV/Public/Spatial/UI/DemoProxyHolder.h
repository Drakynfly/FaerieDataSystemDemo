// Copyright Guy (Drakynfly) Lundvall. All Rights Reserved.

#pragma once

#include "InventoryStorageProxy.h"
#include "Blueprint/UserWidget.h"
#include "DemoProxyHolder.generated.h"

/**
 * 
 */
UCLASS()
class FDS_DEV_API UDemoProxyHolder : public UUserWidget
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Item Data")
	TObjectPtr<UInventoryStackProxy> Proxy; 
};
