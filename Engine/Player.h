#pragma once

#include "Graphics.h"
#include "Keyboard.h"

class Player
{
public:

	Player();

	int GetX() const;
	int GetY() const;
	int GetWidth() const;
	int GetHeight() const;

	void UpdateInput(const Keyboard& kbd);
	void DrawPlayer(Graphics& gfx) const;
	void IsOutsideBoundries();
	void ResetPlayer();

	int playerSpeed = 1;

private:

	int x;
	int y;

	int startingX = 50;
	int startingY = 75;

	static constexpr int width = 15;
	static constexpr int height = 15;

	Color playerColor = Colors::Green;

};