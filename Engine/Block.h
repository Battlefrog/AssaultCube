#pragma once

#include "Player.h"

class Block
{
public:

	bool IsCollidingWithPlayer(Player& player);

	void InitBlock(int in_x, int in_y, int in_width, int in_height);
	void DrawBlock(Graphics& gfx);

	int CalculateWidth(int originalWidth);
	int CalculateHeight(int originalHeight);

	const int GetBlockX() const;
	const int GetBlockY() const;
	const int GetBlockWidth() const;
	const int GetBlockHeight() const;

private:
	int boxX;
	int boxY;
	int width;
	int height;

	Color blockColor = Colors::Red;
};