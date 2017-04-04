#include "stdafx.h"
#include "TripleBullet.h"
#include"Bullet.h"
#include"Torpedo.h"

TripleBullet::TripleBullet()
{
	Name = "triplebullet";

	printf("tripleTorpedo »ý¼º\n");
}

TripleBullet::~TripleBullet()
{
}

TripleBullet::TripleBullet(float radius) : radius(0)
{
	this->radius = radius * 3.14 / 180;
}

bool TripleBullet::Initialize()
{
	auto bullet = new Torpedo();
	bullet->Initialize();

	AddChild(bullet);

	m_collision = new Collision(bullet->bullet->Center, 30, this);
	AddChild(m_collision);
	return false;
}

void TripleBullet::Update(float deltaTime)
{
	Object::Update(deltaTime);

	Position.x += cos(radius);
	Position.y += sin(radius);

	if (Position.x > 1300)
	{ 
		BulletMgr::GetInstance()->Remove(this);
		CollisionMgr::GetInstance()->Remove(m_collision);
	}

}

void TripleBullet::Render()
{
	Object::Render();
}

void TripleBullet::IsCollisionWith(Collision * other)
{
	if ((other->Parent->Name =="player"))
	{
	}

	if (other->Parent->Name == "torpedo")
	{
		printf("triple bullet - torpedo Collision\n");
		return;
	}

	if (other->Parent->Name == "triplebullet")
	{
		printf("triple bullet - triple torpedo Collision\n");
		return;
	}

	if (other->Parent->Name == "urak")
	{
		printf("triple bullet - urak Collision\n");
		visible = false;
	}
}
