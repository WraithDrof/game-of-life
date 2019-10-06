#pragma once

#include "CoreMinimal.h"
#include "OrganismPosition.h"

/**
 *
 */
class GAMEOFLIFE_API FPositionUpdater
{
public:
	FPositionUpdater(int survivalMinimum, int survivalMaximum, int repopulationTarget);
	~FPositionUpdater();

	TArray<OrganismPosition> GetNextPositionUpdate(TArray<OrganismPosition> previousCells);

private:
	// Parameters
	int AreaWidth;
	int AreaHeight;
	int SurvivalMinimum; // The minimum number of neighbours a live cell can have before it dies.
	int SurvivalMaximum; // The maximum number of neighbours a live cell can have before it dies.
	int RepopulationTarget; // The exact number of neighbours a dead cell must have for it to repopulate.

	TArray<OrganismPosition> GetSurvivingLiveCells(TArray<OrganismPosition> previousCells);

	TArray<OrganismPosition> GetNewCells(TArray<OrganismPosition> survivingCells);
	TArray<OrganismPosition> GetAdjacentDeadCells(TArray<OrganismPosition> survivingCells);

	// Used by both
	TArray<OrganismPosition> GetCellsWithNeighbourRange(
		TArray<OrganismPosition> cells,
		int minNeighbours,
		int maxNeighbours
	);
	int GetNeighboursAtCoordinate(OrganismPosition coordinate, TArray<OrganismPosition> currentCells);
};
