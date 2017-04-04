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

	printf("생성");
}

EnemyBullet::~EnemyBullet()
{

}

bool EnemyBullet::Initialize()
{
	bullet->Initialize(tex);
	AddChild(bullet);

	m_collision = new Collision(bullet->Center, 10, this);

	AddChild(m_collision);
	return false;

}

void EnemyBullet::Update(float deltaTime)
{
	Object::Update(deltaTime);
	printf("부모 : %s", Parent->Name.c_str());
	Position.x -= 10;

	if (Position.x < -250)
		EnemySpawner::GetInstance()->Remove(this);
	
	m_collision->SetPostion(Position.x, Position.y);

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
	{
		visible = false;
		return;
	}

	if (other)
		EnemySpawner::GetInstance()->Remove(this);
}
