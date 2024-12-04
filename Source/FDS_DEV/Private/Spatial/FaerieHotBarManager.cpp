// Copyright Guy (Drakynfly) Lundvall. All Rights Reserved.


#include "Spatial/FaerieHotBarManager.h"

void UFaerieHotBarManager::SetSelectedSlot(UFaerieEquipmentSlot* Slot)
{
	if(Slot)
	{
		SelectedSlot = Slot;
	}
	else
	{
		SelectedSlot = nullptr;
	}
	OnSelectedSlotChangedNative.Broadcast();
	OnSelectedSlotChanged.Broadcast();
}

UFaerieEquipmentSlot* UFaerieHotBarManager::GetSelectedSlot() const
{
	return SelectedSlot; 
}