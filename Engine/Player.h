#pragma once

#include "Graphics.h"
#include "Keyboard.h"

class Player
{

	public:

	Player();

	const float GetX() const;
	const float GetY() const;

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

	float startingX = 50.0f;
	float startingY = 75.0f;

	static constexpr float width = 15.0f;
	static constexpr float height = 15.0f;

	Color playerColor = Colors::Green;
};