#include "stdafx.h"
#include "TripleBullet.h"
#include"Bullet.h"

TripleBullet::TripleBullet()
{
	Name = "triplebullet";
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

	printf("Triple Bullet »ý¼º\n");
	m_collision = new Collision(bullet->Center, 30, this);

	AddChild(bullet);

	return false;
}

void TripleBullet::Update(float deltaTime)
{
	Object::Update(deltaTime);

	Position.x += 10 * cos(radius);
	Position.y += 10 * sin(radius);

}

void TripleBullet::Render()
{
	Object::Render();
}

void TripleBullet::IsCollisionWith(Collision * collision)
{
	if (collision)
		bullet->visible = false;
}
