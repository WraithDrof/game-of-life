// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "GameOfLifeCharacter.h"
#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "OrganismPosition.h"
#include "OrganismManagement/PositionUpdater.h"
#include "GameOfLifePlayerController.generated.h"

UCLASS()
class AGameOfLifePlayerController : public APlayerController
{
	GENERATED_BODY()

public:
	AGameOfLifePlayerController();

protected:
	/** True if the controlled character should navigate to the mouse cursor. */
	uint32 bMoveToMouseCursor : 1;
	FPositionUpdater* TestPositionUpdater;

	TArray<OrganismPosition> LastUpdatedPositions;

	// Begin PlayerController interface
	virtual void PlayerTick(float DeltaTime) override;
	virtual void SetupInputComponent() override;
	// End PlayerController interface

	/** Resets HMD orientation in VR. */
	void OnResetVR();

	AGameOfLifeCharacter* GetGameOfLifeCharacterWithCursor();

	/** Navigate player to the current mouse cursor location. */
	void MoveToMouseCursor();

	/** Navigate player to the current touch location. */
	void MoveToTouchLocation(const ETouchIndex::Type FingerIndex, const FVector Location);

	/** Navigate player to the given world location. */
	void SetNewMoveDestination(const FVector DestLocation);

	/** Input handlers for SetDestination action. */
	void OnSetDestinationPressed();
	void OnSetDestinationReleased();

	/** Input handler for spawning organisms */
	void SpawnOrganismAtMouse();
};


