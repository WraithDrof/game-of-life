

#pragma once

#include "CoreMinimal.h"

/**
 * A handler for FVector2D which includes some GameOfLife-specific helper functions.
 */
class GAMEOFLIFE_API OrganismPosition
{
public:
	OrganismPosition(int x, int y);
	~OrganismPosition();

	enum Direction
	{
		North,
		NorthEast,
		East,
		SouthEast,
		South,
		SouthWest,
		West,
		NorthWest
	};

	FVector2D Position;

	OrganismPosition GetPositionInDirection(Direction direction);
	int GetDeltaY(Direction direction);
	int GetDeltaX(Direction direction);

	bool operator==(const OrganismPosition other) const
	{
		return Position == other.Position;
	}
};
