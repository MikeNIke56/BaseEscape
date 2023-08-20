// Fill out your copyright notice in the Description page of Project Settings.


#include "PlayerChar.h"
#include "Kismet/GameplayStatics.h"
#include "WeaponsBase.h"


// Sets default values for this component's properties
UPlayerChar::UPlayerChar()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;
	//health = maxHealth;

	// ...
}


// Called when the game starts
void UPlayerChar::BeginPlay()
{
	Super::BeginPlay();

	GetWeapon();

	// ...
	
}


// Called every frame
void UPlayerChar::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UPlayerChar::GetWeapon()
{
	FActorSpawnParameters spawnParams;
	spawnParams.bNoFail = true;
	spawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn;

	if(weaponClass)
	{
		FTransform weaponTrans;
		weaponTrans.SetLocation(FVector::ZeroVector);
		weaponTrans.SetRotation(FQuat(FRotator::ZeroRotator));

		weapon = GetWorld()->SpawnActor<AWeaponsBase>(weaponClass, weaponTrans, spawnParams);

		if(weapon)
		{
			weapon->InitWeapon(0);
			weapon->AttachToComponent(GetOwner()->FindComponentByClass<USkeletalMeshComponent>(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("WeaponSocket"));
		}
	}
}

void UPlayerChar::SwitchWeapon()
{
	if(arOut==true)
	{
		weapon->InitWeapon(1);
		arOut = false;
		shotgunOut = true;
	}
	else if(shotgunOut==true)
	{
		weapon->InitWeapon(2);
		arOut = false;
		shotgunOut = false;
	}
	else
	{
		weapon->InitWeapon(0);
		arOut = true;
		shotgunOut = false;
	}

	UGameplayStatics::SpawnSoundAttached(switchWeapSfx, weapon->weaponMesh, TEXT("MuzzleFlashSocket"));
	weapon->AttachToComponent(GetOwner()->FindComponentByClass<USkeletalMeshComponent>(), FAttachmentTransformRules::SnapToTargetNotIncludingScale, FName("WeaponSocket"));
}

void UPlayerChar::Shoot()
{
	weapon->PullTrigger();
}

float UPlayerChar::CalcDamage(AWeaponsBase* Weapon)
{
	if(Weapon->weaponName==FString("Weapon-AR") || Weapon->weaponName==FString("Weapon-Shotgun"))
	{
		return Weapon->weaponDamage;
	}
	return 1.0;
}