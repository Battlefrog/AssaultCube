#include "Goal.h"

const float Goal::GetX() const
{
	return x;
}

const float Goal::GetY() const
{
	return y;
}

bool Goal::IsPlayerColliding( Player& player )
{
	const float playerRight = player.GetX() + player.GetWidth();
	const float playerBottom = player.GetY() + player.GetHeight();
	const float goalRight = x + width;
	const float goalBottom = y + height;

	if ( playerRight >= x &&
		 player.GetX() <= goalRight &&
		 playerBottom >= y &&
		 player.GetY() <= goalBottom == true )
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

void Goal::InitGoal( float in_x, float in_y )
{
	x = in_x;
	y = in_y;
}

void Goal::PlayerCollision()
{
	levelEnd.Play();
}
