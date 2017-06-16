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
	bool InitLevels();

	// Finds and loads the level requested into the CurrentLevel.
	void FindAndLoadLevel(Level &level);

	// Actually loads the level. Not needed to be called, this is used internally.
	void LoadLevelIntoCurrentLevel(Level &level);

	// Unloads the level generically so that a new level can be loaded.
	// A nice blank, clean state, really.
	void UnloadLevel(Level &level);

	// Vectors for holding the blocks and the points
	// This will be multidimentional. Just have to figure
	// out how to do that...
	std::vector<Block> blocks;
	std::vector<Point> points;

	// Vector for holding the startPos of the Player.
	// No need to be multidimentional, that would be a
	// waste of time.
	std::vector<int> playerStartPosition;

	// Title for the level. Might be shown to the player, 
	// but the primary purpose is to compare levels.
	std::string title;

	// Amount of things in the level. Nice to use for loops.
	int amountOfBlocks;
	int amountOfPoints;

	// A singular goal, as you'd like a goal...
	Goal goal;

};

// The container for the currently loaded level. Levels are just
// buckets of infomation, but the currentLevel is where everything
// gets rendered, collides with, etc.
Level CurrentLevel;

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