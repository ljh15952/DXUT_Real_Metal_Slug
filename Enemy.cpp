#include "DXUT.h"
#include "Enemy.h"
#include "Bullet.h"
Enemy::Enemy(Map* _map, vector2 movepos)
{
	Create(L"UFO_1.png");
	_position = { 700,200 };
	MovePos = movepos;
	_mytpye = t_ufo;
	map = _map;
}

Enemy::~Enemy()
{
}

void Enemy::Update()
{
	static float timer = 0;
	timer += Time::deltaTime;
	MovePos.x += 0.5f;
	_position.x = map->_position.x + MovePos.x;
	if (timer > 0.3f)
	{
		Shot();
		timer = 0;
	}
}

void Enemy::Movement()
{
}

void Enemy::Shot()
{
	Bullet_Manager::GetInstance()->Shot_Bullet(_position, vector2(0, 1), t_one, t_ufo);
}

void Enemy::isHit()
{
	cout << "HIT UFO" << endl;
}
