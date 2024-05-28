#ifndef RAYCAST_H
#define RAYCAST_H
#include "olcPixelGameEngine.h"
#include "defs.h"
#include "RC_Map.h"



typedef struct sIntersectInfo
{
	float fHitX, fHitY;
	int nMapCoordX, nMapCoordY;
	float fDistFront, fDistBack;
	float fHeight;
	int nLevel = -1;

	int bottom_front = -1;
	int Bottom_back = -1;
	int top_front = -1;
	int top_back = -1;

	int nFaceHit = FACE_UNKNOWN;

	bool rayUp, rayDn, rayLt, rayRt;
}IntersectInfo;


class Raycast
{
	Raycast() = default;
	void castRay();
};


#endif // !RAYCAST_H



