#include "DXUT.h"
#include "Map.h"

Map::Map(wstring filename)
{
	Create(filename);
	_pivot = { 0,0 };
	width = 0;
	height = 0;
}

Map::~Map()
{
}

void Map::LoadMap()
{
	_mapData.clear();

	width = texture->_info.Width;
	height = texture->_info.Height;

	for (int i = 0; i < width; i++)
	{
		_mapData.push_back(vector<COLOR>(height));
	}

	D3DLOCKED_RECT LockRect;

	texture->_texture->LockRect(0, &LockRect, 0, D3DLOCK_DISCARD);
	DWORD* pColor = (DWORD*)LockRect.pBits;

	for (int y = 0; y < height; ++y)
	{
		for (int x = 0; x < width; ++x)
		{
			int nIdx = y * width + x;
			_mapData[x][y] = pColor[nIdx];
		}
	}

	texture->_texture->UnlockRect(0);
}

void Map::Update()
{

}
