#pragma once
#include "Scene.h"
#include "Label.h"
#include "Sprite.h"
#include "Director.h"
#include "Player.h"
#include "Map.h"
#include "Enemy.h"
#include "Bullet.h"
#include "Camera.h"
// remove position camera
class MainScene :
	public Scene
{
public:
	void Init() override;
	void Update() override;
	void OnExit() override;



	Player* P;
	Map* map;
	list<Enemy*> _enemys;

	void LabelRender();

	Label* timerFont;
	int time;
	float timer;

	Label* ScoreFont;

};

