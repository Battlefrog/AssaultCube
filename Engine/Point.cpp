#include "Point.h"

const int Point::GetX() const
{
	return x;
}

const int Point::GetY() const
{
	return y;
}

bool Point::IsPlayerColliding(Player player)
{
	const int playerRight = player.GetX() + player.GetWidth();
	const int playerBottom = player.GetY() + player.GetHeight();
	const int pointRight = x + width;
	const int pointBottom = y + height;

	if (playerRight >= x &&
		player.GetX() <= pointRight &&
		playerBottom >= y &&
		player.GetY() <= pointBottom == true)
	{
		return true;
		isCollected = true;
	}
	else
	{
		return false;
	}
}

void Point::DrawPoint(Graphics& gfx)
{
	if (isCollected == false)
	{
		gfx.DrawRectDim(x, y, width, height, pointColor);
	}
}

void Point::InitPoint(int in_x, int in_y)
{
	x = in_x;
	y = in_y;
}
