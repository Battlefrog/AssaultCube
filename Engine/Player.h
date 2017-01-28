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

	int playerSpeed = 2;

private:

	int x;
	int y;

	static constexpr int  width = 15;
	static constexpr int height = 15;

	Color playerColor = Colors::Green;

};