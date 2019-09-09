#include "PositionUpdater.h"

FPositionUpdater::FPositionUpdater(int survivalMinimum, int survivalMaximum)
{
	SurvivalMinimum = survivalMinimum;
	SurvivalMaximum = survivalMaximum;
}

FPositionUpdater::~FPositionUpdater()
{
}

TArray<FVector2D> FPositionUpdater::GetNextPositionUpdate(const TArray<FVector2D> previousCells)
{
	TArray<FVector2D> nextPositions;

	auto survivors = GetSurvivingLiveCells(previousCells);
	auto newCells = GetNewCells(previousCells);

	nextPositions.Append(survivors);
	nextPositions.Append(newCells);

	return nextPositions;
}

TArray<FVector2D> FPositionUpdater::GetSurvivingLiveCells(const TArray<FVector2D> previousCells)
{
	if (SurvivalMinimum > SurvivalMaximum)
	{
		throw "SurvivalMinimum is not <= SurvivalMaximum! Cannot calculate surviving cells.";
	}

	TArray<FVector2D> survivingCells;

	UE_LOG(LogTemp, Warning, TEXT("Calculating surviving cells"));
	for (auto& previousCell : previousCells)
	{
		auto neighbourCount = GetNeighboursAtCoordinate(previousCell);
		if (neighbourCount >= SurvivalMinimum && neighbourCount <= SurvivalMaximum)
		{
			survivingCells.Add(previousCell);
			UE_LOG(LogTemp, Warning, TEXT("Cell has survived: [%s]"), *previousCell.ToString());
		}
	}

	return survivingCells;
}

TArray<FVector2D> FPositionUpdater::GetNewCells(const TArray<FVector2D> previousCells)
{
	return TArray<FVector2D>();
}

bool FPositionUpdater::GetIfShouldBeAlive(const FVector2D cell, const TArray<FVector2D> previousCells)
{
	return false;
}

bool FPositionUpdater::GetIfDeadCellShouldBeAlive(const FVector2D, const TArray<FVector2D> previousCells)
{
	return false;
}

bool FPositionUpdater::GetIfAliveCellShouldBeAlive(const FVector2D, const TArray<FVector2D> previousCells)
{
	return false;
}

int FPositionUpdater::GetNeighboursAtCoordinate(const FVector2D coordinate)
{
	return 0;
}
