#include "stdafx.h"
#include "Torpedo.h"
Torpedo::Torpedo()
{
	Name = "torpedo";
}


Torpedo::~Torpedo()
{
}
bool Torpedo::Initialize()
{
	bullet = new Sprite();
	bullet->Initialize(L"Resources/Player/p_torpedo.png");
	AddChild(bullet);

	printf("Bullet »ý¼º\n");
	m_collision = new Collision(bullet->Center, 30, this);

	return false;
}

void Torpedo::Update(float deltaTime)
{
	LifeTime++;
	Position.x += 10;

	m_collision->SetPostion(Position.x, Position.y);

	if (LifeTime == deathTime)
		this->SetVisible(false);

	Object::Update(deltaTime);
}

void Torpedo::Render()
{
	Object::Render();
}

void Torpedo::IsCollisionWith(Collision * other)
{
	if (other)
		bullet->visible = false;
}
