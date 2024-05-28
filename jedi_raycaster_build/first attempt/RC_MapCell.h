#ifndef RC_MAPCELL_H
#define RC_MAPCELL_H
#include "RC_Face.h"

typedef struct sMapCellBluePrintStruct
{
	char cID;
	float fHeight;
	int nFaces[FACE_NR_OF];

	bool bPermeable = false;
} MapCellBluePrint;


extern std::vector<MapCellBluePrint> vInitMapCellBluePrints;
extern std::map<char, MapCellBluePrint> nMapCellBluePrintLib;

void AddMapCellBluePrint(char cID, float fH, int nE, int nN, int nW, int nS, int nT, int nB, bool bP = false);

void InitMapCellBluePrints();

MapCellBluePrint& GetMapCellBluePrint(char cID);

char GetMapCellBPID(MapCellBluePrint& b);
float GetMapCellBPHeight(MapCellBluePrint& b);
int GetMapCellBPFaceIx(MapCellBluePrint& b, int nFace);


class RC_MapCell
{
protected:
	int x, y, level;
	char id = '.';
	float height = 0.0f;
	bool bEmpty = true;

	RC_Face* pFaces[FACE_NR_OF] = { nullptr };
	bool bPermeable = false;

public:
	RC_MapCell();
	virtual ~RC_MapCell();

	virtual void Init(int px, int py, int l);
	void SetX(int px);
	void SetY(int py);
	void SetLevel(int nLevel);

	int GetX();
	int GetY();
	int GetLevel();

	virtual void Update(float fElapsedTime, bool& bPermFlag);

	virtual olc::Pixel Sample(int nFaceIx, float sX, float sY);

	char GetID();
	void SetID(char cID);

	float GetHeight();
	void SetHeight(float fH);

	virtual bool IsEmpty();
	bool IsPermeable();

	void SetEmpty(bool bParam = true);
	void SetPermeable(bool bParam = true);

	void SetFacePtr(int nFaceIx, RC_Face* pFace);
	RC_Face* GetFacePtr(int nFaceIx);



};
#endif // !RC_MAPCELL_H





