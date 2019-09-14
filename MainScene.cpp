#include "DXUT.h"
#include "MainScene.h"
//카메라 완성
void MainScene::Init()
{


	map = new Map(L"ground.png");
	map->LoadMap();
	this->AddChild(map, 1);


	P = new Player(map);
	this->AddChild(P, 2);

	Camera::GetInstance()->CameraInit();
	Camera::GetInstance()->Follow(P);
	Bullet_Manager::GetInstance()->Make_Bullet(map);

	


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
	Camera::GetInstance()->Update();
	Camera::GetInstance()->SetTransform();
	Camera::GetInstance()->SetPos({ P->_position.x + 480 ,P->_position.y - 180 });


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
		timerFont->Create_Label(time, { 100,50 });
		timer = 1;
	}

	//ScoreFont->Create_Label(GameManager::GetInstance()->Score, { 100,50 });
}
