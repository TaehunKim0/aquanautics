#include"stdafx.h"
#include"EnemyBullet.h"

EnemyBullet::EnemyBullet()
{
}

EnemyBullet::EnemyBullet(std::wstring text)
{
	tex = text;

	bullet = new Sprite();

}

EnemyBullet::~EnemyBullet()
{
}

bool EnemyBullet::Initialize()
{
	bullet->Initialize(tex);
	AddChild(bullet);

	m_collision = new Collision(bullet->Center, 30, this);

	return false;
}

void EnemyBullet::Update(float deltaTime)
{
	Object::Update(deltaTime);

	Position.x -= 3;
}

void EnemyBullet::Render()
{
	Object::Render();
}

void EnemyBullet::IsCollisionWith(Collision * other)
{
	if (!(other->Parent->Name == "enemybullet"))
		visible = false;

}
