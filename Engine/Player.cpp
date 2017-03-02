#include "Player.h"

void Player::IsOutsideBoundries()
{
	const float right = x + width;
	const float bottom = y + height;

	if ( x < 0 )
	{
		x = 0;
	}
	else if ( right >= float( Graphics::ScreenWidth ) )
	{
		x = float( Graphics::ScreenWidth - 1 ) - width;
	}

	if ( y < 0 )
	{
		y = 0;
	}
	else if ( bottom >= float( Graphics::ScreenHeight ) )
	{
		y = float( Graphics::ScreenHeight - 1 ) - height;
	}
}

void Player::ResetPlayer()
{
	// TODO: This will not work for long... better maintain it
	x = startingX;
	y = startingY;
}

Player::Player()
{
	x = startingX;
	y = startingY;
}

const float Player::GetX() const
{
	return x;
}

const float Player::GetY() const
{
	return y;
}

float Player::GetWidth() const
{
	return width;
}

float Player::GetHeight() const
{
	return height;
}

int Player::SetTimesReset( int newValue )
{
	return newValue;
}

void Player::UpdateInput( const Keyboard& kbd, float dt )
{
	if ( kbd.KeyIsPressed( VK_RIGHT ) )
	{
		x += playerSpeed * dt;
	}
	if ( kbd.KeyIsPressed( VK_LEFT ) )
	{
		x -= playerSpeed * dt;
	}
	if ( kbd.KeyIsPressed( VK_UP ) )
	{
		y -= playerSpeed * dt;
	}
	if ( kbd.KeyIsPressed( VK_DOWN ) )
	{
		y += playerSpeed * dt;
	}
}

void Player::DrawPlayer( Graphics & gfx ) const
{
	gfx.DrawRectDim( x, y, width, height, playerColor );
}
