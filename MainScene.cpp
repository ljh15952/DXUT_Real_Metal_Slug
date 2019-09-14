#include "DXUT.h"
#include "MainScene.h"
//카메라 완성
void MainScene::Init()
{
	S = new Sprite;
	S->Create(L"soldier1_gun.png");
	S->_position = { 640,360 };

	S1 = new Sprite;
	S1->Create(L"soldier1_gun.png");
	S1->_position = { 140,160 };

	C = new Camera();

	C->Follow(S);
}

void MainScene::Update()
{
	if (DXUTIsKeyDown('W'))
		S->_position.y -= 10;
	if (DXUTIsKeyDown('S'))
		S->_position.y += 10;
	if (DXUTIsKeyDown('A'))
		S->_position.x -= 10;
	if (DXUTIsKeyDown('D'))
		S->_position.x += 10;

	C->Update();
	C->SetTransform();

}

void MainScene::OnExit()
{
}
