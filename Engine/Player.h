#pragma once

#include "Graphics.h"
#include "Keyboard.h"

class Player
{
	public:

	Player();

	const float GetX() const;
	const float GetY() const;

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

	float x;
	float y;

	float startingX = 50.0f;
	float startingY = 75.0f;

	static constexpr int width = 15;
	static constexpr int height = 15;

	Color playerColor = Colors::Green;
};