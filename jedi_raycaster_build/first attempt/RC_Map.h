#ifndef RC_MAP_H
#define RC_MAP_H
#include "RC_MapCell.h"

class RC_Map
{
private:
	int nMapX;
	int nMapY;
	std::vector<std::vector<RC_MapCell*>> bMaps;


public:

	RC_Map();
	~RC_Map();

	void InitMap(int nSizeX, int nSizeY);
	void AddLayer(const std::string& sUserMap, std::vector<olc::Sprite*> vWallTextures,
		std::vector<olc::Sprite*> vCeilTextures,
		std::vector<olc::Sprite*> vRoofTextures);

	void FinalizeMap();

	int Width();
	int Height();

	bool isInsideMap(float x, float y);
	bool isOnMapBoudary(float x, float y);

	float CellHeight(int x, int y);
	float CellHeightAt(int x, int y, int level);
	char CellValueAt(int x, int y, int level);
	RC_MapCell* MapCellPtrAt(int x, int y, int level);
	float DiagonalLength();
	int NrOfLayers();
	bool collides(float fx, float fy, float fh, float fr, float fvx, float fvy);

#define F_EPSILON   0.0001f    // error margin for comparing floats

	bool floatEqual(float a, float b) { return abs(a - b) < F_EPSILON; }
	bool floatGrtEqual(float a, float b) { return  floatEqual(a, b) || a > b; }
	bool floatLssEqual(float a, float b) { return  floatEqual(a, b) || a < b; }
	bool floatGreater(float a, float b) { return !floatEqual(a, b) && a > b; }
	bool floatLess(float a, float b) { return !floatEqual(a, b) && a < b; }

};

#endif // !RC_MAP_H



