// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Particles/ParticleSystemComponent.h"
#include "EnemyActor.h"
#include "Math/Vector.h"
#include "CoinActor.generated.h"

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class REVOLVER_API ACoinActor : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ACoinActor();


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Blueprintable)
		float m_ClosestDistance;

	UPROPERTY(EditAnywhere, Blueprintable)
		float m_CoinDamage;

	UPROPERTY(EditAnywhere, Blueprintable)
		float m_DamageMultiplier;

	UPROPERTY(EditAnywhere, Blueprintable)
		float m_Rotation;

	UPROPERTY(VisibileAnywhere, Category = Movement)
		UProjectileMovementComponent* ProjectileMovement;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
		AActor* ClosestEnemy();

	UFUNCTION(BlueprintCallable)
		void SetCoinDamage();

	UFUNCTION(BlueprintCallable)
		void CoinHoming(AActor* CurrHomingTarget);

	UFUNCTION(BlueprintCallable)
		void CoinRotation(float deltaTime);

	UFUNCTION(BlueprintCallable)
		void ApplyDamage(AActor* DamagedActor);
};
