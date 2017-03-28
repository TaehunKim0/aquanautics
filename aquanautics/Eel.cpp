#include "stdafx.h"
#include "Eel.h"
#include"EnemyBullet.h"



Eel::Eel() : lifeCount(7)
{
}


Eel::~Eel()
{
}

bool Eel::Initialize()
{
	int r = 0;
	srand(time(NULL));
	r = (rand() % 2) + 1;

	switch (r)
	{
	case 1:
	{
		eel = new Sprite();
		eel->Initialize(L"Resources/Mob/eel.png");
	}
	break;

	case 2:
	{
		eel = new Sprite();
		eel->Initialize(L"Resources/Mob/redeel.png");
	}
	break;

	default:
		printf("eel Default \n");
		break;
	}
	
	m_collision = new Collision(eel->Center, 30, this);
	AddChild(eel);

	return false;
}

void Eel::Update(float deltaTime)
{
	Object::Update(deltaTime);

	if (lifeCount <= 0)
	{
		visible = false;
		if (!visible)
			return;

		auto i = new Item(Position.x, Position.y);
		i->Initialize();

	}

	Position.x -= 3;

	if (Position.x < 0)
		visible = false;

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

	bullet->Position.x += (this->Position.x) + (eel->Texture->Size.x / 2);
	bullet->Position.y += (this->Position.y) + (eel->Texture->Size.y / 2 - 20);

	BulletMgr::GetInstance()->RegisterBullet(bullet);
	BulletMgr::GetInstance()->Initialize();
}
