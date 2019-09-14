#pragma once
#include "Sprite.h"
class Camera
{
public:
	//Constructors and Destructor
	Camera();

	//Game Functions
	void Update();
	void Follow(Sprite* following);
	void Unfollow();
	bool IsFollowing() const;
	void SetTransform() const;

private:
	D3DXMATRIX orthographicMatrix;
	D3DXMATRIX identityMatrix;
	D3DXMATRIX viewMatrix;

	Sprite* following;

	int cameraX;
	int cameraY;
};

