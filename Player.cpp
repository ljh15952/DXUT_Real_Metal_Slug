#include "DXUT.h"
#include "Player.h"
#include "Director.h"
#include "Bullet.h"
Player::Player(Map* map)
{
	Create(L"Tank_1.png");
	_position = { 150,500 };

	MovePos = { _position.x,_position.y };

	_map = map;


	SetSpeed(200);

	p[0].y = _map->height - 1;
	p[1].y = _map->height - 1;
	v[0] = v[1] = { 0,0 };
	g = { 0,10 };


	po = new Sprite;
	po->Create(L"arm.png");
	po->_pivot = { 0.2f,0.2f };
	po->_position.x = 130;

	shotPos = new Sprite;
	shotPos->Create(L"UFO_1.png");
	shotPos->_scale = { 0.3f,0.3f };

	

	_jumppos = 80;
	_mytpye = t_tank;

	movetpye = true;
	isscreenstop = false;
	End_X_pos = 400;

	arms_font = new Label;
	bomb_font = new Label;
	arms = 100;
	bomb = 10;
	FontRender();

}

void Player::Update()
{
	Movement();
	p[0].x =  _position.x - 20;
	p[1].x =  _position.x + 20;
	for (int i = 0; i < 2; i++)
	{
		p[i] += v[i] * _jumppos * Time::deltaTime;
		v[i] += g * Time::deltaTime;
		if (_map->_mapData[int(p[i].x)][int(p[i].y)].a > 0)
		{
			int y = p[i].y;
			while (_map->_mapData[int(p[i].x)][y].a > 0)
			{
				y -= 1;
			}
			p[i].y = y + 1;
			v[i] = { 0,0 };
		}
	}

	cout << _position.x << endl;
	po->_position = _position;
	po->_position.y += 7;
	po->_position.x -= 20;
	vector2 dif2 = vector2(Director::GetInstance()->p.x - MovePos.x, Director::GetInstance()->p.y - MovePos.y);
	float size = sqrt(dif2.x * dif2.x + dif2.y * dif2.y);
	dif2.x /= size;
	dif2.y /= size;
	po->_rotation = atan2(dif2.y, dif2.x);

	vector2 _pos = po->_position + dif2 * 80;
	shotPos->_position = _pos;

	_shotpower = dif2 * 7.5f;


}

void Player::Movement()
{
	if (!isscreenstop)
	{
		End_X_pos > _position.x ? movetpye = true : movetpye = false;

		if (DXUTIsKeyDown('D') || _position.x < 50)
		{
		//	movetpye ? _position.x += Time::deltaTime * GetSpeed() : _map->_position.x -= Time::deltaTime * GetSpeed();
			_position.x += Time::deltaTime * GetSpeed();
		}
		if (DXUTIsKeyDown('A'))
		{
			_position.x -= Time::deltaTime * GetSpeed();
		}
	}
	else
	{
		if (DXUTIsKeyDown('D') || _position.x < 50)
		{
			_position.x += Time::deltaTime * GetSpeed();
		}
		if (DXUTIsKeyDown('A') || _position.x > 1200)
		{
			_position.x -= Time::deltaTime * GetSpeed();
		}
	}

	if (DXUTIsKeyDown('W'))
	{
		v[0].y = v[1].y = -5.5;
	}

	_position.y = (p[0] + p[1]).y / 2 - 50;
	auto dif = p[1] - p[0];
	float l = atan2(dif.y, dif.x);
	_rotation = l;
}

void Player::Shot()
{
	cout << "SHOT!!" << endl;
	FontRender();
	Bullet_Manager::GetInstance()->Shot_Bullet(shotPos->_position, _shotpower, t_one, t_tank);
	arms--;
}

void Player::isHit()
{
	cout << "PLAYER HIT!!!";
}

void Player::FontRender()
{
	arms_font->Create_Label(arms, { 500,50 });
	bomb_font->Create_Label(bomb, { 400,50 });
}
