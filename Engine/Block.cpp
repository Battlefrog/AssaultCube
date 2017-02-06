#include "Block.h"

//TODO: Function does not report collisions to blocks
//with negative width and heights
bool Block::IsCollidingWithPlayer(Player & player) const
{
	const int playerRight = player.GetX() + player.GetWidth();
	const int playerBottom = player.GetY() + player.GetHeight();
	const int blockRight = boxX + width;
	const int blockBottom = boxY + height;

	if (playerRight >= boxX &&
		player.GetX() <= blockRight &&
		playerBottom >= boxY &&
		player.GetY() <= blockBottom == true)
	{
		return true;
	}
	else
	{
		return false;
	}
}

void Block::InitBlock(int in_x, int in_y, int in_width, int in_height)
{
	boxX = in_x;
	boxY = in_y;
	width = in_width;
	height = in_height;
}

void Block::DrawBlock(Graphics & gfx)
{
	gfx.DrawRectDim(boxX, boxY, width, height, blockColor);
}

const int Block::GetBlockX() const
{
	return boxX;
}

const int Block::GetBlockY() const
{
	return boxY;
}

const int Block::GetBlockWidth() const
{
	return width;
}

const int Block::GetBlockHeight() const
{
	return height;
}
