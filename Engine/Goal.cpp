#include "Goal.h"

const int Goal::GetX() const
{
	return x;
}

const int Goal::GetY() const
{
	return y;
}

bool Goal::IsPlayerColliding( Player player )
{
	const float playerRight = player.GetX() + player.GetWidth();
	const float playerBottom = player.GetY() + player.GetHeight();
	const int goalRight = x + width;
	const int goalBottom = y + height;

	if ( playerRight >= x &&
		 player.GetX() <= float(goalRight) &&
		 playerBottom >= y &&
		 player.GetY() <= float(goalBottom) == true )
	{
		return true;
	}
	else
	{
		return false;
	}
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

bool Goal::PlayerCollision()
{
	levelEnd.Play();
	return true;
}
