#pragma once
#include "Obj.h"
#include "Map.h"
#include "Label.h"
class Player : public Obj
{
public:
	Player(Map* map);

	void Update() override;
	void Movement() override;
	void Shot() override;
	void isHit() override;

	vector2 p[2];
	vector2 v[2];
	vector2 g;

	Map* _map;

	float _jumppos;

	Sprite* po;
	Sprite* shotPos;

	vector2 _shotpower;

	bool movetpye; //true는 자기가 움직이고 false 카메라가 움직임
	float End_X_pos;


	Label* arms_font;
	Label* bomb_font;

	vector2 MovePos;
	
	int arms;
	int bomb;

	void FontRender();

	bool isscreenstop;
};

