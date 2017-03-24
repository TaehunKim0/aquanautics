#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet() : LifeTime(0) , deathTime(300)
{
	Name = "bullet";
}

Bullet::~Bullet()
{
}

bool Bullet::Initialize()
{
	bullet = new Sprite();
	bullet->Initialize(L"Resources/Player/p_torpedo.png");
	AddChild(bullet);

	printf("Bullet »ý¼º\n");
	m_collision = new Collision(bullet->Center, 30, this);

	return false;
}

void Bullet::Update(float deltaTime)
{
	LifeTime++;
	Position.x += 10;

	m_collision->SetPostion(Position.x, Position.y);

	if (LifeTime == deathTime)
		this->SetVisible(false);

	Object::Update(deltaTime);

}

void Bullet::Render()
{
	Object::Render();
}

void Bullet::IsCollisionWith(Collision * collision)
{
	if (collision->Parent->Name == "urak")
		this->visible = false;
}
