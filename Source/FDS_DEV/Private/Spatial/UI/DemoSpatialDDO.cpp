// Copyright Guy (Drakynfly) Lundvall. All Rights Reserved.


#include "Spatial/UI/DemoSpatialDDO.h"

#include "Components/Widget.h"
#include "Spatial/UI/DemoDraggableBase.h"

void UDemoSpatialDDO::Dragged_Implementation(const FPointerEvent& PointerEvent)
{
	{
		if (DefaultDragVisual)
		{
			Cast<UDemoDraggableBase>(DefaultDragVisual)->SetPositionInViewport(
				PointerEvent.GetScreenSpacePosition(),
				false // don't animate
			);
		}
	}
}
