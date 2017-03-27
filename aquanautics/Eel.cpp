#include"stdafx.h"
#include"Eel.h"
#include"EnemyBullet.h"

Eel::Eel()
{
	r = 0;
	Name = "eel";
	srand(time(NULL));
	r = (rand() % 2) + 1;
}

Eel::~Eel()
{
}

bool Eel::Initialize()
{
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
		eel->Initialize(L"Resources/Mob/blueeel.png");
	}
	break;

	default:
		printf("eel Default\n");
		break;
	}

	return false;
}

void Eel::Update(float deltaTime)
{
	Object::Update(deltaTime);

	if (lifeCount < 0)
		visible = 0;
}

void Eel::Render()
{
	Object::Render();
}

void Eel::IsCollisionWith(Collision * other)
{
	if (other->Parent->Name == "torpedo")
		lifeCount--;
}

void Eel::Attack()
{
	switch (r)
	{
	case 1:
	{
		auto bullet = new EnemyBullet(L"Resources/Mob/eelbullet.png");
		bullet->Position.x += (this->Position.x) + (eel->Texture->Size.x / 2);
		bullet->Position.y += (this->Position.y) + (eel->Texture->Size.y / 2)+20;

		BulletMgr::GetInstance()->RegisterBullet(bullet);
		BulletMgr::GetInstance()->Initialize();
	}
	break;

	case 2:
	{
		auto bullet = new EnemyBullet(L"Resources/Mob/blueeelbullet.png");
		bullet->Position.x += (this->Position.x) + (eel->Texture->Size.x / 2);
		bullet->Position.y += (this->Position.y) + (eel->Texture->Size.y / 2) + 20;

		BulletMgr::GetInstance()->RegisterBullet(bullet);
		BulletMgr::GetInstance()->Initialize();
	}
	break;

	default:
		printf("eel Default\n");
		break;
	}
	
}
