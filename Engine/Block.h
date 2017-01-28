#pragma once

#include "Player.h"

class Block
{
public:

	bool IsNotCollidingWithPlayer(Player& player) const;

	void InitBlock(int in_x, int in_y, int in_width, int in_height);
	void DrawBlock(Graphics& gfx);

private:
	int boxX;
	int boxY;
	int width;
	int height;

	Color blockColor = Colors::Red;
};