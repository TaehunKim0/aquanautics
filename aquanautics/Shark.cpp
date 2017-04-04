#include "stdafx.h"
#include "Shark.h"


Shark::Shark() : lifeCount(5) , IsAppear(0)
{
	Name = "shark";
}

Shark::~Shark()
{
}

bool Shark::Initialize()
{
	shark = new Sprite();
	shark->Initialize(L"Resources/Mob/shark.png");

	m_collision = new Collision(shark->Center, 100, this);

	AddChild(m_collision);
	AddChild(shark);

	sharkDirection = SharkDirection::Up;

	return false;
	r = 0;

	srand(time(NULL));

}

void Shark::Render()
{
	Object::Render();
}

void Shark::Update(float deltaTime)
{
	Object::Update(deltaTime);

	m_collision->SetPostion(Position.x, Position.y);

	if (lifeCount < 0)
	{
		visible = false;
		EnemySpawner::GetInstance()->Remove(this);
		CollisionMgr::GetInstance()->Remove(m_collision);
	}

	if (!IsAppear)
		if ((Position.x > 700))
			Position.x -= 1;

		else
			IsAppear = 1;

	if (IsAppear)
		Move();

	r = 0;
	r = (rand() % 360) + 1;
	a = 0;
	a = (rand() % 2) + 1;

}

void Shark::IsCollisionWith(Collision * other)
{
	if (other->Parent->Name == "torpedo")
	{
		lifeCount--;
	}
}

void Shark::Move()
{
	printf("Attack : %d\n", r);
	printf("UPDOWN : %d\n", a);

	if (Position.y > WINDOW_HEIGHT - (shark->Center.y + shark->Center.y))
		sharkDirection = SharkDirection::Up;

	if (Position.y < 0)
		sharkDirection = SharkDirection::Down;

	switch (sharkDirection)
	{
	case SharkDirection::Down:
		Position.y += 3;
		break;

	case SharkDirection::Up:
		Position.y -= 3;
		break;

	/*case SharkDirection::Left:
		Position.x -= 10;
		break;

	case SharkDirection::Right:
		Position.x += 5;
		break;*/

	case SharkDirection::Attack:
		Position.x -= 10;
		break;

	case SharkDirection::NAttack:
		Position.x += 5;
		break;

	default:
		break;
	}

	if (GameTime::TotalFrame % r == 0 )
		if(sharkDirection == SharkDirection::Up | sharkDirection == SharkDirection::Down)
			sharkDirection = SharkDirection::Attack;

	if(Position.x < 0)
		sharkDirection = SharkDirection::NAttack;


	if (sharkDirection == SharkDirection::NAttack && Position.x > 701)
	{


		if(a == 1)
			sharkDirection = SharkDirection::Up;

		else
			sharkDirection = SharkDirection::Down;
	}		
}
