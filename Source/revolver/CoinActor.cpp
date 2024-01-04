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


AActor* ACoinActor::ClosestEnemy()
{
	// Array Variables
	TArray<AActor*> OutActor;
	TSubclassOf<AActor> EnemyClass;

	m_ClosestDistance = 9999999.f;

	UGameplayStatics::GetAllActorsOfClass(GetWorld(), EnemyClass, OutActor);
	for (int i = 0; i < OutActor.Num(); i++)
	{
		FVector m_CoinLocation = this->GetActorLocation();
		FVector m_EnemyLocation = OutActor[i]->GetActorLocation();

		FVector m_EnemyDistance = m_CoinLocation - m_EnemyLocation;
		float m_EnemyDistanceFloat = FVector::Length(m_EnemyDistance);

		if (m_EnemyDistanceFloat < m_ClosestDistance)
		{
			m_ClosestDistance = m_EnemyDistanceFloat;
		}
	}
}

void ACoinActor::SetCoinDamage()
{
	m_CoinDamage *= m_DamageMultiplier;
}

void ACoinActor::CoinRotation(float DeltaTime)
{
	float m_CurrRotation = DeltaTime * m_Rotation;
	FRotator m_newRotator = FRotator::ZeroRotator;

	m_newRotator.Yaw = m_CurrRotation;
	m_newRotator.Pitch = m_CurrRotation;

	this->AddActorLocalRotation(m_newRotator, false);
}

void ACoinActor::CoinHoming(AActor* CurrHomingTarget)
{
	//ProjectileMovement->HomingTargetComponent = 
	ProjectileMovement->bIsHomingProjectile = true;
	ProjectileMovement->HomingAccelerationMagnitude = 9999999999999999999.f;
}

void ACoinActor::ApplyCoinDamage(AActor* DamagedActor)
{
	if (ProjectileMovement->bIsHomingProjectile == true && DamagedActor == )
	{
		//UGameplayStatics::SpawnEmitterAtLocation(GetWorld(), )
		UGameplayStatics::ApplyDamage(DamagedActor, m_CoinDamage, NULL, this, NULL);
		Destroy(this);
	}
}