// Copyright Guy (Drakynfly) Lundvall. All Rights Reserved.


#include "Spatial/UI/DemoDraggableBase.h"

#include "Blueprint/WidgetTree.h"
#include "Components/CanvasPanelSlot.h"
#include "Components/SizeBoxSlot.h"

void UDemoDraggableBase::NativeOnInitialized()
{
	Super::NativeOnInitialized();
	
	// Always construct new widgets for the drag visual
	DragIcon = WidgetTree->ConstructWidget<UImage>();
	DragIconSize = WidgetTree->ConstructWidget<USizeBox>();
    
	if (DragIcon && DragIconSize)
	{
		// Set up the size box defaults
		DragIconSize->SetWidthOverride(64.0f);
		DragIconSize->SetHeightOverride(64.0f);
        
		// Set up widget hierarchy
		WidgetTree->RootWidget = DragIconSize;
		DragIconSize->AddChild(DragIcon);
        
		// Configure the icon slot
		if (USizeBoxSlot* IconSlot = Cast<USizeBoxSlot>(DragIcon->Slot))
		{
			IconSlot->SetHorizontalAlignment(HAlign_Fill);
			IconSlot->SetVerticalAlignment(VAlign_Fill);
		}
        
		// Force properties to update
		DragIconSize->SynchronizeProperties();
	}
}

void UDemoDraggableBase::NativeConstruct()
{
	Super::NativeConstruct();
}

// Add this function to update the widget when DragIcon and DragIconSize are set
void UDemoDraggableBase::UpdateDragVisual() const
{
	if (DragIcon && DragIconSize)
	{
		// Update the root widget
		WidgetTree->RootWidget = DragIconSize;
        
		// Set up the visual hierarchy
		if (DragIcon->GetParent())
		{
			DragIcon->RemoveFromParent();
		}
        
		DragIconSize->AddChild(DragIcon);
        
		if (USizeBoxSlot* IconSlot = Cast<USizeBoxSlot>(DragIcon->Slot))
		{
			IconSlot->SetHorizontalAlignment(HAlign_Fill);
			IconSlot->SetVerticalAlignment(VAlign_Fill);
		}
		
		DragIconSize->SynchronizeProperties();
	}
}
