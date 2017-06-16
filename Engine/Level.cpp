#include "Level.h"

bool Level::operator==(Level & rhs)
{
	return this->title == rhs.title;
}

bool Level::InitLevels()
{
	storyLevel1.title = "SLevel1";
	storyLevel2.title = "SLevel2";
	storyLevel3.title = "SLevel3";
	storyLevel4.title = "SLevel4";
	storyLevel5.title = "SLevel5";
	storyLevel6.title = "SLevel6";

	arcadeLevel1.title = "ALevel1";
	arcadeLevel2.title = "ALevel2";
	arcadeLevel3.title = "ALevel3";
	arcadeLevel4.title = "ALevel4";
	arcadeLevel5.title = "ALevel5";
	arcadeLevel6.title = "ALevel6";
}

// TODO: Could possibly change this to a switch statement, but it might not be nessessary
void Level::LoadLevel(Level &level)
{
	// Compare if the level wanting to be loaded is equal to any other level.
	// Currently this doesn't work, because I can't code operators worth shit.
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