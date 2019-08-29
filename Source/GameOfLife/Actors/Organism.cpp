// Fill out your copyright notice in the Description page of Project Settings.

#include "Organism.h"
#include "Components/StaticMeshComponent.h"

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
	this->currentScale = 1;
}

// Called every frame
void AOrganism::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	UE_LOG(LogTemp, Warning, TEXT("Tick"));
	this->currentScale *= 0.9;
	AActor::SetActorScale3D(FVector(this->currentScale, this->currentScale, this->currentScale));
}

