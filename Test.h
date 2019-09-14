#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Camera.h"
class Test : public Scene
{
public:
	void Init() override;
	void Update() override;
	void OnExit() override;

	Sprite* S1;
	Sprite* S2;
};

