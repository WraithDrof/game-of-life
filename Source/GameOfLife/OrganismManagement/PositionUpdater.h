

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

	TArray<FVector2D> GetNextPositionUpdate(const TArray<FVector2D> previousCells);

private:
	// Parameters
	int AreaWidth;
	int AreaHeight;
	int SurvivalMinimum; // The minimum number of neighbours a live cell can have before it dies.
	int SurvivalMaximum; // The maximum number of neighbours a live cell can have before it dies.

	TArray<FVector2D> GetSurvivingLiveCells(const TArray<FVector2D> previousCells);
	TArray<FVector2D> GetNewCells(const TArray<FVector2D> previousCells);

	bool GetIfShouldBeAlive(const FVector2D cell, const TArray<FVector2D> previousCells);
	bool GetIfDeadCellShouldBeAlive(const FVector2D, const TArray<FVector2D> previousCells);
	bool GetIfAliveCellShouldBeAlive(const FVector2D, const TArray<FVector2D> previousCells);
	int GetNeighboursAtCoordinate(const FVector2D coordinate);
};
