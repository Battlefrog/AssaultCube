/*
AssaultCube
Class: Blocks
Purpose: The blocks that kill you when you touch
Normally they are 15 x 15

@author Battlefrog
*/

#pragma once

#include "Player.h"
#include "Sound.h"

class Block
{
public:

	bool IsCollidingWithPlayer( Player& player );

	void InitBlock( int in_x, int in_y, int in_width, int in_height );
	void DrawBlock( Graphics& gfx );
	void PlaySound();

	int CalculateWidth( int originalWidth );
	int CalculateHeight( int originalHeight );

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

	Sound blockCollision = L"intoWall.wav";
};