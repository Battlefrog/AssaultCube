/*
AssaultCube
Class: GameManager
Purpose: Condences a bunch of nice things that shouldn't be in Game.cpp

@author Battlefrog
*/

#pragma once

#include "Keyboard.h"
#include "Player.h"
#include "Sound.h"
#include "Graphics.h"
#include "MainWindow.h"

class GameManager
{
public:

	void HandleCommonInputs( const Keyboard& kbd, MainWindow& wnd, Player& player );
	void DrawTitleScreen( Graphics& gfx, int x, int y );
	void PlayBackgroundMusic();

private:

	Sound backgroundMusic = L"backgroundMusic.mp3";

};