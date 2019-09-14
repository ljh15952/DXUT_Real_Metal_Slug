#pragma once
#include "Sprite.h"
class Map :
	public Sprite
{
public:
	Map(wstring filename);
	~Map();

	vector2 movepos;
	void LoadMap();
	int width, height;
	vector<vector<COLOR>> _mapData;

	void Update() override;

};

