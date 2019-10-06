#include "CoreMinimal.h"
#include "OrganismPosition.h"

OrganismPosition::OrganismPosition(int x, int y)
{
	Position = FVector2D(x, y);
}

OrganismPosition::~OrganismPosition()
{
}

OrganismPosition OrganismPosition::GetPositionInDirection(Direction direction)
{
	return OrganismPosition(GetDeltaX(direction), GetDeltaY(direction));
}

int OrganismPosition::GetDeltaX(Direction direction)
{
	switch (direction)
	{
	case OrganismPosition::NorthWest:
	case OrganismPosition::North:
	case OrganismPosition::NorthEast:
		return -1;
	case OrganismPosition::SouthEast:
	case OrganismPosition::South:
	case OrganismPosition::SouthWest:
		return 1;
	default:
		return 0;
	}
}

int OrganismPosition::GetDeltaY(Direction direction)
{
	switch (direction)
	{
	case OrganismPosition::NorthEast:
	case OrganismPosition::East:
	case OrganismPosition::SouthEast:
		return 1;
	case OrganismPosition::NorthWest:
	case OrganismPosition::West:
	case OrganismPosition::SouthWest:
		return -1;
	default:
		return 0;
	}
}
