#include "RC_Face.h"

RC_Face::RC_Face() {}

RC_Face::~RC_Face() {}

void RC_Face::Init(int nFaceIx, olc::Sprite* sprPtr, bool bTransp)
{
	nFaceIndex = nFaceIx;
	pSprite = sprPtr;
	bTransparent = bTransp;
}

int RC_Face::GetIndex()
{
	return nFaceIndex;
}

void RC_Face::SetIndex(int nIndex)
{
	nFaceIndex = nIndex;
}

olc::Sprite* RC_Face::GetTexture()
{
	return pSprite;
}

void RC_Face::SetTexture(olc::Sprite* sprPtr)
{
	pSprite = sprPtr;
}

bool RC_Face::IsTextured()
{
	return true;
}

bool RC_Face::IsAnimated()
{
	return false;
}

bool RC_Face::isTranparent()
{
	return bTransparent;
}

void RC_Face::SetTranparent(bool bParam)
{
	bTransparent = bParam;
}

void RC_Face::Update(float fElapsedTime, bool& bPermFlag) {}

olc::Pixel RC_Face::Sample(float sX, float sY)
{
	if (pSprite == nullptr)
	{
		std::cout << "error: sample() --> nullptr sprite ptr encountered" << std::endl;
		return olc::MAGENTA;
	}

	return pSprite->Sample(sX,sY);
}

RC_FaceAnimated::RC_FaceAnimated() {}

void RC_FaceAnimated::Init(int nFaceIx, olc::Sprite* sprPtr, bool bTransp, int s, int tw, int th)
{
	nFaceIndex = nFaceIx;
	pSprite = sprPtr;
	bTransparent = bTransp;
	state = s;
	tileWidth = tw;
	tileHeight = th;

	SetState(state);

	fTimer = fThreshold = 0.0f;
	nCounter = nThreshold = 0;
}

bool RC_FaceAnimated::IsTextured()
{
	return false;
}

bool RC_FaceAnimated::IsAnimated()
{
	return true;
}

int RC_FaceAnimated::GetState()
{
	return state;
}

void RC_FaceAnimated::SetState(int newState)
{
	state = newState;
	//hardcoded for now
	switch (state) {
	case ANIM_STATE_CLOSED: tileX = 0; tileY = 0; fTimer = 0.0f; fThreshold = 0.0f; nCounter = 0; nThreshold = 1; break;
	case ANIM_STATE_OPENED: tileX = 7; tileY = 0; fTimer = 0.0f; fThreshold = 0.0f; nCounter = 0; nThreshold = 1; break;

	case ANIM_STATE_CLOSING: tileX = 7; tileY = 0; fTimer = 0.0f; fThreshold = 0.10f; nCounter = 0; nThreshold = 8; break;
	case ANIM_STATE_OPENING: tileX = 0; tileY = 0; fTimer = 0.0f; fThreshold = 0.10f; nCounter = 0; nThreshold = 8; break;
	}
}

void RC_FaceAnimated::Update(float fElapsedTime, bool& bPermable)
{
	fTimer += fElapsedTime;
	if (fTimer >= fThreshold)
	{
		fTimer -= fThreshold;

		nCounter += 1;
		if (nCounter == nThreshold)
		{
			nCounter = 0;
			switch (state)
			{
			case ANIM_STATE_CLOSED:
			{

			}break;

			case ANIM_STATE_OPENED:
			{

			}break;

			case ANIM_STATE_CLOSING:
			{
				SetState(ANIM_STATE_CLOSED);
			}break;

			case ANIM_STATE_OPENING:
			{
				SetState(ANIM_STATE_OPENED);
				bPermable = true;

			}break;
			}
		}
		else
		{
			switch (state)
			{
			case ANIM_STATE_CLOSED:
			{

			}break;
			case ANIM_STATE_OPENED:
			{

			}break;

			case ANIM_STATE_CLOSING:
			{
				tileX -= 1;
				bPermable = false;

			}break;

			case ANIM_STATE_OPENING:
			{
				tileX += 1;

			}break;
			}
		}

	}
}

olc::Pixel RC_FaceAnimated::Sample(float sX, float sY)
{
	if (pSprite == nullptr)
	{
		std::cout << "warning sample() -> nullptr sprite ptr encountered" << std::endl;
		return olc::MAGENTA;
	}
	else
	{
		float fx0 = float((tileX + sX) * tileWidth) / pSprite->width;
		float fy0 = float((tileY + sY) * tileHeight) / pSprite->height;

		return pSprite->Sample(fx0, fy0);
	}
}


