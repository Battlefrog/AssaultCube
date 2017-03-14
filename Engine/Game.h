/******************************************************************************************
*	Chili DirectX Framework Version 16.07.20											  *
*	Game.h																				  *
*	Copyright 2016 PlanetChili.net <http://www.planetchili.net>							  *
*																						  *
*	This file is part of The Chili DirectX Framework.									  *
*																						  *
*	The Chili DirectX Framework is free software: you can redistribute it and/or modify	  *
*	it under the terms of the GNU General Public License as published by				  *
*	the Free Software Foundation, either version 3 of the License, or					  *
*	(at your option) any later version.													  *
*																						  *
*	The Chili DirectX Framework is distributed in the hope that it will be useful,		  *
*	but WITHOUT ANY WARRANTY; without even the implied warranty of						  *
*	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the						  *
*	GNU General Public License for more details.										  *
*																						  *
*	You should have received a copy of the GNU General Public License					  *
*	along with The Chili DirectX Framework.  If not, see <http://www.gnu.org/licenses/>.  *
******************************************************************************************/
#pragma once

#include "Keyboard.h"
#include "Mouse.h"
#include "Graphics.h"
#include "Player.h"
#include "Block.h"
#include "Sound.h"
#include "Goal.h"
#include "GameManager.h"
#include "FrameTimer.h"
#include "Point.h"

class Game
{
public:

	Game( class MainWindow& wnd );
	Game( const Game& ) = delete;
	Game& operator=( const Game& ) = delete;
	void Go();

private:

	void ComposeFrame();
	void UpdateModel();

private:

	static constexpr int amountOfBlocks = 16;
	static constexpr int amountOfPoints = 1;

	bool isPointCollected = false;
	bool ActiveTitleScreen = false;

	Player player;

	Goal goal;

	Block blocks[ amountOfBlocks ];
	Point points[ amountOfPoints ];

	Sound crashIntoWall;

	GameManager gameManager;

	FrameTimer ft;

	MainWindow& wnd;
	Graphics gfx;

	/********************************/
};