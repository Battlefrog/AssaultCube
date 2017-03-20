/*
AssaultCube
Class: Points
Purpose: The blocks that let you exit the level!

@author Battlefrog
*/

#pragma once

#include "Graphics.h"
#include "Player.h"
#include "Sound.h"

class Point
{

public:

	const int GetX() const;
	const int GetY() const;
	bool IsCollidingWithPlayer( Player player );

	void DrawPoint( Graphics& gfx );
	void InitPoint( int in_x, int in_y );
	void SetRespawnOfPlayer(Player& player);

	bool isCollected = false;

private:

	int x;
	int y;

	static constexpr int width = 15;
	static constexpr int height = 45;

	Color pointColor = Colors::Blue;

	Sound getPoint = L"pointPickup.wav";
};