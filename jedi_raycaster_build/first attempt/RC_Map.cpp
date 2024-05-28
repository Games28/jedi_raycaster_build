#include "RC_Map.h"

RC_Map::RC_Map()
{
}

RC_Map::~RC_Map()
{
}

void RC_Map::InitMap(int nSizeX, int nSizeY)
{
	nMapX = nSizeX;
	nMapY = nSizeY;
}

void RC_Map::AddLayer(const std::string& sUserMap, std::vector<olc::Sprite*> vWallTextures, std::vector<olc::Sprite*> vCeilTextures, std::vector<olc::Sprite*> vRoofTextures)
{
	if (nMapX * nMapY != (int)sUserMap.length())
	{
		std::cout << "error initmap() -> mismatch between map dimensions and length of map string" << std::endl;
	}
	
	std::vector<RC_MapCell*> vLlevelMapCells; // contains all blocks on each level
	RC_MapCell* pMapCellptr = nullptr; // contains info for every single block that goes in to vlLevelsmapcells

	int nCntRefTransp = 0;
	int nCntFceTransp = 0;

	for (int y = 0; y < nMapY; y++)
	{
		for (int x = 0; x < nMapX; x++)
		{
			char cTileID = sUserMap[y * nMapX + x];
			MapCellBluePrint& refMapCell = GetMapCellBluePrint(cTileID);

			pMapCellptr = new RC_MapCell;
			pMapCellptr->Init(x, y, (int)bMaps.size());
			pMapCellptr->SetID(refMapCell.cID);
			pMapCellptr->SetHeight(refMapCell.fHeight);
			pMapCellptr->SetPermeable(refMapCell.bPermeable);

			if (cTileID == '.')
			{
				pMapCellptr->SetEmpty(true);
			}
			else
			{
				pMapCellptr->SetEmpty(false);

				for (int i = 0; i < FACE_NR_OF; i++)
				{
					int nFaceBPIx = refMapCell.nFaces[i];
					FaceBluePrint& refFace = vFaceBluePrintLib[nFaceBPIx];
					nCntRefTransp += (refFace.bTransparent ? 1 : 0);

					olc::Sprite* auxSpritePtr = nullptr;

					switch (refFace.nFaceType)
					{
					case TYPE_FACE_WALL:
					{
						auxSpritePtr = vWallTextures[refFace.nFaceIndex];
					}break;
					case TYPE_FACE_CEIL:
					{
						auxSpritePtr = vCeilTextures[refFace.nFaceIndex];
					}break;
					case TYPE_FACE_ROOF:
					{
						auxSpritePtr = vRoofTextures[refFace.nFaceIndex];
					}break;
					default:
					{
						std::cout << "error addlayer()-> face type unknown " << refFace.nFaceType << std::endl;
					}
					}


					if (refFace.bAnimated)
					{
						RC_FaceAnimated* auxPtr = new RC_FaceAnimated;
						auxPtr->Init(i, auxSpritePtr, refFace.bTransparent, ANIM_STATE_CLOSED, 32, 32);
						pMapCellptr->SetFacePtr(i, auxPtr);
					}
					else
					{
						RC_Face* pFacePtr = new RC_Face;
						pFacePtr->Init(i, auxSpritePtr, refFace.bTransparent);
						pMapCellptr->SetFacePtr(i, pFacePtr);
					}

					nCntFceTransp += (pMapCellptr->GetFacePtr(i)->isTranparent() ? 1 : 0);
				}
			}

			vLlevelMapCells.push_back(pMapCellptr);
		}
	}

	bMaps.push_back(vLlevelMapCells); //all map levels
}

void RC_Map::FinalizeMap()
{
	for (auto& elt : bMaps)
	{
		elt.clear();
	}
	bMaps.clear();

}

int RC_Map::Width()
{
	return nMapX;
}

int RC_Map::Height()
{
	return nMapY;
}

bool RC_Map::isInsideMap(float x, float y)
{
	return floatGrtEqual(x, 0.0f) && floatLssEqual(x, nMapX * TILE_SIZE) &&
		floatGrtEqual(y, 0.0f) && floatLssEqual(y, nMapY * TILE_SIZE);
}

bool RC_Map::isOnMapBoudary(float x, float y)
{
	return floatEqual(x, 0.0f) || floatEqual(x, nMapX * TILE_SIZE) ||
		floatEqual(y, 0.0f) || floatEqual(y, nMapY * TILE_SIZE);
}


float RC_Map::CellHeight(int x, int y)
{
	return 0.0f;
}

float RC_Map::CellHeightAt(int x, int y, int level)
{
	float result = -1.0f;

	result = bMaps[level][y * nMapX + x]->GetHeight();
	return result;
}

char RC_Map::CellValueAt(int x, int y, int level)
{
	char result = ' ';

	result = bMaps[level][y * nMapX + x]->GetID();
	return result;
}

RC_MapCell* RC_Map::MapCellPtrAt(int x, int y, int level)
{
	RC_MapCell* result = nullptr;

	result = bMaps[level][y * nMapX + x];
	return result;
}

float RC_Map::DiagonalLength()
{
	return sqrt(nMapX * nMapX + nMapY * nMapY);
}

int RC_Map::NrOfLayers()
{
	return 0;
}

bool RC_Map::collides(float fx, float fy, float fh, float fr, float fvx, float fvy)
{
	return false;
}
