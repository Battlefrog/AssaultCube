#pragma once4

#include "Keyboard.h"
#include "MainWindow.h"
#include "Player.h"
#include "Sound.h"
#include "Point.h"

class GameManager
{

public:

	void HandleCommonInputs(const Keyboard& kbd, Player& player, MainWindow& wnd);
	void PlaySound();

private:

};