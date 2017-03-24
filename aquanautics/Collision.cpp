#include "stdafx.h"
#include "Collision.h"


Collision::Collision()
{
}

Collision::Collision(D3DXVECTOR3 center, float r)
{
	Center = center;
	radius = r;

	CollisionMgr::GetInstance()->RegisterCollision(this);
}

Collision::~Collision()
{
}

bool Collision::Initialize()
{
	return false;
}

void Collision::Update(float deltaTime)
{
}

void Collision::Render()
{
}

bool Collision::IsCollideWith(Collision * other)
{
	return false;
}
