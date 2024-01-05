// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "EnemyActor.generated.h"

UCLASS(ClassGroup=(Custom), meta = (BlueprintSpawnableComponent), Blueprintable)
class REVOLVER_API AEnemyActor : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AEnemyActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(EditAnywhere, Blueprintable)
		float m_EnemyHealth;

	UPROPERTY(EditAnywhere, Blueprintable)
		float m_RoamRadius;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
