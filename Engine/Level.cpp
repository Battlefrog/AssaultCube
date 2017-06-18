#include "Level.h"

bool Level::operator==(Level & rhs)
{
	return this->title == rhs.title;
}

bool Level::InitLevels()
{
	// TODO: If presenting the titles to the Player, pretty them up
	// a little bit. :)

	// Creating the titles of the levels
	for (int i = 0; i < numStoryLevels + 1; ++i)
	{
		storyLevels[i].title = std::string("SLevel") + std::to_string(i);
	}
	for (int i = 0; i < numArcadeLevels + 1; ++i)
	{
		arcadeLevels[i].title = std::string("ALevel") + std::to_string(i);
	}


	return true;
}

// TODO: Could possibly change this to a switch statement, but it might not be nessessary.
void Level::FindAndLoadLevel(Level &level)
{
	// Compare if the level wanting to be loaded is equal to any other level, and then loads it.
	// Currently this compiles. No idea it it'll work in practice.
	bool foundLevel = false;

	if (foundLevel == false)
	{
		for (int i = 0; i < numStoryLevels + 1; ++i)
		{
			if (storyLevels[i] == level)
			{
				LoadLevelIntoCurrentLevel(storyLevels[i]);
				foundLevel = true;
				// Just in case
				break;
			}
		}
		for (int i = 0; i < numArcadeLevels + 1; ++i)
		{
			if (arcadeLevels[i] == level)
			{
				LoadLevelIntoCurrentLevel(arcadeLevels[i]);
				foundLevel = true;
				// Just in case
				break;
			}
		}
	}
}

void Level::LoadLevelIntoCurrentLevel(Level & level)
{
	// IMPORTANT: You do not need to clear the CurrentLevel before calling FindAndLoadLevel.
	// I'm putting this here to make it easier on me.
	UnloadLevel(CurrentLevel);

	// Inserting the stored data from .txt files into the CurrentLevel
	level.blocks = CurrentLevel.blocks;
	level.points = CurrentLevel.points;
	level.playerStartPosition = CurrentLevel.playerStartPosition;
	level.amountOfBlocks = CurrentLevel.amountOfBlocks;
	level.amountOfPoints = CurrentLevel.amountOfPoints;
	level.goalX = CurrentLevel.goalX;
	level.goalY = CurrentLevel.goalY;
}

void Level::UnloadLevel(Level& level)
{
	blocks.clear();
	points.clear();
	playerStartPosition.clear();

	amountOfBlocks = 0;
	amountOfPoints = 0;
}