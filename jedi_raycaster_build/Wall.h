#ifndef WALL_H
#define WALL_H

#include "olcPixelGameEngine.h"

#include "Player.h"
#include "Raycast.h"
#include "defs.h"
#include "Map.h"





class Wall
{

public:

	enum Side
	{
		Default,
		Top,
		Bottom,
		WalL,
		Roof
	};

public:
	Wall() = default;
	void wallTextures();
	void changeColorIntensity(olc::Pixel& p, float factor);
	void calculateBottomAndTop(float wallDistance,int halfheight, float wallheight, int& wallceil, int& wallfloor, Player& player);
	olc::Pixel SelectSceneryPixel( int textureid, float samplex, float sampley, float distance,Side side);
	void renderWallProjection(olc::PixelGameEngine* PGEptr, Player& player, Raycast& rays, Map& map);
	int getTexture(int x,int y, int& id, Map& map);
public:
	std::vector<olc::Sprite*> wallSprites;
	int text = 0;
	int time = 0;

	int nTestRay = NUM_RAYS / 2;
	float fTestRay = 0.5f;
	Side side = Side::Default;

public:

	std::vector<std::string> WallSpritesFiles =
	{
		"scenery/tatooinewindow1.png",
		"scenery/stonewall.png",
		"scenery/graystone.png",
		"scenery/tatooinewindow2.png",
		"scenery/window1.png",
		"scenery/wood.png",
		"scenery/wall3.png",
		"scenery/bluestone.png",
		"scenery/colorstone.png"
	};
};

#endif // !WALL_H


