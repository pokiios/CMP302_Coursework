// Fill out your copyright notice in the Description page of Project Settings.

#include "CoinActor.h"

// Sets default values
ACoinActor::ACoinActor()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	m_DamageMultiplier = 2.f;
	m_ProjectileMovement->InitialSpeed = 3000.f;
	m_ProjectileMovement->MaxSpeed = 3500.f;
	m_ProjectileMovement->Velocity = { 1.f, 0.f, 0.f };
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
	CoinRotationMethod(DeltaTime);

}

// Called to bind functionality to input
void ACoinActor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

USceneComponent* ACoinActor::ClosestEnemyMethod()
{
	TArray<AActor*> FoundActors;


	UGameplayStatics::GetAllActorsOfClass(GetWorld(), AEnemyActor::StaticClass(), FoundActors);

	for (int i = 0; i < FoundActors.Num(); i++)
	{
		FVector coinLoc = this->GetActorLocation();
		FVector EnemyLoc = FoundActors[i]->GetActorLocation();

		float Dist = FVector::Distance(coinLoc, EnemyLoc);

		if (Dist < m_ClosestDistance)
		{
			m_ClosestDistance = Dist;
			m_CurrHomingTarget = FoundActors[i];
		}
	}
	m_HomingTargetComponent = m_CurrHomingTarget->GetComponentByClass<USceneComponent>();

	return m_HomingTargetComponent;
}

void ACoinActor::SetCoinDamageMethod()
{
	m_CoinDamage *= m_DamageMultiplier;
}

void ACoinActor::CoinRotationMethod(float DeltaTime)
{
	float m_CurrRotation = DeltaTime * m_Rotation;
	FRotator m_newRotator = FRotator::ZeroRotator;

	m_newRotator.Yaw = m_CurrRotation;
	m_newRotator.Pitch = m_CurrRotation;

	this->AddActorLocalRotation(m_newRotator, false);
}

void ACoinActor::HomingCoinMethod(USceneComponent* CurrHomingTarget)
{
	m_ProjectileMovement->HomingTargetComponent = CurrHomingTarget;
	m_ProjectileMovement->bIsHomingProjectile = true;
	m_ProjectileMovement->HomingAccelerationMagnitude = 99999999999999.f;
}
