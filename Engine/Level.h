#pragma once
#include "Block.h"
#include "Player.h"
#include "Point.h"
#include "Goal.h"

#include <vector>
#include <string>

class Level
{
public:
	bool operator == ( Level &level);

	// Adds the titles and other misc. things to the levels.
	// THIS IS NEEDED. CALL ME!
	bool InitLevels();

	// Configures the level specifically for the specific level.
	void LoadLevel(Level &level);

	// Unloads the level generically so that a new level can be loaded.
	// A nice blank, clean state, really.
	void UnloadLevel(Level &level);

	std::vector<Block> blocks;
	std::vector<Point> points;

	std::vector<int> playerStartPosition;

	std::string title;

	int amountOfBlocks;
	int amountOfPoints;

	Goal goal;

};

// The container for the currently loaded level
const Level currentLevel;

// Story Mode Levels //

Level storyLevel1;
Level storyLevel2;
Level storyLevel3;
Level storyLevel4;
Level storyLevel5;
Level storyLevel6;

// Arcade Mode Levels //

Level arcadeLevel1;
Level arcadeLevel2;
Level arcadeLevel3;
Level arcadeLevel4;
Level arcadeLevel5;
Level arcadeLevel6;