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

	/* LEVEL 1 */

	/* Goals */
	goal.InitGoal( 300, 255 );

	/* Blocks */

	// Level Border
	blocks[ 0 ].InitBlock( 20, 30, 750, 15 );
	blocks[ 1 ].InitBlock( 20, 30, 15, 550 );
	blocks[ 2 ].InitBlock( 20, 565, 750, 15 );
	blocks[ 3 ].InitBlock( 770, 30, 15, 550 );

	// 1st Challenge
	blocks[ 4 ].InitBlock( 155, 30, 75, 300 );
	blocks[ 5 ].InitBlock( 20, 375, 200, 15 );
	blocks[ 6 ].InitBlock( 20, 150, 75, 15 );
	blocks[ 7 ].InitBlock( 260, 240, 15, 60 );
	blocks[ 8 ].InitBlock( 275, 30, 110, 210 );

	// 2nd Challenge
	blocks[ 9 ].InitBlock( 300, 300, 15, 45 );
	blocks[ 10 ].InitBlock( 600, 360, 15, 75 );
	blocks[ 11 ].InitBlock( 600, 490, 15, 75 );
	blocks[ 12 ].InitBlock( 275, 285, 100, 15 );
	blocks[ 13 ].InitBlock( 300, 300, 50, 50 );
	blocks[ 14 ].InitBlock( 570, 350, 200, 15 );
	blocks[ 15 ].InitBlock( 460, 100, 45, 280 );

	/* Points */

	points[ 0 ].InitPoint( 700, 440 );
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
	float dt = ft.Mark();

	for ( int i = 0; i <= amountOfBlocks; ++i )
	{
		if ( !blocks[ i ].IsCollidingWithPlayer( player ) )
		{
			player.UpdateInput( wnd.kbd, dt );
			player.IsOutsideBoundries();
		}
		else
		{
			player.ResetPlayer();
			player.SetTimesReset( player.numberOfTimesReset++ );
		}
	}

	for ( int i = 0; i <= amountOfPoints; ++i )
	{
		if ( points[ i ].IsCollidingWithPlayer( player ) )
		{
			isPointCollected = true;
		}
	}

	if ( isPointCollected == true )
	{
		if ( goal.IsPlayerColliding( player ) )
		{
			goal.PlayerCollision( wnd );
		}
	}

	gameManager.HandleCommonInputs( wnd.kbd, wnd, player );
}

void Game::ComposeFrame()
{
	if ( !ActiveTitleScreen )
	{
		player.DrawPlayer( gfx );

		for ( int i = 0; i < amountOfBlocks; ++i )
		{
			blocks[ i ].DrawBlock( gfx );
		}

		for ( int i = 0; i < amountOfPoints; ++i )
		{
			points[ i ].DrawPoint( gfx );
		}

		goal.DrawGoal( gfx );
	}
	else
	{
		gameManager.DrawTitleScreen( gfx, gfx.ScreenWidth / 2, gfx.ScreenHeight / 2 );
	}
}
