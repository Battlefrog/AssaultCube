#pragma once
#include "Block.h"
#include "Player.h"
#include "Point.h"
#include "Goal.h"

#include <vector>
#include <string>
#include <assert.h>

class Level
{

public:

	// Compares the level titles, not the actual content.
	// It's much nicer, and quite possibly faster.
	bool operator == ( Level &level);

	// Adds the titles and other misc. things to the levels.
	// THIS IS NEEDED. CALL ME, BUT ONLY ONCE!
	// Again is a waste of time.
	bool InitLevels();

	// Finds and loads the level requested into the CurrentLevel.
	void FindAndLoadLevel(Level &level);

	// Unloads the level generically so that a new level can be loaded.
	// A nice blank, clean state, really.
	void UnloadLevel(Level &level);

	int GetGoalX();
	int GetGoalY();

	int GetPlayerStartX();
	int GetPlayerStartY();

	// Vectors for holding the blocks and the points
	std::vector<Block> blocks;
	std::vector<Point> points;

	// Title for the level. Might be shown to the player, 
	// but the primary purpose is to compare levels.
	std::string title;

	// Amount of things in the level. Nice to use for loops.
	int amountOfBlocks;
	int amountOfPoints;

	// A singular goal, as you'd like a goal...
	Goal goal;

private:

	// Scans a .txt file for level infomation and adds it to
	// the various factors of the level
	void CollectAndStoreLevelInfo(Level &level);

	// Actually loads the level. Not needed to be called, this is used internally.
	void LoadLevelIntoCurrentLevel(Level &level);

	// Simple x and y pos of the goal
	int goalX;
	int goalY;

	// Two ints for holding the starting position of the player
	int playerStartX;
	int playerStartY;

};

int numStoryLevels = 6;
int numArcadeLevels = 6;

std::vector<Level> storyLevels;
std::vector<Level> arcadeLevels;

// The container for the currently loaded level. Levels are just
// buckets of infomation, but the CurrentLevel is where everything
// gets rendered, collides with, etc.
Level CurrentLevel;