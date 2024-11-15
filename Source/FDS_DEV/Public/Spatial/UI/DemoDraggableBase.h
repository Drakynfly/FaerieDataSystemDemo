// Copyright Guy (Drakynfly) Lundvall. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "Components/Image.h"
#include "Components/SizeBox.h"
#include "DemoDraggableBase.generated.h"

/**
 * 
 */
UCLASS()
class FDS_DEV_API UDemoDraggableBase : public UUserWidget
{
	GENERATED_BODY()

public:
	virtual void NativeOnInitialized() override;
	virtual void NativeConstruct() override;
	void UpdateDragVisual() const;
	
	UPROPERTY(EditAnywhere)
	TObjectPtr<UImage> DragIcon;

	UPROPERTY()
	TObjectPtr<USizeBox> DragIconSize;
};
