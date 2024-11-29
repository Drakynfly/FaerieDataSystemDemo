// Copyright Guy (Drakynfly) Lundvall. All Rights Reserved.


#include "Spatial/Extensions/DemoHotBarExtension.h"

void UDemoHotBarExtension::InitializeExtension(const UFaerieItemContainerBase* Container)
{
	Super::InitializeExtension(Container);
}

void UDemoHotBarExtension::DeinitializeExtension(const UFaerieItemContainerBase* Container)
{
	Super::DeinitializeExtension(Container);
}

void UDemoHotBarExtension::SetSelectedSlot(UFaerieEquipmentSlot* Slot)
{
	if(Slot)
	{
		SelectedSlot = Slot;
	} else {
		SelectedSlot = nullptr;
	}
	OnSelectedItemChanged.Broadcast();
}

UFaerieEquipmentSlot* UDemoHotBarExtension::GetSelectedSlot() const
{
	return SelectedSlot; 
}
