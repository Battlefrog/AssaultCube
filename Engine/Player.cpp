#include "Player.h"

void Player::IsOutsideBoundries()
{
	const float right = x + float( width );
	const float bottom = y + float( height );

	if ( x < 0 )
	{
		x = 0;
	}
	else if ( right >= float( Graphics::ScreenWidth ) )
	{
		x = float( Graphics::ScreenWidth - 1 ) - float( width );
	}

	if ( y < 0 )
	{
		y = 0;
	}
	else if ( bottom >= float( Graphics::ScreenHeight ) )
	{
		y = float( Graphics::ScreenHeight - 1 ) - float( height );
	}
}

void Player::ResetPlayer()
{
	// TODO: This will not work for long... better maintain it
	playerRespawn.StopAll();
	x = respawnX;
	y = respawnY;
	playerRespawn.Play();
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

const float Player::GetRespawnX() const
{
	return respawnX;
}

const float Player::GetRespawnY() const
{
	return respawnY;
}

float Player::SetRespawnX( int newRespawnX )
{
	respawnX = newRespawnX;
	return respawnX;
}

float Player::SetRespawnY( int newRespawnY )
{
	respawnY = newRespawnY;
	return respawnY;
}

int Player::GetWidth() const
{
	return width;
}

int Player::GetHeight() const
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
		x += float( playerSpeed ) * dt;
	}
	if ( kbd.KeyIsPressed( VK_LEFT ) )
	{
		x -= float( playerSpeed ) * dt;
	}
	if ( kbd.KeyIsPressed( VK_UP ) )
	{
		y -= float( playerSpeed ) * dt;
	}
	if ( kbd.KeyIsPressed( VK_DOWN ) )
	{
		y += float( playerSpeed ) * dt;
	}
}

void Player::DrawPlayer( Graphics & gfx ) const
{
	gfx.DrawRectDim( int( x ), int( y ), width, height, playerColor );
}
