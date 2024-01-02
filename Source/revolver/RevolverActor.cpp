// Fill out your copyright notice in the Description page of Project Settings.


#include "RevolverActor.h"

// Sets default values

ARevolverActor::ARevolverActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARevolverActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ARevolverActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ARevolverActor::LineTraceMethod(FHitResult& OutHit)
{
	APlayerCameraManager* OurCamera = UGameplayStatics::GetPlayerCameraManager(this, 0);

	FVector ForwardVector = OurCamera->GetActorForwardVector();
	FVector StartPoint = OurCamera->GetCameraLocation();
	FVector EndPoint = StartPoint + (ForwardVector * m_LinetraceDist);

	FCollisionQueryParams Parameters;

	TArray<AActor*> ActorsToIgnore;

	return UKismetSystemLibrary::LineTraceSingle(this, StartPoint, EndPoint, UEngineTypes::ConvertToTraceType(ECC_Visibility), false, ActorsToIgnore, EDrawDebugTrace::None, OutHit, true);
}
