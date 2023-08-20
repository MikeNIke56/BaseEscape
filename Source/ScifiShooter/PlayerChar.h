// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerChar.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class SCIFISHOOTER_API UPlayerChar : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UPlayerChar();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;

	UFUNCTION(BlueprintCallable)
	void GetWeapon();
	UFUNCTION(BlueprintCallable)
	void SwitchWeapon();
	UFUNCTION(BlueprintCallable)
	void Shoot();
	UFUNCTION(BlueprintCallable)
	float CalcDamage(AWeaponsBase* Weapon);

protected:

	UPROPERTY(EditAnywhere)
	TSubclassOf<class AWeaponsBase> weaponClass;
	UPROPERTY(VisibleAnywhere)
	bool arOut = true;
	UPROPERTY(VisibleAnywhere)
	bool shotgunOut = false;
	UPROPERTY(EditAnywhere)
	USoundBase* switchWeapSfx;

	class AWeaponsBase* weapon;
		
};
