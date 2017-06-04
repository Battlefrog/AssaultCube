#include "Point.h"

const int Point::GetX() const
{
	return x;
}

const int Point::GetY() const
{
	return y;
}

bool Point::IsCollidingWithPlayer( Player& player )
{
	if ( !isCollected )
	{
		const float playerRight = player.GetX() + player.GetWidth();
		const float playerBottom = player.GetY() + player.GetHeight();
		const int pointRight = x + width;
		const int pointBottom = y + height;

		if ( lib.CalculateCollision(pointRight, pointBottom, playerRight, playerBottom, 
									x, y, player.GetX(), player.GetY()) == true )
		{
			getPoint.Play();
			player.SetRespawnX( x );
			player.SetRespawnY( y );
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
		gfx.DrawRectDim( x, y, width, height, pointColor );
	}
}

void Point::InitPoint( int in_x, int in_y )
{
	x = in_x;
	y = in_y;
}
