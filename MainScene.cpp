#include "DXUT.h"
#include "MainScene.h"
//카메라 완성
void MainScene::Init()
{
	/*S = new Sprite;
	S->Create(L"soldier1_gun.png");
	S->_position = { 640,360 };

	S1 = new Sprite;
	S1->Create(L"soldier1_gun.png");
	S1->_position = { 140,160 };

	C = new Camera();

	C->Follow(S);*/

	map = new Map(L"ground.png");
	map->LoadMap();
	this->AddChild(map, 1);
	Bullet_Manager::GetInstance()->Make_Bullet(map);

	P = new Player(map);
	this->AddChild(P, 2);


	for (int i = 0; i < 1; i++)
	{
		Enemy* E1 = new Enemy(map, { (float)(i * 500) + 500 ,0 });
		this->AddChild(E1, 3);
		_enemys.push_back(E1);
	}

	timerFont = new Label;
	time = 60;
	timer = 1;

	ScoreFont = new Label;
}

void MainScene::Update()
{
	/*if (DXUTIsKeyDown('W'))
		S->_position.y -= 10;
	if (DXUTIsKeyDown('S'))
		S->_position.y += 10;
	if (DXUTIsKeyDown('A'))
		S->_position.x -= 10;
	if (DXUTIsKeyDown('D'))
		S->_position.x += 10;

	C->Update();
	C->SetTransform();*/

	LabelRender();

	if (Director::GetInstance()->OnMouseDown())
	{
		P->Shot();
	}
	else if (Director::GetInstance()->OnMouse())
	{
	}



	for (auto it : Bullet_Manager::GetInstance()->_bullets)
	{
		if (it->_visible)
		{
			it->CollideBullet(P);

			for (auto it2 : _enemys)
			{
				it->CollideBullet(it2);
			}

		}
	}



}

void MainScene::OnExit()
{
}

void MainScene::LabelRender()
{
	timer -= Time::deltaTime;
	if (timer < 0)
	{
		time--;
		timerFont->Create_Label(time, { 640,50 });
		timer = 1;
	}

	//ScoreFont->Create_Label(GameManager::GetInstance()->Score, { 100,50 });
}
