#pragma once

#include "Graphics.h"
#include "Player.h"
#include "Sound.h"

class Point
{

	public:

	const float GetX() const;
	const float GetY() const;

	bool IsCollidingWithPlayer( Player& player );

	void DrawPoint( Graphics& gfx );
	void InitPoint( float in_x, float in_y );

	bool isCollected = false;

	private:

	float x;
	float y;

	static constexpr float width = 15.0f;
	static constexpr float height = 45.0f;

	Color pointColor = Colors::Blue;

	Sound getPoint = L"pointPickup.wav";
};