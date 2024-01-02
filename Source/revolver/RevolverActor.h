// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Kismet/GameplayStatics.h"
#include "Kismet/KismetSystemLibrary.h"
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RevolverActor.generated.h"


UCLASS(ClassGroup = (custom), meta=(BlueprintSpawnableComponent), Blueprintable)
class REVOLVER_API ARevolverActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARevolverActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	UPROPERTY(EditAnywhere, Blueprintable)
		float m_LinetraceDist;

	UPROPERTY(EditAnywhere, Blueprintable)
		FVector m_ProjectileOffset;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable)
		void Shoot();

	UFUNCTION(BlueprintCallable)
		bool LineTraceMethod(FHitResult& OutHit);

};
