/*
Cubytes
Class: Player
Purpose: The dude you move around!

@author Battlefrog
*/

#pragma once

#include "Graphics.h"
#include "Keyboard.h"
#include "Sound.h"
class Player
{
public:

	Player();

	const float GetX() const;
	const float GetY() const;

	const float GetRespawnX() const;
	const float GetRespawnY() const;

	float SetRespawnX(const int newRespawnX);
	float SetRespawnY(const int newRespawnY);

	int GetWidth() const;
	int GetHeight() const;

	void UpdateInput( const Keyboard& kbd, float dt );
	void DrawPlayer( Graphics& gfx ) const;
	void IsOutsideBoundries();
	void ResetPlayer();

	int playerSpeed = 55;
	int numberOfTimesReset = 0;

private:

	float x;
	float y;

	float startingX = 50.0f;
	float startingY = 75.0f;
	float respawnX = startingX;
	float respawnY = startingY;

	static constexpr int width = 15;
	static constexpr int height = 15;

	Color playerColor = Colors::Green;

	Sound playerRespawn = L"playerRespawn.mp3";

};