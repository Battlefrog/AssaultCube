#include "Point.h"

const float Point::GetX() const
{
	return x;
}

const float Point::GetY() const
{
}

bool Point::IsCollidingWithPlayer( Player& player )
{
	if ( !isCollected )
	{
		const float playerRight = player.GetX() + player.GetWidth();
		const float playerBottom = player.GetY() + player.GetHeight();
		const float pointRight = x + width;
		const float pointBottom = y + height;

		if ( playerRight >= x &&
			 player.GetX() <= pointRight &&
			 playerBottom >= y &&
			 player.GetY() <= pointBottom == true )
		{
			getPoint.Play();
			isCollected = true;
			return true;
		}
		else
		{
			return false;
		}
	}
	return false;
}

void Point::DrawPoint( Graphics& gfx )
{
	if ( isCollected == false )
	{
		gfx.DrawRectDim( int(x), int(y), int(width), int(height), pointColor );
	}
}

void Point::InitPoint( float in_x, float in_y )
{
	x = in_x;
	y = in_y;
}
