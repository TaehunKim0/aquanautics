#include "stdafx.h"
#include "Bullet.h"


Bullet::Bullet() : LifeTime(0) , deathTime(300)
{

}


Bullet::~Bullet()
{
}

bool Bullet::Initialize()
{
	bullet = new Sprite();
	bullet->Initialize(L"Resources/Player/p_torpedo.png");
	AddChild(bullet);

	printf("Bullet »ý¼º\n");

	return false;
}

void Bullet::Update(float deltaTime)
{
	LifeTime++;
	Position.x += 3;

	if (LifeTime == deathTime)
		this->SetVisible(false);

	Object::Update(deltaTime);

}

void Bullet::Render()
{
	Object::Render();
}
