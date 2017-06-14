#include "Level.h"

bool Level::operator==(Level & rhs)
{
	return *this == rhs;
}

// TODO: Could possibly change this to a switch statement, but it might not be nessessary
void Level::InitLevel(const Level &level)
{
	if (level == storyLevel1)
	{

	}
	else if (level == storyLevel2)
	{

	}
	else if (level == storyLevel3)
	{

	}
	else if (level == storyLevel4)
	{

	}
	else if (level == storyLevel5)
	{

	}
	else if (level == storyLevel6)
	{

	}
	else if (level == arcadeLevel1)
	{

	}
	else if (level == arcadeLevel2)
	{

	}
	else if (level == arcadeLevel3)
	{

	}
	else if (level == arcadeLevel4)
	{

	}
	else if (level == arcadeLevel5)
	{

	}
	else if (level == arcadeLevel6)
	{

	}
}

void Level::UnloadLevel(Level & level)
{
	blocks.clear();
	points.clear();
	playerStartPosition.clear();

	amountOfBlocks = 0;
	amountOfPoints = 0;
}