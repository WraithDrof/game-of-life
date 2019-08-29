// Fill out your copyright notice in the Description page of Project Settings.

#include "Organism.h"
#include "Components/StaticMeshComponent.h"
#include "GameOfLife.h"
#include <cmath>

// Sets default values
AOrganism::AOrganism()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
}

// Called when the game starts or when spawned
void AOrganism::BeginPlay()
{
	Super::BeginPlay();
	SetToAppear();
}

// Called every frame
void AOrganism::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	// This could eventually take in DeltaTime to make it independent of framerate but as an
	// animation, it's less important.
	currentScale = (currentScale + 0.1 * (targetScale - currentScale));
	AActor::SetActorScale3D(FVector(this->currentScale, this->currentScale, this->currentScale));
}

void AOrganism::SetToAppear()
{
	if (currentScale != 0)
	{
		UE_LOG(LogGameOfLife, Warning, TEXT("Setting the organism to appear when it has already appeared, \
			but this is intended to only be called once after it's been initialised. \
			Proceeding anyways, will grow whatever the current scale is to the target scale."));
	}

	targetScale = 1;
}
