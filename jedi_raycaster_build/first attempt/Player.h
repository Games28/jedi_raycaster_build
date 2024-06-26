#ifndef PLAYER_H
#define PLAYER_H
#include "olcPixelGameEngine.h"
#include "defs.h"
#include "RC_Map.h"

class Player
{
public:
	Player() = default;
	void initPlayer(olc::PixelGameEngine* pge);
	void processInput(olc::PixelGameEngine* pge, float deltatime, RC_Map& map);
	void movePlayer(olc::PixelGameEngine* pge, float deltatime, RC_Map& map);

public:
	float x;
	float y;
	float width;
	float height;
	int turnDirection; // -1 for left, +1 for right
	int walkDirection; // -1 for back, +1 for front
	float rotationAngle;
	float walkSpeed;
	float turnSpeed;

	bool strafeLeft;
	bool strafeRight;
	int strafedirection;
	int frun;
	float lookupordown;
	float lookspeed;
	float vertlook;
	float strafeupspeed;
	float fPlayerH;
	bool movevert;
	bool lookvert;
	float strafePlayerX = 0;
	float strafePlayerY = 0;

	float rotatebefore;
	float rotateafter;
	float rotationdifference;

	olc::vf2d movementbefore;
	olc::vf2d movementafter;
	olc::vf2d movedifference;

	olc::vf2d strafebefore;
	olc::vf2d strafeafter;
	olc::vf2d strafedifference;
};

#endif // !PLAYER_H


