#pragma once
#include "Sprite.h"
#include "Map.h"
#include "Types.h"
#include "Obj.h"
class Bullet :
	public Sprite
{
public:
	Bullet(Map* map);
	~Bullet();

	void Update() override;
	void CollideBullet(Obj* obj);
	t_obj_type mytype;
	Map* _map;
	vector2 v;
	vector2 g = { 1,9.81f };
	vector2 shotpos;
};

class Bullet_Manager : public Singleton<Bullet_Manager>
{
public:
	void Make_Bullet(Map* map);
	void Shot_Bullet(vector2 startpos, vector2 shotpower, t_shot_type shot_tpye, t_obj_type obj_type);
	void Delete_Bullet();
	list<Bullet*> _bullets;
};