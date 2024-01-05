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
	CoinRotation(DeltaTime);

}

// Called to bind functionality to input
void ACoinActor::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

USceneComponent* ACoinActor::ClosestEnemyMethod()
{
	TSubclassOf<AActor> ClassToFind;
	TArray<AActor*> FoundActors;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), ClassToFind, FoundActors);

	for (int i = 0; i < FoundActors.Num(); i++)
	{
		FVector coinLoc = this->GetActorLocation();
		FVector EnemyLoc = FoundActors[i]->GetActorLocation();

		FVector vecSubtract = coinLock - EnemyLoc;
		float vecLength = FVector::Length(vecSubtract);

		if (vecLength < m_ClosestDistance)
		{
			m_ClosestDistance = vecLength;
			AActor* m_CurrHomingTarget = FoundActors[i];
		}
	}
	m_HomingTargetComponent = m_CurrHomingTarget->FindComponentByClass<USceneComponent*>;

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

void ACoinActor::HomingCoinMethod(AActor* CurrHomingTarget)
{
	//ProjectileMovement->HomingTargetComponent = 
	ProjectileMovement->bIsHomingProjectile = true;
	ProjectileMovement->HomingAccelerationMagnitude = 9999999999999999999.f;
}
