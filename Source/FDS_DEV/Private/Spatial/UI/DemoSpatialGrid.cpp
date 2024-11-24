// Copyright Guy (Drakynfly) Lundvall. All Rights Reserved.

#include "Spatial/UI/DemoSpatialGrid.h"
#include "Spatial/UI/DemoProxyHolder.h"
#include "Spatial/UI/DemoDraggableBase.h"
#include "Spatial/UI/DemoSpatialDDO.h"

#include "Blueprint/WidgetTree.h"
#include "Components/GridSlot.h"

UWidget* UDemoSpatialGrid::GetCellUnderCursor(const FVector2D AbsolutePosition) const
{
	for (auto&& Child : CellWidgets)
	{
		if (IsValid(Child) && Child->GetCachedGeometry().IsUnderLocation(AbsolutePosition))
		{
			return Child;
		}
	}
	return nullptr;
}

UWidget* UDemoSpatialGrid::GetItemUnderCursor(const FVector2D AbsolutePosition) const
{
	for (auto&& Child : IconWidgets)
	{
		if (IsValid(Child) && Child->GetCachedGeometry().IsUnderLocation(AbsolutePosition))
		{
			return Child;
		}
	}
	return nullptr;
}

void UDemoSpatialGrid::NativeOnDragDetected(const FGeometry& InGeometry, const FPointerEvent& InMouseEvent,
											UDragDropOperation*& OutOperation)
{
	UDemoSpatialDDO* OutDDO = NewObject<UDemoSpatialDDO>();
	//OutDDO->Pivot = EDragPivot::MouseDown;
	OutOperation = OutDDO;
	const FVector2D ScreenSpacePosition = InMouseEvent.GetScreenSpacePosition();

	if (auto&& CellWidget = GetCellUnderCursor(ScreenSpacePosition))
	{
		if (const auto* GridSlot = Cast<UGridSlot>(CellWidget->Slot))
		{
			OutDDO->SourcePoint = FIntPoint(GridSlot->GetColumn(), GridSlot->GetRow());
			OutDDO->Payload = CellWidget;
		}
	}

	if (auto&& ItemWidget = GetItemUnderCursor(ScreenSpacePosition))
	{
		auto DragWidget = CreateWidget<UDemoDraggableBase>(GetOwningPlayer(), UDemoDraggableBase::StaticClass());
		if (const auto* DraggableBase = Cast<UUserWidget>(ItemWidget))
		{
			// Get the original widget's absolute size in screen space
			const FVector2D OriginalScreenSize = ItemWidget->GetCachedGeometry().GetAbsoluteSize();

			// Get the original widget's desired size
			const FVector2D OriginalDesiredSize = ItemWidget->GetDesiredSize();

			// Calculate the current scale factor being applied by the ScaleBox
			const FVector2D CurrentScale = OriginalScreenSize / OriginalDesiredSize;
			// Get widgets from the Child widget (DraggableBase) instead of

			// @todo why
			const auto TargetIcon = Cast<UImage>(DraggableBase->WidgetTree->FindWidget(TEXT("Icon")));
			const auto TargetIconSize = Cast<USizeBox>(DraggableBase->WidgetTree->FindWidget(TEXT("IconSize")));

			if (TargetIcon && TargetIconSize)
			{
				DragWidget->RemoveFromParent();
				DragWidget->DragIcon->SetBrush(TargetIcon->GetBrush());
				DragWidget->DragIconSize->SetWidthOverride(TargetIconSize->GetWidthOverride());
				DragWidget->DragIconSize->SetHeightOverride(TargetIconSize->GetHeightOverride());

				// Calculate the offset between click and icon position
				const FVector2D MouseScreenPos = InMouseEvent.GetScreenSpacePosition();
				const FVector2D IconScreenPos = ItemWidget->GetCachedGeometry().GetAbsolutePosition();
				const FVector2D ClickOffset = MouseScreenPos - IconScreenPos;
				DragWidget->SetPositionInViewport(MouseScreenPos);

				// Apply position with the offset
				const FVector2D AdjustedPos = MouseScreenPos - ClickOffset;
				DragWidget->SetRenderScale(CurrentScale - 1);
				DragWidget->SetRenderTranslation(AdjustedPos);

				OutOperation->DefaultDragVisual = DragWidget;
				OutOperation->Pivot = EDragPivot::MouseDown;
				if (const auto* ProxyHolder = Cast<UDemoProxyHolder>(ItemWidget))
				{
					OutDDO->Proxy = ProxyHolder->Proxy;
				}
			}
		}
	}
	Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);
}