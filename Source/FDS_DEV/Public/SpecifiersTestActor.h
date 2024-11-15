// Copyright Guy (Drakynfly) Lundvall. All Rights Reserved.

#pragma once

#include "Squirrel.h"
#include "GameFramework/Actor.h"
#include "StructUtils/InstancedStruct.h"
#include "SpecifiersTestActor.generated.h"

USTRUCT()
struct FDS_DEV_API FStructToNest
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	FString RandomProperty;

	UPROPERTY(EditAnywhere)
	TArray<TInstancedStruct<FStructToNest>> RecursiveArray;
};

UCLASS()
class FDS_DEV_API ASpecifiersTestActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ASpecifiersTestActor();

/// Unit Testing

	UPROPERTY(EditAnywhere, Category = "Float Units", meta = (Units = Kelvin))
	float KelvenTest;

	UPROPERTY(EditAnywhere, Category = "Float Units", meta = (Units = Celsius))
	float CelciusTest;

	UPROPERTY(EditAnywhere, Category = "Float Units", meta = (Units = Deg))
	float DegreeTest;

	UPROPERTY(EditAnywhere, Category = "Float Units", meta = (Units = km))
	float KilometerTest;

	UPROPERTY(EditAnywhere, Category = "Float Units", meta = (Units = m))
	float MeterTest;

	UPROPERTY(EditAnywhere, Category = "Float Units", meta = (Units = cm))
	float CentimeterTest;

	UPROPERTY(EditAnywhere, Category = "Float Units", meta = (Units = mm))
	float MilimeterTest;


/// Options dropdown

	UPROPERTY(EditAnywhere, Category = "OptionsTest", meta = (GetOptions = GetNameOptions))
	FName OptionedName;

	UPROPERTY(EditAnywhere, Category = "OptionsTest", meta = (GetOptions = GetStringOptions))
	FString OptionedString;

	UPROPERTY(EditAnywhere, Category = "OptionsTest", meta = (GetOptions = GetTextOptions))
	FText OptionedText;

	UPROPERTY(EditAnywhere)
	TArray<FName> NameOptions;

	UPROPERTY(EditAnywhere)
	TArray<FString> StringOptions;

	UPROPERTY(EditAnywhere)
	TArray<FText> TextOptions;

	UFUNCTION()
	TArray<FName> GetNameOptions() const
	{
		return NameOptions;
	}

	UFUNCTION()
	TArray<FString> GetStringOptions() const
	{
		return StringOptions;
	}

	UFUNCTION()
	TArray<FText> GetTextOptions() const
	{
		return TextOptions;
	}

	UPROPERTY(EditAnywhere)
	FStructToNest NestingTest;

/// Enum Arrays

	UPROPERTY(EditAnywhere, Category = "Enum Arrays")
	float ArrayOfEnum[EPhysicalMaterialMaskColor::MAX];

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Squirrel", Instanced)
	TObjectPtr<USquirrel> ReadOnlySquirrel;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Squirrel", Instanced)
	TObjectPtr<USquirrel> ReadWriteSquirrel;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Squirrel", meta = (ShowInnerProperties))
	TObjectPtr<USquirrel> ReadOnlySquirrelInner;

	UPROPERTY(BlueprintReadOnly, EditAnywhere, Category = "Squirrel", meta = (ShowInnerProperties))
	TObjectPtr<USquirrel> ReadWriteSquirrelInner;

	UPROPERTY(BlueprintReadOnly, VisibleDefaultsOnly, Category = "Squirrel", meta = (ShowInnerProperties))
	TObjectPtr<USquirrel> ReadOnlySquirrel_Def;

	UPROPERTY(BlueprintReadWrite, VisibleInstanceOnly, Category = "Squirrel", meta = (ShowInnerProperties))
	TObjectPtr<USquirrel> ReadWriteSquirrel_Def;

	UPROPERTY(BlueprintReadOnly, VisibleAnywhere, Category = "Squirrel", meta = (ShowInnerProperties))
	TObjectPtr<USquirrel> ReadOnlySquirrelInner_Def;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Squirrel", meta = (ShowInnerProperties))
	TObjectPtr<USquirrel> ReadWriteSquirrelInner_Def;
};