// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "GameOfLife.h"
#include "Modules/ModuleManager.h"

IMPLEMENT_PRIMARY_GAME_MODULE(FDefaultGameModuleImpl, GameOfLife, "GameOfLife");

DEFINE_LOG_CATEGORY(LogGameOfLife);
DEFINE_LOG_CATEGORY(LogOrganisms);
DEFINE_LOG_CATEGORY(LogPositionUpdater);
