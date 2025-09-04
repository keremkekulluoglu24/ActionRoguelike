// Fill out your copyright notice in the Description page of Project Settings.


#include "SPowerupActor.h"
#include "Components/SphereComponent.h"


// Sets default values
ASPowerupActor::ASPowerupActor()
{
	SphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp");
	SphereComp->SetCollisionProfileName("Powerup");
	RootComponent = SphereComp;

	RespawnTime = 10.0f;
}


void ASPowerupActor::Interact_Implementation(APawn* InstigatorPawn)
{
	// logic in derived classes...
	UE_LOG(LogTemp, Log, TEXT("logic in derived classes..."));

}

void ASPowerupActor::ShowPowerup()
{
	SetPowerupState(true);
	UE_LOG(LogTemp, Log, TEXT("SetPowerupState(true);"));

}

void ASPowerupActor::HideAndCooldownPowerup()
{
	SetPowerupState(false);

	GetWorldTimerManager().SetTimer(TimerHandle_RespawnTimer, this, &ASPowerupActor::ShowPowerup, RespawnTime);

	UE_LOG(LogTemp, Log, TEXT("HideAndCooldownPowerup COMPLETED!"));

}

void ASPowerupActor::SetPowerupState(bool bNewIsActive)
{
	SetActorEnableCollision(bNewIsActive);

	// Set visibility on root and all children
	RootComponent->SetVisibility(bNewIsActive, true);
	UE_LOG(LogTemp, Log, TEXT("SetVisibility!"));

}