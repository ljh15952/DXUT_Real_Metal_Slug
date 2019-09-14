#pragma once
#include "Sprite.h"
class Obj : public Sprite
{
public:
	void SetHp(int num) { _Hp = num; };
	void AddHp(int num) { _Hp += num; };
	int GetHp() { return _Hp; };

	void SetSpeed(int num) { _speed = num; };
	void AddSpeed(int num) { _speed += num; };
	int GetSpeed() { return _speed; };

	virtual void isHit() {};
	virtual void Movement() {};
	virtual void Shot() {};


	t_shot_type _shottype;
	t_obj_type _mytpye;
private:
	int _Hp;
	float _speed;
};
