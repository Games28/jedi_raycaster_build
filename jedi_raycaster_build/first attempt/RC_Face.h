#ifndef RC_FACE_H
#define RC_FACE_H
#include "olcPixelGameEngine.h"
#include "defs.h"


typedef struct sFaceBluePrintStruct
{
	int nID;
	int nFaceType;
	int nFaceIndex;
	bool bTransparent = false;
	bool bAnimated = false;

}FaceBluePrint;

extern std::vector<FaceBluePrint> vInitFaceBluePrints;

extern std::vector<FaceBluePrint> vFaceBluePrintLib;

void AddFaceBluePrint(int nID, int nType, int nIndex, bool bT = false, bool bA = false);

void InitFaceBluePrints();





class RC_Face
{
protected:
	int nFaceIndex;
	olc::Sprite* pSprite = nullptr;
	bool bTransparent = false;

public:
	RC_Face();
	~RC_Face();

	void Init(int nFaceIx, olc::Sprite* sprPtr, bool bTransp = false);

	int GetIndex();
	void SetIndex(int nIndex);

	olc::Sprite* GetTexture();
	void SetTexture(olc::Sprite* sprPtr);

	virtual bool IsTextured();
	virtual bool IsAnimated();

	bool isTranparent();
	void SetTranparent(bool bParam = true);

	virtual void Update(float fElapsedTime, bool& bPermFlag);
	virtual olc::Pixel Sample(float sX, float sY);

};


class RC_FaceAnimated : public RC_Face
{
protected:
	int state;
	int tileWidth, tileHeight;
	int tileX, tileY;

	float fTimer, fThreshold;
	int nCounter, nThreshold;

public:
	RC_FaceAnimated();

	void Init(int nFaceIx, olc::Sprite* sprPtr, bool bTransp, int s, int tw, int th);

	virtual bool IsTextured();
	virtual bool IsAnimated();

	int GetState();
	void SetState(int newState);

	void Update(float fElapsedTime, bool& bPermable);

	olc::Pixel Sample(float sX, float sY);

};


#endif // !RC_FACE_H


