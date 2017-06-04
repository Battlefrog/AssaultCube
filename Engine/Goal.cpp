#include "Goal.h"

const int Goal::GetX() const
{
	return x;
}

const int Goal::GetY() const
{
	return y;
}

bool Goal::IsPlayerColliding( Player& player )
{
	const float playerRight = player.GetX() + player.GetWidth();
	const float playerBottom = player.GetY() + player.GetHeight();
	const int goalRight = x + width;
	const int goalBottom = y + height;

	return lib.CalculateCollision(goalRight, goalBottom, playerRight, playerBottom,
									x, y, player.GetX(), player.GetY());

}

void Goal::DrawGoal( Graphics & gfx ) const
{
	gfx.DrawRectDim( x, y, width, height, goalColor );
}

void Goal::InitGoal( int in_x, int in_y )
{
	x = in_x;
	y = in_y;
}

// TODO: Move onto the next level, perhaps?
bool Goal::PlayerCollision( MainWindow& wnd )
{
	levelEnd.Play();
	wnd.Kill();
	return true;
}
