#include "Block.h"

// TODO: Function does not report collisions to blocks
// with negative width and heights. Would be nice.
bool Block::IsCollidingWithPlayer( Player& player )
{
	float playerRight = player.GetX() + player.GetWidth();
	float playerBottom = player.GetY() + player.GetHeight();
	int blockRight = CalculateWidth( width );
	int blockBottom = CalculateHeight( height );

	if ( lib.CalculateCollision(blockRight, blockBottom, playerRight, playerBottom,
								boxX, boxY, player.GetX(), player.GetY()))
	{
		PlaySound();
		return true;
	}
	else
	{
		return false;
	}
}

void Block::InitBlock( int in_x, int in_y, int in_width, int in_height )
{
	boxX = in_x;
	boxY = in_y;
	width = in_width;
	height = in_height;
}

void Block::DrawBlock( Graphics & gfx )
{
	gfx.DrawRectDim( boxX, boxY, width, height, blockColor );
}

void Block::PlaySound()
{
	blockCollision.Play();
}

int Block::CalculateWidth( int originalWidth )
{
	if ( originalWidth < 0 )
	{
		return boxX - originalWidth;
	}
	else
	{
		return boxX + originalWidth;
	}
}

int Block::CalculateHeight( int originalHeight )
{
	if ( originalHeight < 0 )
	{
		return boxY - originalHeight;
	}
	else
	{
		return boxY + originalHeight;
	}
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
