#include "stdafx.h"
#include "Eel.h"
#include"EnemyBullet.h"



Eel::Eel() : lifeCount(7)
{
	Name = "eel";
}


Eel::~Eel()
{
}

bool Eel::Initialize()
{
	eel = new Sprite();
	eel->Initialize(L"Resources/Mob/eel.png");

	m_collision = new Collision(eel->Center, 30, this);
	AddChild(m_collision);

	AddChild(eel);

	return false;
}

void Eel::Update(float deltaTime)
{
	Object::Update(deltaTime);

	if (lifeCount <= 0)
	{
		auto i = new Item(Position.x, Position.y);
		i->Initialize();

		EnemySpawner::GetInstance()->Remove(this);
		CollisionMgr::GetInstance()->Remove(m_collision);
	}

	Position.x -= 3;

	if (Position.x < 0)
	{
		EnemySpawner::GetInstance()->Remove(this);
		CollisionMgr::GetInstance()->Remove(m_collision);
	}

	if (GameTime::TotalFrame % 120 == 0)
		Attack();

}

void Eel::Render()
{
	Object::Render();
}

void Eel::IsCollisionWith(Collision * other)
{
	if (other->Parent->Name == "torpedo")
	{
		lifeCount -= 1;
		return;
	}
}

void Eel::Attack()
{
	auto bullet = new EnemyBullet(L"Resources/Mob/eelbullet.png");
	bullet->Initialize();

	bullet->Position.x += (this->Position.x);
	bullet->Position.y += (this->Position.y);

	AddChild(bullet);

}
