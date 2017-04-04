#include "stdafx.h"
#include "Urak.h"

Urak::Urak() : speed(3) , lifeCount(1), Cancollsion(0)
{
	
	id = 123;
}


Urak::~Urak()
{
}

bool Urak::Initialize()
{
	Name = "urak";

	urak = new Sprite();
	urak->Initialize(L"Resources/Mob/urak.png");

	m_collision = new Collision(urak->Center, 20, this);

	AddChild(urak);
	AddChild(m_collision);

	return true;

}

void Urak::Update(float deltaTime)
{
	Object::Update(deltaTime);

	m_collision->SetPostion(Position.x  + urak->Center.x, Position.y + urak->Center.y);

	if (visible == true)
	{
		if (lifeCount < 0)
		{
			auto i = new Item(Position.x, Position.y);
			i->Initialize();

			EnemySpawner::GetInstance()->Remove(this);
			CollisionMgr::GetInstance()->Remove(m_collision);
		}
	}

	Position.x -= 10;

	if (Position.x < -250)
		EnemySpawner::GetInstance()->Remove(this);

}

void Urak::Render()
{
	Object::Render();
}

void Urak::IsCollisionWith(Collision * other)
{
	//if(Cancollsion)
	if (other->Parent->Name == "torpedo")
	{
		lifeCount -= 1;
		
		printf("Torpedo Collision - urak\n");
		//Cancollsion = 0;
		
	}

	if (other->Parent->Name == "triplebullet")
	{
		lifeCount -= 1;

		printf("triple Collision - urak\n");
		//Cancollsion = 0;
	}
}