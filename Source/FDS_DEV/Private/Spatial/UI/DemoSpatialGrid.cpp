// Copyright Guy (Drakynfly) Lundvall. All Rights Reserved.


#include "Spatial/UI/DemoSpatialGrid.h"

#include "DemoProxyHolder.h"
#include "InventoryStorageProxy.h"
#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanel.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/PanelWidget.h"
#include "Components/UniformGridPanel.h"
#include "Components/UniformGridSlot.h"
#include "Spatial/UI/DemoDraggableBase.h"
#include "Spatial/UI/DemoSpatialDDO.h"

UWidget* UDemoSpatialGrid::GetChildUnderCursor(const FVector2D AbsolutePosition, UPanelWidget* InPanel)
{
	for (auto& Child : InPanel->GetAllChildren())
	{
		if (Child->GetCachedGeometry().IsUnderLocation(AbsolutePosition))
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
    
	// Iterate through children of GridPanel
	for (auto& Child : GridPanel->GetAllChildren())
	{
		if (Child->GetCachedGeometry().IsUnderLocation(ScreenSpacePosition))
		{
			if(const auto* GridSlot = Cast<UUniformGridSlot>(Child->Slot))
			{
				OutDDO->SourcePoint = FIntPoint(GridSlot->GetColumn(), GridSlot->GetRow());
				OutDDO->Payload = Child;
			}
			break;
		}
	}
	
	for (auto& Child : IconPanel->GetAllChildren())
	{
		if (Child->GetCachedGeometry().IsUnderLocation(ScreenSpacePosition))
		{
			auto DragWidget = CreateWidget<UDemoDraggableBase>(GetOwningPlayer(), UDemoDraggableBase::StaticClass());
			if (auto* DraggableBase = Cast<UUserWidget>(Child))
			{
				// Get the original widget's absolute size in screen space
				FVector2D OriginalScreenSize = Child->GetCachedGeometry().GetAbsoluteSize();
            
				// Get the original widget's desired size
				FVector2D OriginalDesiredSize = Child->GetDesiredSize();
            
				// Calculate the current scale factor being applied by the ScaleBox
				FVector2D CurrentScale = OriginalScreenSize / OriginalDesiredSize;
				// Get widgets from the Child widget (DraggableBase) instead of IconPanel
				auto TargetIcon = Cast<UImage>(DraggableBase->WidgetTree->FindWidget(TEXT("Icon")));
				auto TargetIconSize = Cast<USizeBox>(DraggableBase->WidgetTree->FindWidget(TEXT("IconSize")));
               
				if (TargetIcon && TargetIconSize)
				{
					DragWidget->RemoveFromParent();
					DragWidget->DragIcon->SetBrush(TargetIcon->GetBrush());
					DragWidget->DragIconSize->SetWidthOverride(TargetIconSize->GetWidthOverride());
					DragWidget->DragIconSize->SetHeightOverride(TargetIconSize->GetHeightOverride());
             
					// Calculate the offset between click and icon position
					const FVector2D MouseScreenPos = InMouseEvent.GetScreenSpacePosition();
					const FVector2D IconScreenPos = Child->GetCachedGeometry().GetAbsolutePosition();
					const FVector2D ClickOffset = MouseScreenPos - IconScreenPos;
					DragWidget->SetPositionInViewport(MouseScreenPos);

					// Apply position with the offset 
					const FVector2D AdjustedPos = MouseScreenPos - ClickOffset;
					DragWidget->SetRenderScale(CurrentScale - 1);
					DragWidget->SetRenderTranslation(AdjustedPos);
             
					OutOperation->DefaultDragVisual = DragWidget;
					OutOperation->Pivot = EDragPivot::MouseDown;
					if(auto* ProxyHolder = Cast<UDemoProxyHolder>(Child))
					{
						OutDDO->Proxy = ProxyHolder->Proxy;
					}
				}
			}
			break;
		}
	}
	Super::NativeOnDragDetected(InGeometry, InMouseEvent, OutOperation);
}
