#include"stdafx.h"
#include"Eel.h"
#include"EnemyBullet.h"

Eel::Eel()
{
	Name = "eel";
	printf("EEL 持失\n");
}

Eel::~Eel()
{
}

bool Eel::Initialize()
{
	r = (rand() % 2) + 1;

	printf("RRR : %d \n", r);

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
	m_collision = new Collision(eel->Center, 30, this);
	AddChild(eel);
		
	return false;
}

void Eel::Update(float deltaTime)
{
	Object::Update(deltaTime);

	if (lifeCount < 0)
		visible = 0;

	eel->Position.x -= 3;

	if (GameTime::TotalFrame % 180 == 0)
		Attack();

	m_collision->SetPostion(eel ->Position.x, eel->Position.y);
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
		bullet->Position.x += (eel->Position.x) + (eel->Texture->Size.x / 2);
		bullet->Position.y += (eel->Position.y) + (eel->Texture->Size.y / 2);
		printf("Eel bullet 持失\n , Bullet x : %f Y : %f \n", bullet->Position.x, bullet->Position.y);
		BulletMgr::GetInstance()->RegisterBullet(bullet);
		BulletMgr::GetInstance()->Initialize();

	}
	break;

	case 2:
	{
		auto bullet = new EnemyBullet(L"Resources/Mob/blueeelbullet.png");
		bullet->Position.x += (eel->Position.x) + (eel->Texture->Size.x / 2);
		bullet->Position.y += (eel->Position.y) + (eel->Texture->Size.y / 2) + 20;
		printf("Eel bullet 持失\n , Bullet x : %f Y : %f \n", bullet->Position.x, bullet->Position.y);
		BulletMgr::GetInstance()->RegisterBullet(bullet);
		BulletMgr::GetInstance()->Initialize();

	}
	break;

	default:
		printf("eelbullet Default\n");
		break;
	}
	
}
