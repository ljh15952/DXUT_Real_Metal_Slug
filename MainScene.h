#pragma once
#include "Scene.h"
#include "Label.h"
#include "Sprite.h"
#include "Director.h"
#include "Player.h"
#include "Map.h"
#include "Enemy.h"
#include "Bullet.h"
class MainScene :
	public Scene
{
public:
	void Init() override;
	void Update() override;
	void OnExit() override;

	/*Camera* C;
	Sprite* S;
	Sprite* S1;*/


	Player* P;
	Map* map;
	list<Enemy*> _enemys;

	void LabelRender();

	Label* timerFont;
	int time;
	float timer;

	Label* ScoreFont;

};

