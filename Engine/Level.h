#pragma once
#include "Block.h"
#include "Player.h"
#include "Point.h"
#include "Goal.h"

#include <vector>

struct Level
{

	bool operator == ( Level &level);

	// Configures the level specifically for the specific level.
	void InitLevel(const Level &level);

	// Unloads the level generically so that a new level can be loaded.
	// A nice blank, clean state, really.
	void UnloadLevel(Level &level);

	std::vector<Block> blocks;
	std::vector<Point> points;

	std::vector<int> playerStartPosition;

	int amountOfBlocks;
	int amountOfPoints;

	Goal goal;

};

// Story Mode Levels
const Level storyLevel1;
const Level storyLevel2;
const Level storyLevel3;
const Level storyLevel4;
const Level storyLevel5;
const Level storyLevel6;

// Arcade Mode Levels
const Level arcadeLevel1;
const Level arcadeLevel2;
const Level arcadeLevel3;
const Level arcadeLevel4;
const Level arcadeLevel5;
const Level arcadeLevel6;