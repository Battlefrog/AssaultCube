#include "GameManager.h"

void GameManager::HandleCommonInputs( const Keyboard& kbd, Player& player )
{
	if ( kbd.KeyIsPressed( 'R' ) )
	{
		player.ResetPlayer();
	}
}

void GameManager::DrawTitleScreen( Graphics & gfx, int x, int y )
{
}

