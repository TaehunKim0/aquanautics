#include "stdafx.h"
#include "TripleBullet.h"
#include"Bullet.h"

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
	bullet = new Sprite();
	bullet->Initialize(L"Resources/Player/p_torpedo.png");
	AddChild(bullet);

	m_collision = new Collision(bullet->Center, 30, this);

	AddChild(bullet);

	return false;
}

void TripleBullet::Update(float deltaTime)
{
	Object::Update(deltaTime);

	Position.x += 10 * cos(radius);
	Position.y += 10 * sin(radius);

	if (Position.x > 1300)
		visible = 0;

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
