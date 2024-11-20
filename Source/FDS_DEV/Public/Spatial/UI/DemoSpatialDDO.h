// Copyright Guy (Drakynfly) Lundvall. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "FaerieItemProxy.h"
#include "Blueprint/DragDropOperation.h"
#include "DemoSpatialDDO.generated.h"

/**
 * 
 */
UCLASS()
class FDS_DEV_API UDemoSpatialDDO : public UDragDropOperation
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FIntPoint SourcePoint;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TObjectPtr<UWidget> DragWidget;
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	FFaerieItemProxy Proxy;
};
