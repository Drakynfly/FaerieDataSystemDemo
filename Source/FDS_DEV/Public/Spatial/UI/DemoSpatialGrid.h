// Copyright Guy (Drakynfly) Lundvall. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Blueprint/UserWidget.h"
#include "DemoSpatialGrid.generated.h"

/**
 * 
 */
UCLASS()
class FDS_DEV_API UDemoSpatialGrid : public UUserWidget
{
	GENERATED_BODY()
public:
	virtual FReply NativeOnMouseButtonDown(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent) override;
	virtual bool NativeOnDrop(const FGeometry& InGeometry, const FDragDropEvent& InDragDropEvent, UDragDropOperation* InOperation) override;
	virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	TObjectPtr<UPanelWidget> GridPanel;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget)) 
	TObjectPtr<UPanelWidget> IconPanel;
};
