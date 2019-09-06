// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "GameOfLifeGameMode.h"
#include "GameOfLifePlayerController.h"
#include "GameOfLifeCharacter.h"
#include "UObject/ConstructorHelpers.h"
#include "Engine/World.h"
#include "Actors/Organism.h"

AGameOfLifeGameMode::AGameOfLifeGameMode()
{
	// use our custom PlayerController class
	PlayerControllerClass = AGameOfLifePlayerController::StaticClass();

	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(
		TEXT("/Game/TopDownCPP/Blueprints/TopDownCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}