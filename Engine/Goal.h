#pragma once

#include "Graphics.h"
#include "Player.h"
#include "Sound.h"

class Goal
{

	public:

	const float GetX() const;
	const float GetY() const;

	bool IsPlayerColliding( Player& player );

	void DrawGoal( Graphics& gfx ) const;
	void InitGoal( float in_x, float in_y );
	void PlayerCollision();

	private:

	float x;
	float y;

	static constexpr float width = 15.0f;
	static constexpr float height = 15.0f;

	Color goalColor = Colors::Yellow;

	Sound levelEnd = L"completeLevel.wav";
};