

#pragma once

#include "CoreMinimal.h"

/**
 *
 */
class GAMEOFLIFE_API FPositionUpdater
{
public:
	FPositionUpdater(int survivalMinimum, int survivalMaximum);
	~FPositionUpdater();

	TArray<FVector2D> GetNextPositionUpdate(TArray<FVector2D> previousCells);

private:
	// Parameters
	int AreaWidth;
	int AreaHeight;
	int SurvivalMinimum; // The minimum number of neighbours a live cell can have before it dies.
	int SurvivalMaximum; // The maximum number of neighbours a live cell can have before it dies.

	TArray<FVector2D> GetSurvivingLiveCells(TArray<FVector2D> previousCells);
	TArray<FVector2D> GetNewCells(TArray<FVector2D> previousCells);

	bool GetIfShouldBeAlive(FVector2D cell, TArray<FVector2D> previousCells);
	bool GetIfDeadCellShouldBeAlive(FVector2D, TArray<FVector2D> previousCells);
	bool GetIfAliveCellShouldBeAlive(FVector2D, TArray<FVector2D> previousCells);
	int GetNeighboursAtCoordinate(FVector2D coordinate, TArray<FVector2D> previousCells);
};
