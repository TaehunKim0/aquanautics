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

	m_collision = new Collision(bullet->Center, 10, this);

	return false;
}

void EnemyBullet::Update(float deltaTime)
{
	Object::Update(deltaTime);

	bullet->Position.x -= 7;

	printf("m_Enem ybullet Position %f, %f \n", bullet->Position.x, bullet->Position.y);

	m_collision->SetPostion(bullet->Position.x, bullet->Position.y);
}

void EnemyBullet::Render()
{
	Object::Render();
}

void EnemyBullet::IsCollisionWith(Collision * other)
{
	if (other->Parent->Name == "enemybullet")
		return;

	if (!(other->Parent->Name == "eel"))
		visible = false;

}
