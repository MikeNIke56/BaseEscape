// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/DataTable.h"
#include "WeaponsBase.generated.h"

USTRUCT (BlueprintType)
struct FWeaponData : public FTableRowBase
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere)
	class USkeletalMesh* weaponMeshS;
	UPROPERTY(EditAnywhere)
	FString weaponName;
};

UCLASS()
class SCIFISHOOTER_API AWeaponsBase : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWeaponsBase();

	class USkeletalMeshComponent* weaponMesh;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere)
	class UDataTable* weaponDT;

	FWeaponData* weaponData;

public:
	UPROPERTY(VisibleAnywhere)
	FString weaponName;

	void InitWeapon(int32 num);

	UFUNCTION(BluePrintCallable)
	void PullTrigger();

	UPROPERTY(EditAnywhere)
	UParticleSystem* arMuzzleFlash;
	UPROPERTY(EditAnywhere)
	UParticleSystem* shotgunMuzzleFlash;

	UPROPERTY(EditAnywhere)
	float maxRange = 1000;

	UPROPERTY(EditAnywhere)
	float weaponDamage = 10;
	

};
