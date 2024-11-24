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

	UFUNCTION(BlueprintCallable, Category = "Spatial Grid")
	UWidget* GetCellUnderCursor(const FVector2D AbsolutePosition) const;

	UFUNCTION(BlueprintCallable, Category = "Spatial Grid")
	UWidget* GetItemUnderCursor(const FVector2D AbsolutePosition) const;

protected:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TObjectPtr<UWidget>> CellWidgets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TArray<TObjectPtr<UWidget>> IconWidgets;
};