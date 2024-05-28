#ifndef MAP_H
#define MAP_H

#include "defs.h"
#include "MapEditor.h"
#include "olcPixelGameEngine.h"

typedef struct BLock_infomation
{
	int blockid;
	float fheight;
	int northside, southside, westside, eastside,
		topside, bottomside;
	bool btransparent;

}block_info;

class Map
{
public:
	struct texturesOne
	{
		int one;
	};

	struct texturesTwo
	{
		int one, two;
	};
	
	struct texturesThree
	{
		int one, two, three;
	};

public:
	Map() = default;
	bool mapHasWallAt(    float x, float y );
	bool isInsideMap(     float x, float y );
	bool isOutSideMap(    float x, float y );
    bool isOnMapBoundary( float x, float y );   // Added Joseph21

	void renderMapGrid(olc::PixelGameEngine* PGEptr);

	int getFromHeightMap( int x, int y );
	void setTextures();

	int getTextureMap(    int x, int y, int Height);

	int gettexture(int x, int y,int layer);
	
	float FloatgetfromHeightmap(int x, int y);
	//new
	void addMapLayer( const std::string& sUserMap);
	void addTextures(const std::string& sUserTexture);
	void InitMap(int sizex, int sizey);
	std::vector<float*> fMaps;
	std::vector<std::string> sMaps;
	std::vector<int*> iTextures;
	std::vector<std::string> sTextures;
	
	//block type test
	std::vector<block_info> blocktypes;
	void initblocks();

	texturesOne layeronetextures[5];
	
	int MapX, MapY;
	int texturesize = 6;
	int totallayers = 3;
public:
#define BLOCK_TENTH '!'     // no block
#define BLOCK_TWENYTH '#'     // block of height 1
#define BLOCK_THRITY '@'     //                 2
#define BLOCK_FORTH '*'     //                 3
#define BLOCK_FIFTH '-'     //                 4
#define BLOCK_SIXTH '+'     //                 5
#define BLOCK_SEVENTH '='     //                 6

#define BLOCK_1QRTR 'Q'    // block of height 1/4
#define BLOCK_HALVE 'H'    //                 2/4
#define BLOCK_3QRTR 'T'   //                 3/4

#define BLOCK_BLANK '.'
#define BLOCK_ZERO '0'
#define BLOCK_ONE '1'
#define BLOCK_TWO '2'
#define BLOCK_THREE '3'
#define BLOCK_FOUR '4'
#define BLOCK_FIVE '5'

public:
	//map layout
	std::vector<std::string> Maplevels =
	{
		"11111111111111111111"
		"1..................1"
		"1..................1"
		"1..........###.....1"
		"1..........#.#.....1"
		"1..........#.#.....1"
		"1..........###.....1"
		"1..................1"
		"1..................1"
		"1...........####...1"
		"1...........#..#...1"
		"1...........####...1"
		"1..................1"
		"11111111111111111111",

		"...................."
		"...................."
		"...................."
		"...........###......"
		"...........#.#......"
		"...........#.#......"
		"...........###......"
		"...................."
		"...................."
		"............####...."
		"............#..#...."
		"............####...."
		"...................."
		"....................",

		"...................."
		"...................."
		"...................."
		"...................."
		"...................."
		"...................."
		"...................."
		"...................."
		"...................."
		"............####...."
		"............#..#...."
		"............####...."
		"...................."
		"...................."

	};

	//texture layout
	std::string Texture_levelOne =
	{
		"11111111111111111111"
		"10000000000000000001"
		"10000000000000000001"
		"10000000000555000001"
		"10000000000205000001"
		"10000000000505000001"
		"10000000000344000001"
		"20000000000000000001"
		"20000000000000000001"
		"20000000000024350001"
		"20000000000050050001"
		"20000000000054540001"
		"10000000000000000001"
		"11111111111111111111"
	};

	std::string Texture_levelTwo =
	{  
		"...................."
		"...................."
		"...................."
		"...........455......"
		"...........5.5......"
		"...........4.5......"
		"...........554......"
		"...................."
		"...................."
		"............4554...."
		"............5..5...."
		"............5455...."
		"...................."
		"...................."
	};

	std::string Texture_levelThree =
	{
		"...................."
		"...................."
		"...................."
		"...................."
		"...................."
		"...................."
		"...................."
		"...................."
		"...................."
		"............4555...."
		"............5..5...."
		"............5554...."
		"...................."
		"...................."
	};




	
};

#endif // !MAP_H


