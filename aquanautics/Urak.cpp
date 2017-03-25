#include "stdafx.h"
#include "Urak.h"

Urak::Urak() : speed(3) , lifeCount(1)
{
	Name = "urak";
	id = 123;
}


Urak::~Urak()
{
}

bool Urak::Initialize()
{
	urak = new Sprite();
	urak->Initialize(L"Resources/Mob/urak.png");

	m_collision = new Collision(urak->Center, 30, this);

	AddChild(urak);

	return true;
}

void Urak::Update(float deltaTime)
{
	Object::Update(deltaTime);
	m_collision->SetPostion(Position.x, Position.y);

	/*printf("Urak Collision X : %f \n", m_collision->Position.x);
	printf("Urak Collision Y : %f \n", m_collision->Position.y);

	printf("Urak X : %f \n", Position.x);
	printf("Urak Y : %f \n", Position.y);*/
	//Position.x -= speed;

	if (lifeCount <= 0)
	{
		urak->visible = false;

		auto i = new Item(Position.x , Position.y);
		i->Initialize();
	}
	lifeCount = 1;
}

void Urak::Render()
{
	Object::Render();
}

void Urak::IsCollisionWith(Collision * collision)
{
	if (collision->Parent->Name == "torpedo")
	{
		lifeCount -= 1;
	}
}

