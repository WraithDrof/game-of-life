#include "PositionUpdater.h"
#include "GameOfLife.h"

#define forEachCell(cellArray) for (auto cell : cellArray)

FPositionUpdater::FPositionUpdater(int survivalMinimum, int survivalMaximum, int repopulationTarget)
{
	UE_LOG(
		LogGameOfLife,
		Log,
		TEXT("Creating PositionUpdater with survival bounds as min = [%d], max = [%d], repop = [%d]"),
		survivalMinimum,
		survivalMaximum,
		repopulationTarget);

	SurvivalMinimum = survivalMinimum;
	SurvivalMaximum = survivalMaximum;
	RepopulationTarget = repopulationTarget;
}

FPositionUpdater::~FPositionUpdater()
{
}

TArray<OrganismPosition> FPositionUpdater::GetNextPositionUpdate(TArray<OrganismPosition> previousCells)
{
	TArray<OrganismPosition> nextPositions;

	auto survivors = GetSurvivingLiveCells(previousCells);
	auto newCells = GetNewCells(previousCells);

	nextPositions.Append(survivors);
	nextPositions.Append(newCells);

	UE_LOG(LogGameOfLife, Log, TEXT("Returning next position update:"));
	forEachCell(nextPositions)
	{
		UE_LOG(LogGameOfLife, Log, TEXT("Alive cell: [%s]"), *cell.Position.ToString())
	}
	UE_LOG(LogGameOfLife, Log, TEXT("End returning next position update."));

	return nextPositions;
}

TArray<OrganismPosition> FPositionUpdater::GetSurvivingLiveCells(TArray<OrganismPosition> previousCells)
{
	checkf(
		SurvivalMinimum <= SurvivalMaximum,
		TEXT("SurvivalMinimum is not <= SurvivalMaximum! Cannot calculate surviving cells.")
	);

	return GetCellsWithNeighbourRange(previousCells, SurvivalMinimum, SurvivalMaximum);
}

TArray<OrganismPosition> FPositionUpdater::GetNewCells(TArray<OrganismPosition> survivingCells)
{
	checkf(
		RepopulationTarget >= 0 && RepopulationTarget <= 4,
		TEXT("RepopulationTarget is [%d] which is out of range!"),
		RepopulationTarget
	);
	auto adjacentDeadCells = GetAdjacentDeadCells(survivingCells);
	return GetCellsWithNeighbourRange(adjacentDeadCells, RepopulationTarget, RepopulationTarget);
}

TArray<OrganismPosition> FPositionUpdater::GetAdjacentDeadCells(TArray<OrganismPosition> survivingCells)
{
	// Get dead cells adjacent to previous cells so that we can see if they should be alive.
	TArray<OrganismPosition> adjacentCells;

	forEachCell(survivingCells)
	{
		//TODO: Potentially move cardinal direction calculations to a helper class.
		OrganismPosition neighbours[] =
		{
			OrganismPosition(cell.Position.X, cell.Position.Y - 1), // north
			OrganismPosition(cell.Position.X + 1, cell.Position.Y), // east
			OrganismPosition(cell.Position.X, cell.Position.Y + 1), // south
			OrganismPosition(cell.Position.X - 1, cell.Position.Y) // west
		};

		// For each neighbour...
		for (int i = 0; i < 4; i++)
		{
			// Add to the adjacent cells if it hasn't already, and isn't already a part of the
			// surviving cells.
			if (!adjacentCells.Contains(neighbours[i]) && !survivingCells.Contains(neighbours[i]))
			{
				adjacentCells.Add(neighbours[i]);
			}
		}
	}

	return adjacentCells;
}

TArray<OrganismPosition> FPositionUpdater::GetCellsWithNeighbourRange(TArray<OrganismPosition> cells, int minNeighbours, int maxNeighbours)
{
	TArray<OrganismPosition> cellsInRange;

	forEachCell(cells)
	{
		auto neighbourCount = GetNeighboursAtCoordinate(cell, cells);
		auto inRange = neighbourCount >= minNeighbours && neighbourCount <= maxNeighbours;
		if (inRange)
		{
			cellsInRange.Add(cell);
		}
	}

	return cellsInRange;
}

int FPositionUpdater::GetNeighboursAtCoordinate(OrganismPosition coordinate, TArray<OrganismPosition> previousCells)
{
	int neighbours = 0;

	forEachCell(previousCells)
	{
		if (FVector2D::Distance(coordinate.Position, cell.Position) == 1)
		{
			neighbours++;
		}
	}

	return neighbours;
}

#undef forEachCell
