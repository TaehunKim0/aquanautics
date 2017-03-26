#include "stdafx.h"
#include "Collision.h"


Collision::Collision()
{
	
}

Collision::Collision(D3DXVECTOR3 center, float r , Object* parent)
{
	Center = center;
	radius = r;
	Parent = parent;

	CollisionMgr::GetInstance()->RegisterCollision(this);
	printf("Collision Register \n");
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
	Object::Update(deltaTime);
}

void Collision::Render()
{
}

void Collision::IsCollide(Collision * other)
{
	Parent->IsCollisionWith(other);
}


