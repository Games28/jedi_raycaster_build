#include "Player.h"

void Player::initPlayer(olc::PixelGameEngine* pge)
{
	x = pge->ScreenWidth() / 2;
	y = pge->ScreenHeight() / 2;
	width = 5;
	height = 5;
	turnDirection = 0;
	walkDirection = 0;
	rotationAngle = 0;
	walkSpeed = 100;
	turnSpeed = 45 * (PI / 180.0f);
	strafeLeft = true;
	strafeRight = true;
	strafedirection = 0;
	frun = 1;
	lookspeed = 200.0f;
	lookupordown = 0;
	vertlook = 0;
	strafeupspeed = 1.0f;
	fPlayerH = 0.5f;
	lookvert = false;
	movevert = false;
	rotatebefore = 0.0f;
	rotateafter = 0.0f;
	movementbefore = { 0.0f,0.0f };
	movementafter = { 0.0f,0.00f };
	movedifference = { 0.0f, 0.0f };
	strafeafter = { 0.0f,0.0f };
	strafebefore = { 0.0f,0.0f };
	strafedifference = { 0.0f,0.0f };
}

void Player::processInput(olc::PixelGameEngine* pge, float deltatime, RC_Map& map)
{
	if (pge->GetKey(olc::W).bHeld)
	{
		walkDirection = +1;
	}

	if (pge->GetKey(olc::S).bHeld)
	{
		walkDirection = -1;
	}

	if (pge->GetKey(olc::Q).bHeld)
	{
		strafeLeft = true;
		strafedirection = +1;
	}


	if (pge->GetKey(olc::E).bHeld)
	{
		strafeRight = true;
		strafedirection = -1;
	}


	if (pge->GetKey(olc::D).bHeld)
	{
		turnDirection = +1;
	}

	if (pge->GetKey(olc::A).bHeld)
	{
		turnDirection = -1;
	}

	if (pge->GetKey(olc::SHIFT).bHeld)
	{
		frun = 3;
	}


	if (pge->GetKey(olc::W).bReleased)
	{
		walkDirection = 0;
	}

	if (pge->GetKey(olc::S).bReleased)
	{
		walkDirection = 0;
	}

	if (pge->GetKey(olc::Q).bReleased)
	{

		strafedirection = 0;
	}

	if (pge->GetKey(olc::E).bReleased)
	{

		strafedirection = 0;
	}

	if (pge->GetKey(olc::D).bReleased)
	{
		turnDirection = 0;
	}

	if (pge->GetKey(olc::A).bReleased)
	{
		turnDirection = 0;
	}
	if (pge->GetKey(olc::SHIFT).bReleased)
	{
		frun = 1;
	}
}

void Player::movePlayer(olc::PixelGameEngine* pge, float deltatime, RC_Map& map)
{
}
