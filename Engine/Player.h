#pragma once

#include "Graphics.h"
#include "Keyboard.h"

class Player
{

	public:

	Player();

	const int GetX() const;
	const int GetY() const;

	float GetWidth() const;
	float GetHeight() const;
	int SetTimesReset( int newValue );

	void UpdateInput( const Keyboard& kbd, float dt );
	void DrawPlayer( Graphics& gfx ) const;
	void IsOutsideBoundries();
	void ResetPlayer();

	float playerSpeed = 60.0f;
	int numberOfTimesReset = 0;

	private:

	float x;
	float y;

	int startingX = 50;
	int startingY = 75;

	static constexpr float width = 15.0f;
	static constexpr float height = 15.0f;

	Color playerColor = Colors::Green;
};