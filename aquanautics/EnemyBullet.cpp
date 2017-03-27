#include "stdafx.h"
#include "EnemyBullet.h"


EnemyBullet::EnemyBullet()
{
}

EnemyBullet::EnemyBullet(std::wstring text)
{
	Name = "enemybullet";
	bullet = new Sprite();
	this->tex = text;
}


EnemyBullet::~EnemyBullet()
{

}

bool EnemyBullet::Initialize()
{
	bullet->Initialize(tex);
	AddChild(bullet);

	return false;
}

void EnemyBullet::Update(float deltaTime)
{
	Object::Update(deltaTime);

	Position.x -= 7;
}

void EnemyBullet::Render()
{
	Object::Render();
}

void EnemyBullet::IsCollisionWith(Collision * other)
{
	if (other->Parent->Name == "enemybullet")
		return;

	if (other)
		visible = false;

}
