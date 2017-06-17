#include "Level.h"

bool Level::operator==(Level & rhs)
{
	return this->title == rhs.title;
}

bool Level::InitLevels()
{
	// TODO: If presenting the titles to the Player, pretty them up
	// a little bit. :)

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
				FindAndLoadLevel(storyLevels[i]);
				foundLevel = true;
			}
		}
		for (int i = 0; i < numArcadeLevels + 1; ++i)
		{
			if (arcadeLevels[i] == level)
			{
				FindAndLoadLevel(arcadeLevels[i]);
				foundLevel = true;
			}
		}
	}

	//if (level == storyLevel1)
	//{
	//	LoadLevelIntoCurrentLevel(storyLevel1);
	//}
	//else if (level == storyLevel2)
	//{
	//	LoadLevelIntoCurrentLevel(storyLevel2);
	//}
	//else if (level == storyLevel3)
	//{
	//	LoadLevelIntoCurrentLevel(storyLevel3);
	//}
	//else if (level == storyLevel4)
	//{
	//	LoadLevelIntoCurrentLevel(storyLevel4);
	//}
	//else if (level == storyLevel5)
	//{
	//	LoadLevelIntoCurrentLevel(storyLevel5);
	//}
	//else if (level == storyLevel6)
	//{
	//	LoadLevelIntoCurrentLevel(storyLevel6);
	//}
	//else if (level == arcadeLevel1)
	//{
	//	LoadLevelIntoCurrentLevel(arcadeLevel1);
	//}
	//else if (level == arcadeLevel2)
	//{
	//	LoadLevelIntoCurrentLevel(arcadeLevel2);
	//}
	//else if (level == arcadeLevel3)
	//{
	//	LoadLevelIntoCurrentLevel(arcadeLevel3);
	//}
	//else if (level == arcadeLevel4)
	//{
	//	LoadLevelIntoCurrentLevel(arcadeLevel4);
	//}
	//else if (level == arcadeLevel5)
	//{
	//	LoadLevelIntoCurrentLevel(arcadeLevel5);
	//}
	//else if (level == arcadeLevel6)
	//{
	//	LoadLevelIntoCurrentLevel(arcadeLevel6);
	//}
	//else
	//{
	//	// TODO: Confusion will arise. DIS IS GONNA FUCK UP!
	//	assert("ERROR: Loading a level that does not exist. For safety, the current level is being unloaded.");
	//	UnloadLevel(CurrentLevel);
	//}
}

void Level::LoadLevelIntoCurrentLevel(Level & level)
{
	// IMPORTANT: You do not need to clear the CurrentLevel before calling FindAndLoadLevel.
	// I'm putting this here to make it easier on me.
	UnloadLevel(CurrentLevel);


}

void Level::UnloadLevel(Level& level)
{
	blocks.clear();
	points.clear();
	playerStartPosition.clear();

	amountOfBlocks = 0;
	amountOfPoints = 0;
}