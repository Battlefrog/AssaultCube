#pragma once

#include "Keyboard.h"
#include "Player.h"
#include "Sound.h"
#include "Point.h"
#include "Graphics.h"

class GameManager
{

	public:

	void HandleCommonInputs( const Keyboard& kbd, Player& player);
	void DrawTitleScreen(Graphics& gfx, int x, int y);
};