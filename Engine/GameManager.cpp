#include "GameManager.h"

void GameManager::HandleCommonInputs( const Keyboard& kbd, MainWindow& wnd, Player& player )
{
	if ( kbd.KeyIsPressed( 'R' ) )
	{
		player.ResetPlayer();
	}

	if ( kbd.KeyIsPressed( VK_ESCAPE ) )
	{
		wnd.Kill();
	}
}

void GameManager::DrawTitleScreen( Graphics & gfx, int x, int y )
{
	// TODO: Impliment titlescreen here when .bmp loading is a thing ;)
}

void GameManager::PlayBackgroundMusic()
{
}

