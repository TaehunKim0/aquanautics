#include"stdafx.h"
#include"Shark.h"

Shark::Shark()
{
}

Shark::~Shark()
{
}

bool Shark::Initialize()
{
	shark = new Sprite();
	shark->Initialize(L"Resources/Move/shark.png");

	AddChild(shark);

	return false;
}

void Shark::Render()
{
	Object::Render();
}

void Shark::Update(float deltaTime)
{
	Object::Update(deltaTime);
}

void Shark::IsCollisionWith(Collision * other)
{
}

void Shark::Move()
{
}
