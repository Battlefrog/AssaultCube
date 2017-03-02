#pragma once

#include "Graphics.h"
#include "Keyboard.h"

class Player
{
	public:

	Player();

	const int GetX() const;
	const int GetY() const;

	int GetWidth() const;
	int GetHeight() const;
	int SetTimesReset( int newValue );

	void UpdateInput( const Keyboard& kbd, float dt );
	void DrawPlayer( Graphics& gfx ) const;
	void IsOutsideBoundries();
	void ResetPlayer();

	int playerSpeed = 60;
	int numberOfTimesReset = 0;

	private:

	int x;
	int y;

	int startingX = 50;
	int startingY = 75;

	static constexpr int width = 15;
	static constexpr int height = 15;

	Color playerColor = Colors::Green;
};