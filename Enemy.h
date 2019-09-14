#pragma once
#include "Obj.h"
#include "Map.h"
class Enemy :
	public Obj
{
public:
	Enemy(Map* map, vector2 movepos);
	~Enemy();

	void Update() override;
	void Movement() override;
	void Shot() override;
	void isHit() override;

	Map* map;
};

