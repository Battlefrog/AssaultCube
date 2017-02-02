#include "Player.h"

void Player::IsOutsideBoundries()
{
	const int right = x + width;
	const int bottom = y + height;

	if (x < 0)
	{
		x = 0;
	}
	else if (right >= Graphics::ScreenWidth)
	{
		x = (Graphics::ScreenWidth - 1) - width;
	}

	if (y < 0)
	{
		y = 0;
	}
	else if (bottom >= Graphics::ScreenHeight)
	{
		y = (Graphics::ScreenHeight - 1) - height;
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

int Player::GetX() const
{
	return x;
}

int Player::GetY() const
{
	return y;
}

int Player::GetWidth() const
{
	return width;
}

int Player::GetHeight() const
{
	return height;
}

void Player::UpdateInput(const Keyboard & kbd)
{
	if (kbd.KeyIsPressed(VK_RIGHT))
	{
		x += playerSpeed;
	}
	if (kbd.KeyIsPressed(VK_LEFT))
	{
		x -= playerSpeed;
	}
	if (kbd.KeyIsPressed(VK_UP))
	{
		y -= playerSpeed;
	}
	if (kbd.KeyIsPressed(VK_DOWN))
	{
		y += playerSpeed;
	}
}

void Player::DrawPlayer(Graphics & gfx) const
{
	gfx.DrawRectDim(x, y, width, height, playerColor);
}
