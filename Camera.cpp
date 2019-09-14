#include "DXUT.h"
#include "Camera.h"

Camera::Camera()
{
	D3DXMatrixOrthoLH(&orthographicMatrix, 1280, -720, 0.0f, 1.0f);
	D3DXMatrixIdentity(&identityMatrix);
}

void Camera::Update()
{
	if (!following)
		return;

	cameraX = this->following->_position.x;
	cameraY = this->following->_position.y;

	this->viewMatrix = D3DXMATRIX(
		1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		-cameraX, -cameraY, 0, 1 );
}

void Camera::Follow(Sprite* following)
{
	this->following = following;
}

void Camera::Unfollow()
{
	this->following = nullptr;
}

bool Camera::IsFollowing() const
{
	return this->following != nullptr;
}

void Camera::SetTransform() const
{
	DXUTGetD3D9Device()->SetTransform(D3DTS_PROJECTION, &orthographicMatrix);
	DXUTGetD3D9Device()->SetTransform(D3DTS_WORLD, &identityMatrix);
	DXUTGetD3D9Device()->SetTransform(D3DTS_VIEW, &viewMatrix);
}
