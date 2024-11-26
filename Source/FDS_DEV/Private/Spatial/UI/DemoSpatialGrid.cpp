// Copyright Guy (Drakynfly) Lundvall. All Rights Reserved.

#include "Spatial/UI/DemoSpatialGrid.h"

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