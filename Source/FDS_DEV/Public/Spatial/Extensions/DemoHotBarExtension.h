// Copyright Guy (Drakynfly) Lundvall. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "ItemContainerExtensionBase.h"
#include "DemoHotBarExtension.generated.h"

class UFaerieEquipmentSlot;
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnSelectedItemChanged);

/**
 * 
 */
UCLASS()
class FDS_DEV_API UDemoHotBarExtension : public UItemContainerExtensionBase
{
	GENERATED_BODY()

protected:
	virtual void InitializeExtension(const UFaerieItemContainerBase* Container) override;
	virtual void DeinitializeExtension(const UFaerieItemContainerBase* Container) override;

	UFUNCTION(BlueprintCallable, Category = "HotBarManager")
	void SetSelectedSlot(UFaerieEquipmentSlot* Slot);

	UFUNCTION(BlueprintCallable, Category = "HotBarManager")
	UFaerieEquipmentSlot* GetSelectedSlot() const;

	UPROPERTY(BlueprintAssignable, Category = "HotBarManager")
	FOnSelectedItemChanged OnSelectedItemChanged;

private:
	TObjectPtr<UFaerieEquipmentSlot> SelectedSlot;
};
