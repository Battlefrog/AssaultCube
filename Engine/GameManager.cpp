#include "GameManager.h"

void GameManager::HandleCommonInputs(const Keyboard& kbd, Player& player, MainWindow& wnd)
{
	if (kbd.KeyIsPressed('R'))
	{
		player.ResetPlayer();
	}

	if (kbd.KeyIsPressed(VK_ESCAPE))
	{
		wnd.Kill();
	}
}

void GameManager::PlaySound()
{
}
