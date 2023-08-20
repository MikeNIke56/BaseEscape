// Fill out your copyright notice in the Description page of Project Settings.


#include "WeaponsBase.h"
#include "Components/SkeletalMeshComponent.h"
#include "Kismet/GameplayStatics.h"
#include "DrawDebugHelpers.h"

// Sets default values
AWeaponsBase::AWeaponsBase()
{
 	weaponMesh = CreateDefaultSubobject<USkeletalMeshComponent>("SkeletalMeshComponent");
	RootComponent = weaponMesh;

}

// Called when the game starts or when spawned
void AWeaponsBase::BeginPlay()
{
	Super::BeginPlay();

	
}

void AWeaponsBase::InitWeapon(int32 num)
{
	if(weaponDT)
	{		
		switch(num) 
		{
			case 0:
				weaponName = FString("Weapon-AR");
				weaponData = weaponDT->FindRow<FWeaponData>(FName("AR"), weaponName, true);
				weaponDamage = 3;
				if(weaponData)
				{
					weaponMesh->SetSkeletalMesh(weaponData->weaponMeshS);
				}
				break;
			case 1:
				weaponName = FString("Weapon-Shotgun");
				weaponData = weaponDT->FindRow<FWeaponData>(FName("Shotgun"), weaponName, true);
				weaponDamage = 20;
				if(weaponData)
				{
					weaponMesh->SetSkeletalMesh(weaponData->weaponMeshS);
				}
				break;
			case 2:
				weaponName = FString("Weapon-Launcher");
				weaponData = weaponDT->FindRow<FWeaponData>(FName("Launcher"), weaponName, true);
				weaponDamage = 20;
				if(weaponData)
				{
					weaponMesh->SetSkeletalMesh(weaponData->weaponMeshS);
				}
				break;
			default:
				weaponName = FString("Weapon-DT");
				weaponData = weaponDT->FindRow<FWeaponData>(FName("AR"), weaponName, true);
				weaponDamage = 20;
				if(weaponData)
				{
					weaponMesh->SetSkeletalMesh(weaponData->weaponMeshS);
				}
		}
	}
}

void AWeaponsBase::PullTrigger()
{
	if(weaponName==FString("Weapon-AR"))
		UGameplayStatics::SpawnEmitterAttached(arMuzzleFlash, weaponMesh, TEXT("MuzzleFlashSocket"));

	APawn* ownerPawn = Cast<APawn>(GetOwner());
	if(ownerPawn==nullptr) return;

	AController* ownerCont = ownerPawn->GetController();
	if(ownerCont==nullptr) return;

}