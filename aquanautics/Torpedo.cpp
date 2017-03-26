#include "stdafx.h"
#include "Torpedo.h"
Torpedo::Torpedo()
{
	Name = "torpedo";
	bullet = nullptr;

	IsTexted = 1;
}

Torpedo::Torpedo(std::wstring texture)
{
	Name = "torpedo";

	bullet = new Sprite();
	tt = texture;

	IsTexted = 0;
}

Torpedo::~Torpedo()
{
}

bool Torpedo::Initialize()
{

	if (bullet == nullptr)
	{
		bullet = new Sprite();
		bullet->Initialize(L"Resources/Player/p_torpedo.png");

		m_collision = new Collision(bullet->Center, 30, this);
		AddChild(bullet);

		return true;
	}

	if (IsTexted)
	{
		bullet = new Sprite();
		bullet->Initialize(L"Resources/Player/p_torpedo.png");

		m_collision = new Collision(bullet->Center, 30, this);
		AddChild(bullet);

		return true;
	}

	bullet->Initialize(tt);

	m_collision = new Collision(bullet->Center, 30, this);
	AddChild(bullet);
	return false;
}

void Torpedo::Update(float deltaTime)
{
	LifeTime++;
	Position.x += 10;

	m_collision->SetPostion(Position.x, Position.y);

	if (LifeTime == deathTime)
		this->SetVisible(false);

	Object::Update(deltaTime);
}

void Torpedo::Render()
{
	Object::Render();
}

void Torpedo::IsCollisionWith(Collision * other)
{
	if (!(other->Parent->Name == "player"))
	{
		visible = false;

		printf("Bullet - Player Collsion\n");
	}

	if ((other->Parent->id == 1))
	{
		visible = true;

		printf("Bullet - Item Collsion\n");
	}

	if ((other->Parent->Name == "torpedo"))
	{
		visible = true;
		printf("Bullet - Bullet Collision\n");
	}

	if((other->Parent->Name == "triplebullet"))
	{
		visible = true;
		printf("Bullet - triplebullet Collision\n");
	}

	if ((other->Parent->Name == "addonplayer"))
	{
		printf("asd");
	}
		
}

void Torpedo::SetTorpedoTexture(std::wstring texture)
{
	if (bullet->Texture)
	{
		bullet->Texture = nullptr;

		bullet->Initialize(texture);
	}

}
