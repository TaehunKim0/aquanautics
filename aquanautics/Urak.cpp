#include "stdafx.h"
#include "Urak.h"

Urak::Urak() : speed(3) , lifeCount(3), Cancollsion(0)
{
	
	id = 123;
}


Urak::~Urak()
{
}

bool Urak::Initialize()
{
	Name = "urak";

	
	int r = 0;
	srand(time(NULL));
	r = (rand() % 2 )+1;

	switch (r)
	{
	case 1:
	{
		urak = new Sprite();
		urak->Initialize(L"Resources/Mob/urak.png");
	}
		break;

	case 2:
	{
		urak = new Sprite();
		urak->Initialize(L"Resources/Mob/redurak.png");
	}
		break;

	default:
		printf("Urak Default\n");
		break;
	}

	m_collision = new Collision(urak->Center, 60, this);

	AddChild(urak);

	//urak = new Sprite();
	//urak->Initialize(L"Resources/Mob/urak.png");

	//m_collision = new Collision(urak->Center, 70, this);
	//

	//AddChild(urak);

	return true;

}

void Urak::Update(float deltaTime)
{
	Object::Update(deltaTime);

	m_collision->SetPostion(Position.x, Position.y);

	printf("urak collision X :%f Y :%f\n", m_collision->Position.x, m_collision->Position.y);
	if (lifeCount == 0)
	{
		auto i = new Item(Position.x, Position.y);
		i->Initialize();

		visible = 0;
		lifeCount--;
	}

	//Position.x -= 3;

	if (Position.x < 0)
		visible = false;

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
			return;
		}
}