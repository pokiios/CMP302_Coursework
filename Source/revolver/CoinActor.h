// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
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
		float m_CoinHealth;

	UPROPERTY(EditAnywhere, Blueprintable)
		int m_ClosestIndex;

	UPROPERTY(EditAnywhere, Blueprintable)
		float m_CoinDamage;

	UPROPERTY(EditAnywhere, Blueprintable)
		float m_DamageMultiplier;

	UPROPERTY(EditAnywhere, Blueprintable)
		FRotator m_CurrRotation;

	UPROPERTY(EditAnywhere, Blueprintable)
		FRotator m_TargetRotation;

	UPROPERTY(EditAnywhere, Blueprintable)
		FVector RotationVec;

	UPROPERTY(EditAnywhere, Blueprintable)
		TArray<AActor*> m_OutActors;

	UPROPERTY(EditAnywhere, BluePrintable)
		AActor* CoinRef;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
		void MoveCoinToEnemy(USkeletalMeshComponent* SkeletalMesh, FVector Impulse);
};
