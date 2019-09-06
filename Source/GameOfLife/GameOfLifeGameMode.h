// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "GameOfLifeGameMode.generated.h"

UCLASS(minimalapi)
class AGameOfLifeGameMode : public AGameModeBase
{
	GENERATED_BODY()

public:
	AGameOfLifeGameMode();

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
		class UCameraComponent* TopDownCameraComponent;
};



