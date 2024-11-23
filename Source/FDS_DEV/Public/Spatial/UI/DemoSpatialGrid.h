// Copyright Guy (Drakynfly) Lundvall. All Rights Reserved.

#pragma once

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
	virtual void NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent, UDragDropOperation*& OutOperation) override;

	UFUNCTION(BlueprintCallable)
	UWidget* GetChildUnderCursor(const FVector2D AbsolutePosition, UPanelWidget* InPanel);

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	TObjectPtr<UPanelWidget> GridPanel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta=(BindWidget))
	TObjectPtr<UPanelWidget> IconPanel;
};