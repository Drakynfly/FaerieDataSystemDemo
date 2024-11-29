// Copyright Guy (Drakynfly) Lundvall. All Rights Reserved.

#pragma once

#include "FaerieEquipmentManager.h"
#include "FaerieHotBarManager.generated.h"

using FOnSelectedSlotChangedNative = TMulticastDelegate<void()>;
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSelectedSlotChanged);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class FDS_DEV_API UFaerieHotBarManager : public UFaerieEquipmentManager
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "HotBarManager")
	void SetSelectedSlot(UFaerieEquipmentSlot* Slot);

	UFUNCTION(BlueprintCallable, Category = "HotBarManager")
	UFaerieEquipmentSlot* GetSelectedSlot() const;

	UPROPERTY(BlueprintAssignable, Category = "HotBarManager")
	FOnSelectedSlotChanged OnSelectedSlotChanged;

private:
	TObjectPtr<UFaerieEquipmentSlot> SelectedSlot;

	FOnSelectedSlotChangedNative OnSelectedSlotChangedNative;
};
