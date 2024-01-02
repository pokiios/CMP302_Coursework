// Fill out your copyright notice in the Description page of Project Settings.

#include "CoinActor.h"

// Sets default values
ACoinActor::ACoinActor()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ACoinActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ACoinActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ACoinActor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void ACoinActor::MoveCoinToEnemy(USkeletalMeshComponent* SkeletalMesh, FVector Impulse)
{
	FVector CoinVel = GetVelocity();
	FVector CoinImpulse = CoinVel * CoinImpulse;

	//UPrimitiveComponent::AddImpulse(CoinImpulse);
}
