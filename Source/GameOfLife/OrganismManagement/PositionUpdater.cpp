#include "PositionUpdater.h"
#include "GameOfLife.h"

FPositionUpdater::FPositionUpdater(int survivalMinimum, int survivalMaximum)
{
	UE_LOG(
		LogGameOfLife,
		Log,
		TEXT("Creating PositionUpdater with survival bounds as min = [%d], max = [%d]"),
		survivalMinimum,
		survivalMaximum);

	SurvivalMinimum = survivalMinimum;
	SurvivalMaximum = survivalMaximum;
}

FPositionUpdater::~FPositionUpdater()
{
}

TArray<FVector2D> FPositionUpdater::GetNextPositionUpdate(TArray<FVector2D> previousCells)
{
	TArray<FVector2D> nextPositions;

	auto survivors = GetSurvivingLiveCells(previousCells);
	/*auto newCells = GetNewCells(previousCells);

	nextPositions.Append(survivors);
	nextPositions.Append(newCells);*/

	return nextPositions;
}

TArray<FVector2D> FPositionUpdater::GetSurvivingLiveCells(TArray<FVector2D> previousCells)
{
	checkf(
		SurvivalMinimum <= SurvivalMaximum,
		TEXT("SurvivalMinimum is not <= SurvivalMaximum! Cannot calculate surviving cells.")
	);

	TArray<FVector2D> survivingCells;

	for (auto previousCell : previousCells)
	{
		auto neighbourCount = GetNeighboursAtCoordinate(previousCell, previousCells);
		if (neighbourCount >= SurvivalMinimum && neighbourCount <= SurvivalMaximum)
		{
			survivingCells.Add(previousCell);
			UE_LOG(LogGameOfLife, Log, TEXT("Cell has survived: [%s]"), *previousCell.ToString());
		}
		else
		{
			UE_LOG(LogPositionUpdater, Log, TEXT("Cell has died: [%s]"), *previousCell.ToString());
		}
	}

	return survivingCells;
}

int FPositionUpdater::GetNeighboursAtCoordinate(FVector2D coordinate, TArray<FVector2D> previousCells)
{
	int neighbours = 0;

	for (auto previousCell : previousCells)
	{
		if (FVector2D::Distance(coordinate, previousCell) == 1)
		{
			neighbours++;
		}
	}

	return neighbours;
}

TArray<FVector2D> FPositionUpdater::GetNewCells(TArray<FVector2D> previousCells)
{
	return TArray<FVector2D>();
}

bool FPositionUpdater::GetIfShouldBeAlive(FVector2D cell, TArray<FVector2D> previousCells)
{
	return false;
}

bool FPositionUpdater::GetIfDeadCellShouldBeAlive(FVector2D, TArray<FVector2D> previousCells)
{
	return false;
}

bool FPositionUpdater::GetIfAliveCellShouldBeAlive(FVector2D, TArray<FVector2D> previousCells)
{
	return false;
}
