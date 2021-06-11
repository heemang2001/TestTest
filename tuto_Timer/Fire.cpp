// Fill out your copyright notice in the Description page of Project Settings.


#include "Fire.h"

// Sets default values
AFire::AFire()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	FireParticle = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("Fire Particle"));
	RootComponent = FireParticle;

	FireTime = 5;
}

// Called when the game starts or when spawned
void AFire::BeginPlay()
{
	Super::BeginPlay();
	
	GetWorldTimerManager().SetTimer(FireTimerHandle, this, &AFire::Combution, 1.0f, true);
}

// Called every frame
void AFire::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFire::Combution()
{
	FireTime--;

	if (FireTime <= 0)
	{
		OffFire();
	}
}

void AFire::OffFire()
{
	GetWorldTimerManager().ClearTimer(FireTimerHandle);
	FireParticle->DeactivateSystem();
}

