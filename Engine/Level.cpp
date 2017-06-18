#include "Level.h"

bool Level::operator==(Level & rhs)
{
	return this->title == rhs.title;
}

bool Level::InitLevels()
{
	// TODO: If presenting the titles to the Player, pretty them up
	// a little bit, like loading them via the .txt level files

	for (int i = 0; i < numStoryLevels + 1; ++i)
	{
		// Creating the titles of the levels
		storyLevels[i].title = std::string("SLevel") + std::to_string(i);

		// Loading infomation via .txt files
		CollectAndStoreLevelInfo(storyLevels[i]);
	}
	for (int i = 0; i < numArcadeLevels + 1; ++i)
	{
		// Creating the titles of the levels
		arcadeLevels[i].title = std::string("ALevel") + std::to_string(i);

		// Loading infomation via .txt files
		CollectAndStoreLevelInfo(arcadeLevels[i]);
	}
	return true;
}

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

void Level::CollectAndStoreLevelInfo(Level & level)
{
}

void Level::LoadLevelIntoCurrentLevel(Level & level)
{
	// IMPORTANT: You do not need to clear the CurrentLevel before calling FindAndLoadLevel.
	// I'm putting this here to make it easier on me.
	UnloadLevel(CurrentLevel);

	// Inserting the stored data from .txt files into the CurrentLevel
	level.blocks = CurrentLevel.blocks;
	level.points = CurrentLevel.points;

	level.playerStartX = CurrentLevel.playerStartX;
	level.playerStartY = CurrentLevel.playerStartY;

	level.amountOfBlocks = CurrentLevel.amountOfBlocks;
	level.amountOfPoints = CurrentLevel.amountOfPoints;

	level.goalX = CurrentLevel.goalX;
	level.goalY = CurrentLevel.goalY;
}

// TODO: Update this as the levels grow in features / complexity
void Level::UnloadLevel(Level& level)
{
	blocks.clear();
	points.clear();

	playerStartX = 0;
	playerStartY = 0;

	amountOfBlocks = 0;
	amountOfPoints = 0;
}

int Level::GetGoalX()
{
	return goalX;
}

int Level::GetGoalY()
{
	return goalY;
}

int Level::GetPlayerStartX()
{
	return playerStartX;
}

int Level::GetPlayerStartY()
{
	return playerStartY;
}
