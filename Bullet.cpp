#include "DXUT.h"
#include "Bullet.h"

void Bullet_Manager::Make_Bullet(Map* map)
{
	for (int i = 0; i < 100; i++)
	{
		Bullet* b = new Bullet(map);
		//	map->AddChild(b, 3);
		_bullets.push_back(b);
	}
}

void Bullet_Manager::Shot_Bullet(vector2 startpos, vector2 shotpower, t_shot_type shot_tpye, t_obj_type obj_type)
{
	for (auto it : _bullets)
	{
		if (!it->_visible)
		{
			it->shotpos = startpos + it->_map->_position * -1;
			it->_position = startpos;
			it->v = shotpower;
			it->_visible = true;
			it->mytype = obj_type;
			return;
		}
	}
}
void Bullet_Manager::Delete_Bullet()
{
	for (auto it : _bullets)
		delete it;
	_bullets.clear();
}

Bullet::Bullet(Map* map)
{
	Create(L"Weapon.png");
	_map = map;
	_visible = false;
}

Bullet::~Bullet()
{
}

void Bullet::Update()
{
	if (!_visible)
		return;

	shotpos += v * Time::deltaTime * 100;
	v += Time::deltaTime * g;
	//cout << _map->_position.x * -1<< endl;
	//_position += v * Time::deltaTime * 100;
	_position = shotpos - _map->_position * -1;
	_rotation = atan2(v.y, v.x);


	//if(_position.x < 0)
	//{
	//	_visible = false;
	//	return;
	//}

	if (_map->_mapData[shotpos.x][shotpos.y].a > 0)
	{
		_visible = false;
	}
}

void Bullet::CollideBullet(Obj* obj)
{
	RECT TEMP;
	if (!IntersectRect(&TEMP, &GetRect(), &obj->GetRect()))
		return;

	if (obj->_mytpye == mytype)
		return;
	obj->isHit();
	_visible = false;
}
