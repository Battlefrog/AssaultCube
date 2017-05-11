#pragma once
#include "Block.h"
#include "Player.h"
#include "Point.h"

#include <vector>

class Level
{

	public:

	void LoadLevel( Level blocks, Level player, Level points );
	void UnloadLevel( Level blocks, Level player, Level points );

	private:


	// Hardcoded Levels
	std::vector<Block> Level1Blocks;
	std::vector<Player> Level1Player;
	std::vector<Point> Level1Points;

	std::vector<Block> Level2Blocks;
	std::vector<Player> Level2Player;
	std::vector<Point> Level2Points;

	std::vector<Block> Level3Blocks;
	std::vector<Player> Level3Player;
	std::vector<Point> Level3Points;

};