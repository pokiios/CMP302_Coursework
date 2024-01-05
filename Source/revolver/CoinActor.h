// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Kismet/GameplayStatics.h"
#include "GameFramework/ProjectileMovementComponent.h"
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

	UPROPERTY(VisibleAnywhere, Category = "Movement")
		UProjectileMovementComponent* m_ProjectileMovement;

	UPROPERTY(VisibleAnywhere, Category = "Components")
		USceneComponent* m_HomingTargetComponent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
		USceneComponent* ClosestEnemyMethod();

	UFUNCTION(BlueprintCallable)
		void SetCoinDamageMethod();

	UFUNCTION(BlueprintCallable)
		void HomingCoinMethod(AActor* CurrHomingTarget);

	UFUNCTION(BlueprintCallable)
		void CoinRotationMethod(float deltaTime);

	/*UFUNCTION(BlueprintCallable)
		void ApplyCoinDamage(AActor* DamagedActor);*/
};
