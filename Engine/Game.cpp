/****************************************************************************************** 
 *	Chili DirectX Framework Version 16.07.20											  *	
 *	Game.cpp																			  *
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
#include "MainWindow.h"
#include "Game.h"

Game::Game( MainWindow& wnd )
	:
	wnd( wnd ),
	gfx( wnd )
{
	blocks[0].InitBlock(300, 300, 35, 20);
	blocks[1].InitBlock(222, 555, 50, 50);
}

void Game::Go()
{
	gfx.BeginFrame();	
	UpdateModel();
	ComposeFrame();
	gfx.EndFrame();
}

void Game::UpdateModel()
{
	for (int i = 0; i <= amountOfBlocks; ++i)
	{
		if (blocks[i].IsNotCollidingWithPlayer(player))
		{
			player.UpdateInput(wnd.kbd);
			player.IsOutsideBoundries();
		}
		else
		{
			isGameOver = true;
			// TODO: Do something when the game is over
		}
	}	
}

void Game::ComposeFrame()
{
	player.DrawPlayer(gfx);
	for (int i = 0; i <= amountOfBlocks; ++i)
	{
		blocks[i].DrawBlock(gfx);
	}
}
