#pragma once
#include "Sprite.h"
#include "Scene.h"
#include "Camera.h"
class MainScene :
	public Scene
{
public:
	void Init() override;
	void Update() override;
	void OnExit() override;

	Camera* C;
	Sprite* S;
	Sprite* S1;

};

